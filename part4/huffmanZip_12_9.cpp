/*
 * @Author: your name
 * @Date: 2021-12-08 18:40:01
 * @LastEditTime: 2021-12-08 21:35:11
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \Dstructure\part4\huffmanZip_12_9.cpp
 */

#include<iostream>
using namespace std;

// handdman树结点定义
typedef struct HuffmanNode{
    char ch;//结点保存的字符
    int parent,lchild,rchild;//表示父结点以及左右孩子结点
    int weight;//表示权重
    int codelength;//表示编码的长度
    char* code;
}HuffmanNode;

// 编码表
typedef struct CodeTable{
    char ch;
    int length;
    char* code;
}CodeTable;
#define MAXCH 50
class Stack
{
private:
    /* data */
    char ch[MAXCH];
    int top;
public:
    Stack(/* args */);
    ~Stack();
    bool empty();
    void push(char ch);
    char pop();
    int size();
    int maxsize();
};
typedef struct WeightTable{
    char ch;  // 字符
    int weight; //权重
}WeightTable;


class AppZip
{
private:
    /* data */
    HuffmanNode* huffmanNode;
    CodeTable* codeTable;
    WeightTable* weightTable;
    int CHNUMBER; // 文件中字符的最大种类数
    int CharNumber;
public:
    AppZip(/* args */);
    ~AppZip();

    // 得到权重表
    bool CreateWeightTable(const char* FilePath);
    // 打印权重表
    bool PrintWeightTable();
    // 创建huffmantree
    bool CreateHuffmanTree();
    // 打印huffmantree
    bool PrintHuffmanTree();
    // 查找最小权重值结点的下标
    int FindMinWeightIndex(int index);
    // 创建编码表
    bool CreateCodeTable();

    // 打印编码表
    bool PrintCodeTable();
};
bool AppZip::PrintCodeTable()
{
    cout<<"*****编码"<<endl;
    char ch;
    int len;
    for(int i = 0;i <CharNumber;i++)
    {
        ch = codeTable[i].ch;
        len = codeTable[i].length;
        cout<<ch<<"\t";
        for(int j = 0;j < len;j++)
        {
            cout<<codeTable[i].code[j];
        }
        cout<<endl;
    }
    return true;
}
bool AppZip::CreateCodeTable()
{
    codeTable = new CodeTable[CharNumber];
    // 对每一个数据结点进行编码查询
    Stack stk;
    for(int i = 0;i < CharNumber;i++)
    {
        int index = i;
        while (huffmanNode[index].parent!=0)
        {
            /* code */
            int parent = huffmanNode[index].parent; 
            if(huffmanNode[parent].lchild == index)
            {
                stk.push('0');
            }
            if(huffmanNode[parent].rchild == index)
            {
                stk.push('1');
            }
            index = parent;
        }
        int parent = huffmanNode[index].parent;
        if(huffmanNode[parent].lchild == index){
            stk.push('0');
        }
        else if(huffmanNode[parent].rchild == index){
            stk.push('1');
        }
        int CodeIndex = 0;
        char ch;
        codeTable[i].ch = huffmanNode[i].ch;
        codeTable[i].length = stk.size();
        codeTable[i].code = new char[stk.size()];
        while(!stk.empty())
        {
            ch = stk.pop();
            codeTable[i].code[CodeIndex++] = ch;
        }
    }
    return true;
}
int AppZip::FindMinWeightIndex(int index)
{
    int min = INT_MAX;
    int AnswerIndex;
    for(int i = 0;i < index;i++)
    {
        if(huffmanNode[i].parent == 0 && huffmanNode[i].weight < min)
        {
            min = huffmanNode[i].weight;
            AnswerIndex = i;
        }
    }
    huffmanNode[AnswerIndex].parent = 1;
    return AnswerIndex;
}
bool AppZip::PrintHuffmanTree()
{
    //this->CharNumber
    cout<<"*********HuffmanTree*********"<<endl;
    for(int i = 0;i < 2*CharNumber - 1;i++)
    {
        cout<<huffmanNode[i].ch<<"\t"<<huffmanNode[i].weight<<"\t"<<huffmanNode[i].parent<<"\t"<<huffmanNode[i].lchild<<"\t"<<huffmanNode[i].rchild<<endl;
    }
    return true;
}
bool AppZip::PrintWeightTable()
{
    cout<<"****权重表***"<<endl;
    
    for(int i = 0;i < CHNUMBER;i++)
    {
        if(weightTable[i].weight!=0)
        {
            char ch = weightTable[i].ch;
            int weight = weightTable[i].weight;
            cout<<ch<<"\t"<<weight<<endl;
        }
    }
    cout<<"\n";
    return true;
}
bool AppZip::CreateHuffmanTree()
{
    if(CharNumber == 0){
        cout<<"文件为空";
        return false;
    }
    huffmanNode = new HuffmanNode[2*CharNumber-1];
    // 将huffman首先置空
    int index = 0;
    for(int i = 0;i<CHNUMBER;i++)
    {
        if(weightTable[i].weight!=0){
            huffmanNode[index].ch = weightTable[i].ch;
            huffmanNode[index].weight = weightTable[i].weight;
            huffmanNode[index].parent = huffmanNode[index].lchild = huffmanNode[index].rchild = 0;
            index++;
        }
    }
    for(int j = index;j < 2*CharNumber-1;j++){
        int min1 = AppZip::FindMinWeightIndex(j);
        int min2 = AppZip::FindMinWeightIndex(j);
        huffmanNode[min1].parent = huffmanNode[min2].parent = j;
        huffmanNode[j].parent = 0;
        huffmanNode[j].lchild = min1;
        huffmanNode[j].rchild = min2;
        huffmanNode[j].weight = huffmanNode[min1].weight + huffmanNode[min2].weight;
        
    }
    return true;
}
bool AppZip::CreateWeightTable(const char* FilePath)
{
    FILE* fp = nullptr;
    if((fp=fopen(FilePath,"r")) == nullptr){
        cout<<"打开文件失败\n";
        return false;
    }
    char ch;
    while (!feof(fp))
    {
        /* code */
        ch = fgetc(fp);
        weightTable[ch].ch = ch;
        if(weightTable[ch].weight == 0){
            CharNumber++;
        }
        weightTable[ch].weight++;
    }
    fclose(fp);
    return true;
}
AppZip::AppZip(/* args */)
{
    CHNUMBER = 256;
    weightTable = new WeightTable[CHNUMBER];
    for(int i = 0;i < CHNUMBER;i++)
    {
        weightTable[i].weight = 0;
    }
    CharNumber = 0;
}

AppZip::~AppZip()
{
    delete huffmanNode;
    for(int i = 0;i < CharNumber;i++)
    {
        delete codeTable[i].code;
    }
    delete codeTable;
    delete weightTable;
}

int Stack::size()
{
    return top+1;
}
int Stack::maxsize()
{
    return MAXCH;
}
bool Stack::empty(){
    if(top == -1)return true;
    return false;
}
void Stack::push(char character){
    ++top;
    ch[top] = character;
}
char Stack::pop()
{
    return ch[top--];
}
Stack::Stack(/* args */)
{
    top = -1;
}

Stack::~Stack()
{
}




int main()
{
    AppZip* app = new AppZip();
    const char* FilePath = "./code.txt";
    app->CreateWeightTable(FilePath);
    app->CreateHuffmanTree();
    app->PrintWeightTable();
    app->PrintHuffmanTree();
    app->CreateCodeTable();
    app->PrintCodeTable();
    return 0;
}
