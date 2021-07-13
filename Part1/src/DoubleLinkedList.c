/*
 * @Author: your name
 * @Date: 2021-07-08 10:40:00
 * @LastEditTime: 2021-07-08 21:21:46
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Dstructure\Part1\src\DoubleLinkedList.c
 */
#include "DoubleLinkedList.h"
DoubLinkList initDoubleLinkList()
{
    DoubLinkList list = (DoubLinkList)malloc(sizeof(DoubLinkListNode));
    if(list == NULL)
    {
        printf("结点空间开辟失败，请重新开辟结点空间~\n");
        exit(0);
    }
    list->prior = NULL;
    list->next = NULL;
    return list;
}

DoubLinkList GtoReadFile(const char* filePath, DoubLinkList List)
{
    FILE* fp  = NULL;
    if((fp = fopen(filePath,"r")) == NULL)
    {
        printf("文件打开失败！请重新打开文件~\n");
        exit(0);
    }
    // 定义转换的结点
    DoubLinkList pList = List;
    
    DoubLinkList tList = NULL;
    int flag = 0;
    do{
        tList = (DoubLinkList)malloc(sizeof(DoubLinkListNode));
        flag  = fscanf(fp,"%d ",&tList->elem.data);
        if(flag>0)
        {
            tList->next = pList->next;
            tList->prior = pList;
            pList->next = tList;
            pList = tList;
        }
    }while(flag>0);
    pList->next = NULL;
    
    return List;
}


void GtoPrintDoubleLinkedList(DoubLinkList List)
{
    DoubLinkList pList = List->next;
    printf("双向循环链表的数据展示如下:\n");
    while (pList)
    {
        /* code */
        printf("%d   ",pList->elem.data);
        pList = pList->next;

    }
    
}

int GtoGetDoubleLinkedListLength(DoubLinkList List)
{
    int i = 0;
    DoubLinkList pList = List->next;
    while (pList)
    {
        pList = pList->next;
        i++;
    }
    return i;
}

struct Elem* GtoFindElemByIndex(DoubLinkList List, int index)
{
    DoubLinkList pList = List;
    int i = 0;
    if (index < 1 || index > GtoGetDoubleLinkedListLength(List))
    {
        printf("查找的位置不合法！请重新输查找的位置~\n");
        printf("双向链表的长度为 %d",GtoGetDoubleLinkedListLength(List));
        exit(0);
    }
    while (i < index - 1)
    {
        /* code */
        pList = pList->next;
        i++;
    }
    return &pList->next->elem;   
}


struct Elem* GtoFindElemByValue(DoubLinkList List,int value)
{
    DoubLinkList pList = List;
    while (pList)
    {
        /* code */
        if (pList->elem.data == value)
        {
            return &pList->elem;            
        }
    }
    printf("双向链表中没有待查找的值！请重新输入需要待查找的值~\n");
    return NULL; 
}


// DoubLinkList GtoCreateLintNodeByTerminal()
// {
//     DoubLinkList Node  = (DoubLinkList)malloc(sizeof(DoubLinkListNode));
//     if(Node == NULL)
//     {
//         printf("结点空间开辟失败！请重新开辟结点空间~\n");
//         exit(0);
//     }
//     printf("请输入双向链表的信息：\n");
//     scanf("%d",&Node->elem.data);
//     Node->prior  = Node->next = NULL;
//     return Node;
// }

void GtoPrintDoubleLinkedListNode(struct Elem* elem)
{
    if(elem)
    {
        printf("\n结点数据域为：%d",elem->data);
    }
}

void GtoDeleteDoubleLinkedList(DoubLinkList List)
{
    DoubLinkList pList = List;
    while (List)
    {
        /* code */
        pList = List;
        List = List->next;
        free(pList);
        pList = NULL;
    }   
}


DoubLinkList GtoCreateLintNodeByTerminal()
{
    DoubLinkList Node  = (DoubLinkList)malloc(sizeof(DoubLinkListNode));
    if(Node == NULL)
    {
        printf("结点空间开辟失败！请重新开辟结点空间~\n");
        exit(0);
    }
    printf("\n请输入双向链表的信息：\n");
    scanf("%d",&Node->elem.data);
    Node->prior  = Node->next = NULL;
    return Node;
}
DoubLinkList GtoInsertLinkedListNodeBeforeIndex(DoubLinkList List,int index,DoubLinkList node)
{
    if (node == NULL)
    {
        /* code */
        printf("插入的结点为空！请重新输入结点~\n");
        exit(0);
    }
    
    int i = 0;    // 索引控制
    DoubLinkList pList = List;
    while (i < index-1)
    {
        /* code */
        pList = pList->next;
        i++;
    }
    node->next = pList->next;
    pList->next->prior = node;
    pList->next = node;
    node->prior = pList;
}





