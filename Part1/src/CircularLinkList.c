/*
 * @Author: your name
 * @Date: 2021-07-06 14:11:02
 * @LastEditTime: 2021-07-12 16:03:06
 * @LastEditors: Please set LastEditors
 * @Description: 循环单链表的相关的操作
 * @FilePath: \datastructure\Part1\main\CircleLinkList.c
 */

#include"CircularLinkList.h"

CirLinkList wToInitCircleLinkList()
{
    CirLinkList head =  NULL;
    head = (CirLinkList)malloc(sizeof(CirLinkListNode));
    head->next = head;
    BoolLinkListNodeIsEmpty(head);
    return head;
}

void BoolLinkListNodeIsEmpty(CirLinkList node)
{
    if (node == NULL)
    {
        printf("结点空间开辟失败！请重新开辟空间~\n");
        exit(0);
    }
}

CirLinkList wToReadFile(const char* filepath,CirLinkList List)
{
    // 读取文件
    FILE* fp;
    if((fp = fopen(filepath,"r")) == NULL)
    {
        printf("打开文件失败，请重新打开文件~\n");
        exit(0);
    }
    // 判断循环链表的头结点是否为空
    BoolLinkListNodeIsEmpty(List);
    int StudentsNumber = 0 ,ScoresNumber = 0;
    fscanf(fp,"%d %d",&StudentsNumber,&ScoresNumber);
    int index = 0;
    while(index < StudentsNumber)
    {
        CirLinkList pNode = (CirLinkList)malloc(sizeof(CirLinkListNode));
        fscanf(fp,"%d %s",&pNode->elem.id,pNode->elem.name);
        for (int i = 0;i < ScoresNumber;i++)
        {
            fscanf(fp," %d",&pNode->elem.score[i]);
        }
        pNode->next = List->next;
        List->next = pNode;
        List = pNode;
        index++;
    }
    return List;
}

void wToPrintCircularLinkList(CirLinkList List)
{
    CirLinkList pNode = List->next->next;
    while (pNode!=List->next)
    {
        printf("%d,%s,",pNode->elem.id,pNode->elem.name);
        for(int i = 0 ;i < 3;i++)
        {
            printf("%d,",pNode->elem.score[i]);
        }
        printf("\n");
        pNode = pNode->next;
        
        /* code */
    }
    //return true;
    
}

int wToGetLength(CirLinkList List)
{
    int len = 0;
    CirLinkList pNode = List->next->next;
    while ( pNode != List->next)
    {
        /* code */
        len++;
        pNode = pNode->next;
    }
    return len;   
}

CirLinkList wToCreateNode()
{
    CirLinkList pNode = (CirLinkList)malloc(sizeof(CirLinkListNode));
    BoolLinkListNodeIsEmpty(pNode);
    printf("请输入结点的相关的信息：\n");
    printf("请输入学生的学号id:");
    scanf("%d",&pNode->elem.id);
    printf("请输入学生的学号name:");
    scanf("%s",pNode->elem.name);
    for (int i = 0;i < SCORENUM;i++)
    {
        printf("请输入该学生的第 %d 门成绩:",i);
        scanf(" %d",&pNode->elem.score[i]);
    }
    return pNode;
}

CirLinkList wToInsertListNode(CirLinkList List,int index, CirLinkList node)
{
    CirLinkList plist = List->next;
    int i = 0;
    while (i < index-1)
    {
        plist = plist->next;
        i++;
    }
    node->next = plist->next;
    plist->next = node;
    return plist;
}

Bool CircularLinkListIsEmpty(CirLinkList List)
{
    if(List = List->next)
    {
        return TRUE;
    }
    return FALSE;
}

void wToClearLinkList(CirLinkList List)
{
    if(CircularLinkListIsEmpty(List))
    {
        printf("循环单链表的元素为空！请重新输入循环单链表~\n");
        exit(0);
    }
    
    CirLinkList pList = List->next->next,tempList = NULL,head = List->next; // 用于保存循环单链表的头结点
    while (pList != List->next)
    {
        /* code */
        tempList = pList;
        pList = pList->next;
        free(tempList);
        tempList = NULL;       
    } 
    head->next = head;  
    
}

void wToDeleteLinkList(CirLinkList List)
{    
    CirLinkList plist  = List->next;
    List->next = NULL; // 将循环单链表的尾结点设置为空
    
    while(plist)
    {
        CirLinkList temp = plist;
        plist = plist->next;
        free(temp);
        temp = NULL;
    }
    // 说明
    printf("完成循环单链表的删除操作!\n");
}

Elem* wToGetElem(CirLinkList List,int i)
{
    int index = 0;
    CirLinkList hList  = List->next;
    while (index<i)
    {
        /* code */
        hList = hList->next;
        index++;
    }
    Elem* elem = &hList->elem;
    return elem;    
}

void wToPrintNodeElem(Elem* elem)
{
    printf("结点的信息为: \n");
    printf("学生的学号为 %d\n",elem->id);
    printf("学生的姓名为 %s\n",elem->name);
    for(int i= 1 ;i <= SCORENUM;i++)
    {
        printf("该学生的第 %d 门成绩为 %d\n",i,*(elem->score+i-1));
    }
}
void wToFindElem(CirLinkList List,int id,Elem* elem)
{
    // Elem* elem;
    CirLinkList pLisT = List->next->next; // 转换到循环单链表以头指针表示的循环单链表
    while (pLisT!=List->next)
    {
        /* code */
        if(pLisT->elem.id == id)
        {
            elem->id = pLisT->elem.id;
            strcpy(elem->name,pLisT->elem.name);
            for(int i =0 ;i < SCORENUM;i++)
            {
                elem->score[i] = pLisT->elem.score[i];
            }

        }
        pLisT = pLisT->next;
    }
}

void wToFreeLinkListNode(CirLinkList List,int index)
{
    CirLinkList pList = List->next;
    int i = 0;
    while (i < index - 1)
    {
        pList = pList->next;
        i++;
    }    
    CirLinkList temp = pList->next;
    pList->next = pList->next->next;
    free(temp);
    temp = NULL;
}












