/*
 * @Author: 魏玉国
 * @Date: 2021-05-15 17:43:02
 * @LastEditTime: 2021-07-04 20:15:47
 * @LastEditors: Please set LastEditors
 * @Description: 线性表-顺序链表
 * @FilePath: \CStructPrograme\Part1\include\LinearTable.h
 */
#include<stdio.h>
#include<stdlib.h>
#define NAMELENGTH 10
#define FIRSTROWLENGHT 50
// 定义学生成绩的结构体
typedef struct StudentInfor
{
    int id;
    char name[NAMELENGTH];
    float* score;
}SeqListNodeData;
enum BOOL{FALSE,TRUE};
typedef enum BOOL BOOL;
// 定义顺序表的结构体

typedef struct SeqListNode
{
    SeqListNodeData* dNode;   // 数据域
    int index;
    int nscore;// 学生成绩的门数
}SeqListNode;

/***********************************************************************/


// 创建顺序表的头结点
SeqListNode* SEQ_gToCreateSequentialList();
// 读取文件流
void SEQ_gToReadFileData(const char* FILEPATH, SeqListNode* ListHead);
// 顺序链表信息填充
void SEQ_gToGetInformation(FILE* fp, SeqListNode* ListHead);
// 打印
void SEQ_gToPrint(SeqListNode* ListHead);
// 释放空间
void SEQ_gToFreeSpace(SeqListNode* ListHead);
// 删除指定位置的元素 按照逻辑位置
void SEQ_gToDeleteNode(SeqListNode* ListHead,int Location);
// 在顺序表尾部插入
void SEQ_gToInsertAtLast(SeqListNode* ListHead,SeqListNodeData nod);
// 在顺序表头部插入
void SEQ_gToInsertAtHead(SeqListNode* ListHead,SeqListNodeData nod);
// 顺序链表在中间部分插入
void SEQ_gToInsertAtLocation(SeqListNode* ListHead,SeqListNodeData Node,int Location);
// 判断顺序链表是否为空
BOOL SEQ_gSeqListIsNull(SeqListNode* ListHead);
// 判断顺序表是否满了
BOOL SEQ_gSeqListIsFull(SeqListNode* ListHead);
// 将顺序表按照二进制的方式写入到文件中
void SEQ_gToWriteToFileByBinary(const char* FILEPATH,SeqListNode* ListHead);
// 将顺序表按照二进制的方式进行读取
void SEQ_gToReadFileByBinary(const char* FILEPATH,SeqListNode* ListHead);
// 顺序表的排序操作
void SEQ_gToSort(SeqListNode* ListHead);
// 顺序表打印一个节点
void SEQ_gToPrintNode(SeqListNodeData* node);
// 按照位置查找，逻辑位置
SeqListNodeData* SEQ_gToFindByIndex(SeqListNode* ListHead,int index);
// 顺序查找，按照比对信息进行判断,返回逻辑位置
int SEQ_gToFindByInformation(SeqListNode* ListHead,int infor);
/***********************************************************************/





SeqListNode* SEQ_gToCreateSequentialList()
{
    SeqListNode* ListHead = (SeqListNode*)malloc(sizeof(SeqListNode));
    if (ListHead == NULL)
    {
        printf("开辟空间失败！请重新开辟空间~\n");
        exit(0);
    }
    else
    {
        printf("请输入需要创建顺序链表的结点数量:~\n");
        int NodeNum;
        scanf("%d",&NodeNum);
        ListHead->dNode = (SeqListNodeData*)malloc( sizeof(SeqListNodeData) * NodeNum);
        if (ListHead->dNode == NULL)
        {
            printf("顺序链表数据内容空间开辟失败！请重新开辟空间~\n");
            exit(0);
        }
    }
    ListHead->index = 0;
    return ListHead;
}

