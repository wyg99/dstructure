/*
 * @Author: your name
 * @Date: 2021-08-29 23:45:35
 * @LastEditTime: 2021-08-30 17:27:12
 * @LastEditors: Please set LastEditors
 * @Description: huffman压缩文件与解压缩文件
 * @FilePath: \Dstructure\part4\HuffTreeCodeZip.cpp
 */
#include"stdio.h"

#include<iostream>
#include<memory.h>
using namespace std;
#define MAX_CH 256
// 取出index位，若取出的index位为0，则GET_BYTE 值为假，否则为真
// #define CLR_BYTE(vbyte,index) ((vbyte) &= (~(1 << ((index) ^ 7))))
#define GET_BYTE(vbyte, index) (((vbyte) & (1 << ((index) ^ 7))) != 0)
// 把index位设置为‘1’
#define SET_BYTE(vbyte, index) ((vbyte) |= (1 << ((index) ^ 7)))
// 把index位设置为‘0’ 
#define CLR_BYTE(vbyte, index) ((vbyte) &= (~(1 << ((index) ^ 7))))
typedef struct hfmTreeNode
{
    /* data */
    char ch;   // 数据域
    int weight;
    int parent,lchild,rchild; // 双亲结点;左孩子结点;右孩子结点;
    int codeLen;  // 用于保存最后编码的长度;
    char* code; // 用于最后存储编码是多少
}hfmTreeNode;

// 定义Huffman编码的表
typedef struct hfmCodeTable
{
    /* data */
    char* code;
    int len;
}hfmCodeTable;

// 定义权重表
typedef struct weightTable
{
    /* data */
    char ch;   // 字符
    int weight;// 出现的次数
}weightTable;

// 定义栈
typedef struct stack{
    char size[50];  // 栈空间大小
    int top; // 栈顶指针
}stack;

// 初始化栈空间
void initStack(stack& stack)
{
    stack.top = 0;
}

// 判断栈是否为空
bool isStackEmpty(stack & stack)
{
    if(stack.top == 0)
        return true;
    return false;
}

// 元素入栈
void pushStack(stack &stack,char elem)
{
    stack.size[stack.top++] = elem;
}

// 元素出栈
void popStack(stack& stack,char &elem)
{
    if(!isStackEmpty(stack))
    {
        elem = stack.size[--stack.top];
    }
}

class HuffTreeCodeZip
{
private:
    weightTable* wTable; // 获取权重表
    hfmTreeNode* huffmanTree; // huffman树
    hfmCodeTable* huffmanCodeTable; // huffman编码表
    int numberCh;// 不同字符的个数

public:
    HuffTreeCodeZip(/* args */);
    ~HuffTreeCodeZip();

    
    
    // 输入一个.TXT文件，统计文件中各个字符的ch以及个数（权重）
    void toCreateWeightTable(const char* filePath);
    // 打印权重表：
    void outPutWeightTable();
    // 构造Huffman树
    void CreateHuffmanTree();
    // 打印huffman树
    void outPutHuffmanTree();
    
    // 确定编码，构建一个Huffman码表
    void CreateHUffmanCodeTable();
    // 遍历文件，按照编码重写文件
    void WriteFileToZip(const char* inFile,const char* outFile);
    // huffman解压缩
    void UnZipFILE(const char* inFile,const char* outFile);

    int FindMinNode(int& index);
    
};
void HuffTreeCodeZip::WriteFileToZip(const char* inFile,const char* outFile)
{
    FILE* fp1 = NULL,*fp2 = NULL;
    if((fp1 = fopen(inFile,"r")) == NULL || (fp2 = fopen(outFile,"w")) == NULL)
    {
        cout<<"The file open false，please open again~\n"<<endl;
        exit(0);
    }
    // 将huffman编码的表写入到其中
    
    fwrite(&numberCh,sizeof(int),1,fp2);//字符类型数
    int invalidbitcount=0;
    fwrite(&invalidbitcount,sizeof(int),1,fp2);//无效编码位数
    fwrite(wTable,sizeof(hfmCodeTable),256,fp2);
    int bitindex=0;
    char byte = 0;
    while (feof(fp1))
    {
        /* code */
        char ch = fgetc(fp1);
        if (ch <0 || ch>255)
        {
            continue;
        }
        int leng = huffmanCodeTable[ch].len;
        for(int i = 0;i < huffmanCodeTable[ch].len;i++)
        {
            //fprintf(fp2,"%c",huffmanCodeTable[ch].code[i]);

            if(huffmanCodeTable[ch].code[i]== '0')
            {
                CLR_BYTE(byte,bitindex);
            }
            else
            {
                SET_BYTE(byte,bitindex);
            }
            if(bitindex==7)
            {
                //凑满了一个字节，可以写出了
                fwrite(&byte,sizeof(char),1,fp2);
                bitindex=0;
            }
            else{
                bitindex++;
            }   
        }
    }


    
    //还有剩余的字符需要写入
    if(bitindex!=0)
    {
        fwrite(&byte,sizeof(char),1,fp2);
    }
    //无效的位数
    invalidbitcount=8-(bitindex+1);
    fseek(fp2,sizeof(int),0);
    fwrite(&invalidbitcount,sizeof(char),1,fp2);
    fclose(fp1);
    fclose(fp2);
}
void HuffTreeCodeZip::outPutHuffmanTree()
{
    for(int index = 0;index < 2 * numberCh-1;index++)
    {
        cout<<index<<"  "<<huffmanTree[index].weight<<"  "<<huffmanTree[index].parent<<"  "<<huffmanTree[index].lchild<<"  "<<huffmanTree[index].rchild<<"  "<<endl;
    }
}
int HuffTreeCodeZip::FindMinNode(int& index)
{
    int min_value = 9999;
    int _tar;
    
    for(int i = 0;i < index;i++)
    {
        
        if(huffmanTree[i].weight < min_value && huffmanTree[i].parent ==0)
        {
            min_value = huffmanTree[i].weight;
            _tar = i;
        }
    }
    huffmanTree[_tar].parent = -1;
    return _tar;
}