void SEQ_gToReadFileData(const char* FILEPATH, SeqListNode* ListHead)
{
    FILE *fp = NULL;
    if ((fp = fopen(FILEPATH,"r")) == NULL)
    {
        /* code */
        printf("打开文件失败！请重新打开文件~\n");
        exit(0);
    }
    if(ListHead == NULL)
    {
        printf("顺序链表空间为空！请重新输入顺序链表~\n");
        exit(0);
    }
    // 临时定义一个数组用于去掉第一行的数据
    char *gFirstRowInfo = (char*)malloc(sizeof(char) * FIRSTROWLENGHT);
    if (gFirstRowInfo!=NULL)
    {    
        fgets(gFirstRowInfo,FIRSTROWLENGHT,fp);
        free(gFirstRowInfo);
    }
    SEQ_gToGetInformation(fp,ListHead);
    fclose(fp);
}

void SEQ_gToGetInformation(FILE* fp, SeqListNode* ListHead)
{
    int scorenumber = 0, index = 0;
    printf("请输入学生的成绩门数：\n");
    scanf("%d",&ListHead->nscore);
    BOOL flag = TRUE;
    do
    {
        /* code */
        int gren = fscanf(fp, "%d   %s  ", &ListHead->dNode[index].id, ListHead->dNode[index].name);
        ListHead->dNode[index].score = (float*)malloc(sizeof(float) * ListHead->nscore);
        if ((ListHead->dNode[index].score != NULL) && (ListHead->dNode[index].id != -1))
        {
            int i;// 用于分数的循环
            for(i = 0;i < ListHead->nscore - 1; i++)
            {
                fscanf(fp,"%f   ",&ListHead->dNode[index].score[i]);
            }
            fscanf(fp,"%f\n",&ListHead->dNode[index].score[i]);
            ListHead->index++;
        }
        else{
            flag = FALSE;
        }
        index++;
    } while (flag);
}

void SEQ_gToPrint(SeqListNode* ListHead)
{
    printf("\n顺序链表中储存的信息为：\n");
    int i,j;
    for (i = 0;i < ListHead->index;i++)
    {
        printf("%d,%s,",ListHead->dNode[i].id,ListHead->dNode[i].name);
        for (j = 0;j < ListHead->nscore;j++)
        {
            printf("%f,",ListHead->dNode[i].score[j]);
        }
        printf("\b\n");
    }
}

void SEQ_gToFreeSpace(SeqListNode* ListHead)
{
    if (ListHead->dNode)
    {
        free(ListHead->dNode);
        ListHead->dNode = NULL;
    }
    if (ListHead)
    {
        free(ListHead);
        ListHead =NULL;
    }

}

void SEQ_gToDeleteNode(SeqListNode* ListHead,int Location)
{
    if(Location<1||(Location>ListHead->index))
    {
        printf("删除的位置不合法，请重新输入位置！\n");
        exit(0);
    }
    else{
        for(int i = Location-1; i < ListHead->index; i++)
        {
            ListHead->dNode[i] = ListHead->dNode[i+1];
        }
        ListHead->index--;
    }
}

void SEQ_gToInsertAtLast(SeqListNode* ListHead,SeqListNodeData Node)
{
    ListHead->dNode[ListHead->index] = Node;
    ListHead->index++;    
}

void SEQ_gToInsertAtHead(SeqListNode* ListHead,SeqListNodeData Node)
{
    int i = 0;
    for( i= ListHead->index;i>0;i--)
    {
        ListHead->dNode[i] = ListHead->dNode[i-1];
    }
    ListHead->dNode[i] = Node;
    ListHead->index++; // 顺序链表的节点个数需要+1
}

BOOL SEQ_gSeqListIsNull(SeqListNode* ListHead)
{
    if (ListHead->index == 0){
        return TRUE;
    }
    return FALSE;
}

BOOL SEQ_gSeqListIsFull(SeqListNode* ListHead)
{
    if (ListHead->index == sizeof(ListHead->dNode)/sizeof(SeqListNodeData))
    {
        return TRUE;
    }
    return FALSE;
}