HuffTreeCodeZip::HuffTreeCodeZip(/* args */)
{
    numberCh = 0;    // 元素个数设置为0
    wTable = new weightTable[MAX_CH];
    memset(wTable,0,MAX_CH*sizeof(wTable));   // 将空间全部置空为0
}

HuffTreeCodeZip::~HuffTreeCodeZip()
{
    delete []wTable;
    delete []huffmanTree;
    delete []huffmanCodeTable;
    
}

void HuffTreeCodeZip::toCreateWeightTable(const char* filePath)
{
    // 打开文件
    FILE* fp = NULL;
    if ( (fp = fopen(filePath,"r")) == NULL)
    {
        cout<<"文件打开失败"<<endl;
        return;
    }
    
    while (!feof(fp))
    {
        char ch = fgetc(fp);       
        if(wTable[ch].weight == 0)
        {            
            wTable[ch].ch = ch;
            numberCh++;
        }   
        wTable[ch].weight++;    
    }
    fclose(fp);
}
void HuffTreeCodeZip::outPutWeightTable()
{
    for(int index = 0;index < MAX_CH;index++)
    {
        if(wTable[index].weight!= 0 )        
            cout<<wTable[index].ch<<wTable[index].weight<<endl;
    }
}

void HuffTreeCodeZip::CreateHuffmanTree()
{
    // 循环遍历已经有的结点，
    huffmanTree = new hfmTreeNode[2 * numberCh - 1];
    memset(huffmanTree,0,(2*numberCh - 1)* sizeof(hfmTreeNode));
    int index = 0;
    for(int index1 = 0;index1 < MAX_CH; index1++)
    {
        if (wTable[index1].weight !=0 )
        {
            huffmanTree[index].ch = wTable[index1].ch;
            huffmanTree[index].weight = wTable[index1].weight;
            huffmanTree[index].parent = huffmanTree[index].lchild = huffmanTree[index].rchild = 0;  
            huffmanTree[index].codeLen = 0;
            index++;          
        }
    }
    for (int index2 = numberCh; index2 < 2*numberCh-1;index2++)
    {
        int min1 = HuffTreeCodeZip::FindMinNode(index2);
        int min2 = HuffTreeCodeZip::FindMinNode(index2);
        huffmanTree[min1].parent = huffmanTree[min2].parent = index2;
        huffmanTree[index2].lchild = min1;
        huffmanTree[index2].rchild = min2;
        huffmanTree[index2].weight = huffmanTree[min1].weight + huffmanTree[min2].weight;
        huffmanTree[index2].parent = 0;
    }
}

void HuffTreeCodeZip::CreateHUffmanCodeTable()
{
    huffmanCodeTable = new hfmCodeTable[MAX_CH];
    memset(huffmanCodeTable,0,MAX_CH* sizeof(hfmCodeTable));
    for(int index1 = 0;index1<numberCh;index1++)
    {
        int index2 = index1;
        // 初始化一个栈空间
        stack stack;
        initStack(stack);
        // 对每一个结点进行循环遍历，直到找到根结点
        while (huffmanTree[index2].parent != 0)
        {
            /* code */
            if(huffmanTree[huffmanTree[index2].parent].lchild == index2)
            {
                pushStack(stack,'0');
            }
            if(huffmanTree[huffmanTree[index2].parent].rchild == index2)
            {
                pushStack(stack,'1');
            }
            index2 = huffmanTree[index2].parent;
            huffmanTree[index1].codeLen++;
        }
        huffmanTree[index1].code = new char[huffmanTree[index1].codeLen];
        huffmanCodeTable[huffmanTree[index1].ch].len  = huffmanTree[index1].codeLen;
        huffmanCodeTable[huffmanTree[index1].ch].code = new char[huffmanTree[index1].codeLen];
        int codeIndex = 0;
        char temp;
        while (!isStackEmpty(stack))
        {
            popStack(stack,temp);
            huffmanTree[index1].code[codeIndex] = temp;
            huffmanCodeTable[huffmanTree[index1].ch].code[codeIndex] = temp;
            codeIndex++;
        }
        
        
    }
    for(int i = 0; i<MAX_CH;i++)
    {
        if(huffmanCodeTable[i].len!=0)
        {
            printf("%c:",i);
            for(int j = 0; j < huffmanCodeTable[i].len;j++)
            {
                printf("%c",huffmanCodeTable[i].code[j]);
            }
            printf("\n");
        }
    }
}
int main()
{
    const char* filepath = "code.txt";
    const char* outFile = "huffmanzip.txt";
    HuffTreeCodeZip* zipApp = new HuffTreeCodeZip();
    zipApp->toCreateWeightTable(filepath);
    zipApp->outPutWeightTable();
    zipApp->CreateHuffmanTree();
    zipApp->outPutHuffmanTree();
    zipApp->CreateHUffmanCodeTable();
    zipApp->WriteFileToZip(filepath,outFile);
    //delete zipApp;
    return 0;
}