void SEQ_gToInsertAtLocation(SeqListNode* ListHead,SeqListNodeData Node,int Location)
{
    if(Location<1||Location>ListHead->index)
    {
        printf("插入的位置不合法！请重新输入位置~\n");
        exit(0);
    }
    int i; // 游标
    for(i = ListHead->index;i > Location;i--)
    {
        ListHead->dNode[ListHead->index] = ListHead->dNode[ListHead->index-1];
    }
    ListHead->dNode[i] = Node;
    ListHead->index++;  
}

void SEQ_gToWriteToFileByBinary(const char* FILEPATH,SeqListNode* ListHead)
{
    FILE* fp = NULL;
    // 判断顺序表是否为空
    if (SEQ_gSeqListIsNull(ListHead))
    {
        printf("要写入到文件中的顺序表为空！请重新输入顺序表~\n");
        exit(0);
    }
    else
    {
        // 对文件打开的判断
        if ((fp = fopen(FILEPATH,"w")) == NULL)
        {
            printf("打开文件失败！请重新打开文件~\n");
            exit(0);
        }
        else
        {
            for (int i = 0; i < ListHead->index; i++)
            {
                /* code */
                fwrite(ListHead->dNode,sizeof(SeqListNodeData),1,fp);
            }         
        }
    }
    fclose(fp);
}

void SEQ_gToReadFileByBinary(const char* FILEPATH,SeqListNode* ListHead)
{
     FILE* fp = NULL;
    // 判断顺序表是否为空
    if (SEQ_gSeqListIsNull(ListHead))
    {
        printf("要写入到文件中的顺序表为空！请重新输入顺序表~\n");
        exit(0);
    }
    else
    {
        // 对文件打开的判断
        if ((fp = fopen(FILEPATH,"w")) == NULL)
        {
            printf("打开文件失败！请重新打开文件~\n");
            exit(0);
        }
        else
        {
            for (int i = 0; i < ListHead->index; i++)
            {
                /* code */
                fread(ListHead->dNode,sizeof(SeqListNodeData),1,fp);
            }         
        }
    }
    fclose(fp);
}

BOOL gToCompareAB(SeqListNodeData a,SeqListNodeData b)
{
    float sum_a = 0,sum_b = 0;
    for (int i = 0;i < sizeof(a.score)/sizeof(float);i++)
    {
        sum_a += a.score[i];
        sum_b += b.score[i];       
    }
    if (sum_a>sum_b)
    {
        return TRUE;
    }
    return FALSE;
}

void SEQ_gToSort(SeqListNode* ListHead)
{
    // 按照结点进行排序
    for(int i = 0;i < ListHead->index;i++)
    {
        for (int j = 0;j < ListHead->index-i-1;j++)
        {
            if (gToCompareAB(ListHead->dNode[j],ListHead->dNode[j+1]))
            {
                SeqListNodeData temp = ListHead->dNode[j];
                ListHead->dNode[j] = ListHead->dNode[j+1];
                ListHead->dNode[j+1] = temp;
            }
        }
    }       
}

SeqListNodeData* SEQ_gToFindByIndex(SeqListNode* ListHead,int index)
{
    SeqListNodeData* TarNode = NULL;
    if(index>=ListHead->index||index<0)
    {
        printf("待查找的位置超出顺序表的界限~请重新输入index\n");
        exit(0);
    }
    for (int i = 0;i < ListHead->index;i++){
        if(i == index-1)
        {
            TarNode = &ListHead->dNode[i];
        }
    }
    return TarNode;
}

void SEQ_gToPrintNode(SeqListNodeData* node)
{
    printf("%d  %s  ",node->id,node->name);
    for(int i=0;i < sizeof(node->score)/sizeof(float);i++)
    {
        printf("%f  ");
    }
    printf("\n");
}

int SEQ_gToFindByInformation(SeqListNode* ListHead,int infor)
{
    for (int i = 0;i < ListHead->index;i++)
    {
        if (infor == ListHead->dNode[i].id)
        {
            return i+1;
        }
    }
    return -1;
}

