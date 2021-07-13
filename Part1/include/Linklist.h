#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NAMELENGHT 10
#define SCORESUM 3
enum BOOL{False,True};
typedef enum BOOL BOOL;
typedef struct Studata
{
    int id;
    char name[NAMELENGHT];
    float *score;
}Elem;

typedef struct SingleLinkList
{
    /* data */
    Elem elem;
    struct SingleLinkList *next;    
}LinkListNode,*LinkList;

/**
 * @description:用于单链表的合并，新建的结点类型
 */
typedef struct singlelists
{
    int elem;  // 结点的数据域
    struct singlelists* next;
}NumberListNode,*NumberListPtr;

/******************************************************************/

/**
 * @description: 带头结点单链表的创建
 * @param {nullptr}
 * @return {ListHead}
 */
LinkList gToCreateListHead();
/**
 * @description: 读取文件数据，填充单链表
 * @param {*}
 * @return {*}
 */
LinkList gToReadFile(const char* Filepath,LinkList ListHead);
/**
 * @description: 打印输出单链表
 * @param {*}
 * @return {*}
 */
void gToPrintList(LinkList List);
/**
 * @description: 单链表的长度计算操作
 * @param {LinkList ListHead,}
 * @return {int count}
 */
int gToGetLength(LinkList ListHead);
/**
 * @description: 判断单链表是否为空
 * @param {LinkList ListHead}
 * @return {bool}
 */
BOOL isLinkListNULL(LinkList ListHead);
/**
 * @description: 清空单链表
 * @param {*}
 * @return {*}
 */
void gToClearLinkList(LinkList ListHead);
/**
 * @description: 单链表的销毁
 * @param {*}
 * @return {*}
 */
void gToDestroyLinkList(LinkList ListHead);
/**
 * @description: 在单链表第i个位置之前插入一个元素
 * @param {*}
 * @return {*}
 */
void gToInsertElem(LinkList ListHead,LinkList Node, int index);
/**
 * @description: 判断元素插入位置是否正确
 * @param {*}
 * @return {*}
 */
BOOL TheLocationIsRight(LinkList ListHead,int index);
/**
 * @description: 获取第i个位置处的单链表的值
 * @param {*}
 * @return {*}
 */
LinkList gToGeIndexDataOfLinkList(LinkList ListHead,int index);
/**
 * @description: 删除单链表i个位置的值
 * @param {*}
 * @return {*}
 */
LinkList gToDeleteIndexDataOfLinkList(LinkList ListHead,int index);
/**
 * @description: 释放单个结点的空间
 * @param {*}
 * @return {*}
 */
void gToFreeLinkListNode(LinkList Node);
/**
 * @description: 在单链表的尾部进行插入
 * @param {LinkList} ListHead
 * @param {LinkList} Node
 * @return {*}
 */
LinkList gToInsertAtLinkListLast(LinkList ListHead,LinkList Node);
/**
 * @description: 冒泡排序
 * @param {LinkList} ListHead
 * @return {*}
 */
LinkList BubbleSortLinkList(LinkList ListHead);
/**
 * @description: 
 * @param {float} m
 * @param {float} n
 * @return {*}
 */
BOOL JudgeConditionIsRight(float m,float n);
/**
 * @description: 交换单链表的结点
 * @param {LinkList} m
 * @param {LinkList} n
 * @return {*}
 */
void ChangeTwoElem(LinkList m,LinkList n);
/**
 * @description: 两个单链表的合并，按照从小到大的顺序
 * @param {LinkList} list1
 * @param {LinkList} list2
 * @return {*}
 */
LinkList gToMergeTwoLinkLists(LinkList list1,LinkList list2);
/**
 * @description: 创建单链表的一个结点
 * @param {*}
 * @return {*}
 */
LinkList gToCreateNodeOfLinkList();
/**
 * @description: 终端录入结点的信息
 * @param {*}
 * @return {*}
 */
void gToInputNodeInformation(Elem* element)
{
    printf("请输入学生的学号：");
    scanf("%d",&element->id);
    printf("请输入学生的姓名：");
    scanf("%s",element->name);
    for(int index = 0;index < SCORESUM;index++)
    {
        printf("请输入第 %d 门课程的成绩：",index);
        scanf("%f",&element->score[index]);
    }
}
/**
 * @description: 打印单个结点
 * @param {LinkList} node
 * @return {*}
 */
void gToPrintNode(LinkList node);

/******************************************************************/

void gToPrintNode(LinkList node)
{
    if (node == NULL)
    {
        printf("待打印的结点为空指针~请重新输入指针~\n");
        exit(0);
    }else
    {
        printf("%d %s ",node->elem.id,node->elem.name);
        for(int i = 0; i < SCORESUM;i++)
        {
            printf("%f ",node->elem.score[i]);
        }
        printf("\n");
        
    }
    
}

LinkList gToCreateNodeOfLinkList()
{
    LinkList Node = (LinkList)malloc(sizeof(LinkListNode));
    if(Node ==NULL)
    {
        printf("结点空间开辟失败！请重新开辟空间~\n");
        exit(0);
    }else
    {
        printf("请输入节点的相关信息：\n");
        Node->elem.score = (float*)malloc(sizeof(float));
        if(Node->elem.score == NULL)
        {
            printf("结点元素空间开辟失败！请从新开辟结点元素空间~\n");
            exit(0);
        }
        else{
            gToInputNodeInformation(&Node->elem);
            Node->next =NULL;
        }
        
    }    
}

LinkList gToCreateListHead()
{
    LinkList ListHead = NULL;
    ListHead = (LinkList)malloc(sizeof(LinkListNode));
    if(ListHead ==NULL) {
        printf("头结点空间开辟失败！请从新开辟空间~\n");
        exit(0);
    }
    ListHead->next = NULL;  
    return ListHead;  
}

LinkList gToReadFile(const char* Filepath,LinkList ListHead)
{
    // 判断指针是否为空
    FILE *fp = NULL;
    LinkList list = ListHead;
    if ((fp = fopen(Filepath,"r")) == NULL)
    {
        /* code */
        printf("打开文件失败！请重新打开文件~\n");
        exit(0);
    }
    if(ListHead == NULL)
    {
        printf("单链表头为空，请重新输入单链表~\n");exit(0);
    }         
    // 运用尾插法进行数据的读取
    int elemsum = 0,scoresum = 0,index = 0;
    fscanf(fp,"%d %d",&elemsum,&scoresum);
    while (index < elemsum)
    {
        /* code */
        LinkList node = (LinkList)malloc(sizeof(LinkListNode));
        if(node == NULL)
        {
            printf("结点空间开始失败~\n");
            exit(0);
        }
        else{
            fscanf(fp,"%d %s",&node->elem.id,node->elem.name);
            node->elem.score = (float*)malloc(sizeof(float) * scoresum);
            if(node->elem.score == NULL)
            {
                printf("数据块空间开辟失败~\n");
                exit(0);
            }
            else
            {
                /* code */
                for(int i = 0;i<scoresum;i++)
                {
                    fscanf(fp," %f",&node->elem.score[i]);                   
                }
            }
            list->next = node;
            list = list->next;          
        }
        index++;
    }
    list->next = NULL;
    
    return ListHead;
}

void gToPrintList(LinkList List)
{
    LinkList tar = List->next;
    if(tar == NULL)
    {
        printf("单链表的信息为空~\n");
        exit(0);
    }
    while (tar)
    {
        /* code */
        printf("%d %s ",tar->elem.id,tar->elem.name);
        for(int i = 0; i < SCORESUM;i++)
        {
            printf("%f ",tar->elem.score[i]);
        }
        printf("\n");
        tar = tar->next;
    }  
}

int gToGetLength(LinkList ListHead)
{
    int count = 0; // 用于获得单链表的长度
    if(ListHead->next == NULL)
    {
        printf("单链表的长度为0！即将推出~\n");
        exit(0);
    }else
    {
        
        LinkList templist = ListHead->next;
        while (templist)
        {
            /* code */
            count++;
            templist = templist->next;
        }   
    }
    return count;  
}

BOOL isLinkListNULL(LinkList ListHead)
{
    if(ListHead->next == NULL)
    {
        return True;
    }
    return False;
}

void gToClearLinkList(LinkList ListHead)
{
    LinkList list1 = ListHead->next;
    LinkList list2 = NULL;
    if(list1 == NULL)
    {
        printf("单链表已经为空的链表！~请重新输入待清空的单链表~\n");
        exit(0);
    }
    else{
        while (list1)
        {
            /* code */
            list2 = list1;
            list1 = list1->next;
            free(list2->elem.score);
            list2->elem.score = NULL;
            free(list2);
            list2 = NULL;
        }    
        ListHead->next = NULL;    
    }
}

void gToDestroyLinkList(LinkList ListHead)
{
    LinkList list = NULL;
    while (ListHead)
    {
        /* code */
        list = ListHead;
        ListHead = ListHead->next;
        free(list->elem.score);
        list->elem.score = NULL;
        free(list);
        list = NULL;
    }  
}

void gToInsertElem(LinkList ListHead, LinkList Node, int index)
{
    if(TheLocationIsRight(ListHead,index) && Node)
    {
        LinkList list = ListHead;
        int i = 0;
        while(i < index-1)
        {
            list = list->next;
            i++;
        }
        Node->next = list->next;
        list->next = Node;
    }   
}

BOOL TheLocationIsRight(LinkList ListHead,int index)
{
    if(index>(gToGetLength(ListHead)+1) || index <1)
    {
        printf("插入的位置不正确！请重新输入待插入的位置~\n");
        return False;
    }
    return True;
}

LinkList gToGeIndexDataOfLinkList(LinkList ListHead,int index)
{
    
    if(index>gToGetLength(ListHead) || index<0)
    {
        printf("待取出元素位置不合！请重新输入位置~\n");
        exit(0);
    }
    else{
        int i = 0;
        LinkList list = ListHead;
        while (i<index-1)
        {
            /* code */
            list = list->next;
            i++;     //      
        }
        return list->next;       
    }
}

LinkList gToDeleteIndexDataOfLinkList(LinkList ListHead,int index)
{
    LinkList list = ListHead;
    if(index>gToGetLength(ListHead)||index<0)
    {
        printf("待删除的位置错误！超出界限~\n");
        exit(0);
    }else{
        int i = 0;
        while (i<index-1)
        {
            /* code */
            list = list->next; 
            i++;          
        }
        LinkList temp = list->next;
        list->next = list->next->next;
        // 将目标节点进行释空
        gToFreeLinkListNode(temp);        
    }
}

void gToFreeLinkListNode(LinkList Node)
{
    free(Node->elem.score);
    Node->elem.score = NULL;
    free(Node);
    Node = NULL;
}

LinkList gToInsertAtLinkListLast(LinkList ListHead,LinkList Node)
{
    LinkList list = ListHead;
    while(list->next)
    {
        list = list->next;
    }
    Node->next= list->next;
    list->next = Node;
    return ListHead;    
}

BOOL JudgeConditionIsRight(float m,float n)
{
    if(m > n) return True;
    return False;
}

LinkList BubbleSortLinkList(LinkList ListHead)
{
    
    int len = gToGetLength(ListHead);
    if(len == 0)
    {
        printf("单链表的长度为0!请重新输入待排序的单链表~\n");
        exit(0);
    }
    else{
        LinkList list = ListHead->next;
        LinkList list1 = list;
        for(int i = 0;i < len-1;i++)
        {          
            LinkList list2 = list;  
            for(int j = 0;j < len-1;j++)
            {      
                if (JudgeConditionIsRight(list2->elem.score[0],list2->next->elem.score[0]))
                {
                    // 交换数据
                    ChangeTwoElem(list2,list2->next);
                }
                list2 = list2->next;
            }
            list1 = list1->next;
        }
        return ListHead;     
    } 
}

void ChangeTwoElem(LinkList m,LinkList n)
{
    LinkList list = (LinkList)malloc(sizeof(LinkListNode));
    if(list == NULL)
    {
        printf("链表结点空间开辟失败!请重新开辟空间~\n");
        exit(0);
    }
    else{
        list->elem.score = (float*)malloc(sizeof(float) * SCORESUM);
        if(list->elem.score == NULL)
        {
            printf("结点数据元素空间开辟失败！请重新开辟空间~\n");
            exit(0);
        }
        else{
            // 现在开始交换指针所指地址的数据元素
            
            //list->elem = m->elem;
            list->elem.id = m->elem.id;
            strcpy(list->elem.name,m->elem.name);
            for(int i = 0;i <SCORESUM;i++)
            {
                list->elem.score[i] = m->elem.score[i];
            }
            //m->elem = n->elem;

            m->elem.id = n->elem.id;
            strcpy(m->elem.name,n->elem.name);
            for(int i = 0;i <SCORESUM;i++)
            {
                m->elem.score[i] = n->elem.score[i];
            }
            
            
            n->elem.id = list->elem.id;

            strcpy(n->elem.name,list->elem.name);
            for(int i = 0;i <SCORESUM;i++)
            {
                n->elem.score[i] = list->elem.score[i];
            }

            // 关于交换的一点修改

            // 指针域不交换
            /* code */
            // 将新开辟的空间进行释放
            gToFreeLinkListNode(list);  // 将list释放掉之后，因为n的指针指向这块内存，导致n的返回值就发生错误
        }
    }  
}




/**
 * @description: 创建单链表并实现文件的读取
 * @param {*}
 * @return {*}
 */
NumberListPtr nlToCreateTwoLinkList(NumberListPtr list1, NumberListPtr list2);
/**
 * @description: 打印单链表
 * @param {*}
 * @return {*}
 */
void nlToPrintNumberLinkList(NumberListPtr list);

/**
 * @description: 单链表的合并
 * @param {*}
 * @return {*}
 */
NumberListPtr gToMergeTwoLinkList(NumberListPtr list1, NumberListPtr list2);



NumberListPtr nlToCreateTwoLinkList(NumberListPtr listA, NumberListPtr listB)
{
    FILE *fp = NULL;
    if ((fp =fopen("..\\data\\singlelistnumber.txt","r")) == NULL)
    {
        printf("文件打开失败！请重新打开文件~\n");
        exit(0);
    }else
    {
        /* code */
        // 创建链表的头结点
        listA = listB = (NumberListPtr)malloc(sizeof(NumberListNode));
        if(listA == NULL || listB == NULL)
        {
            printf("头结点空间开辟失败，请重新开辟空间~\n");
            exit(0);
        }
        listA->next = listB->next = NULL;

        // 开始读取文件，并循环存入结点的信息
        int lenlist1 = 0,lenlist2 = 0;
        fscanf(fp,"%d,%d",&lenlist1,&lenlist2);
        // 替用两个临时的指针
        NumberListPtr listA1, listA2, listB1, listB2;
        listA1 = listA;
        listB1 = listB;
    
        // 进行循环遍历
        int i = 0,j = 0; // 循环输入的index
        while (i <lenlist1)
        {
            /* code */
            listA2 = (NumberListPtr)malloc(sizeof(NumberListNode));
            if (listA2 == NULL)
            {
                printf("结点空间开辟失败！请重新开辟结点空间~\n");
                exit(0);
            }
            fscanf(fp,"%d,",&listA2->elem);
            listA1->next = listA2;
            listA1 = listA2;
            i++;
        }
        listA1->next = NULL;
        while (j <lenlist2)
        {
            /* code */
            listB2 = (NumberListPtr)malloc(sizeof(NumberListNode));
            if (listB2 == NULL)
            {
                printf("结点空间开辟失败！请重新开辟结点空间~\n");
                exit(0);
            }
            fscanf(fp,"%d,",&listB2->elem);
            listB1->next = listB2;
            listB1 = listB2;
            j++;
        }
        listB1->next = NULL;
        // 最后释放文件指针       
    } 
    free(fp);
}

void nlToPrintNumberLinkList(NumberListPtr list)
{
    while(list->next)
    {
        printf("%d   ",list->elem);
    }
}


// 创建一个链表结点结构体
// typedef struct list
// {
//     /* data */
//     int elem;
//     struct list *next;
// }gNode;

// // 创建链表头结点
// gNode* gToCreatelist()
// {
//     gNode* listHead = (gNode*)malloc(sizeof(gNode));
//     if(listHead == NULL){
//         printf("头结点空间开辟失败！请重新开辟空间~\n");
//         exit(0);
//     }
//     listHead->next = NULL;
//     return listHead;
// }

// // 读取文件数据到单链表中
// gNode* gToGetDataFromFile(const char* filePath,gNode* listHead)
// {
//     FILE* fp = NULL;
//     if((fp = fopen(filePath,"r")) == NULL){
//         printf("文件打开失败！请重新打开文件~\n");
//         exit(0);
//     }
//     gNode* list1 = listHead,*list2 = NULL; 
//     do{
//         list2 = (gNode*)malloc(sizeof(gNode));
//         if(list2 ==NULL){
//             printf("结点空间开辟失败！请重新开辟空间~\n");
//             exit(0);
//         }
//         int rev = fscanf(fp,"%d,",&list2->elem);
//         if(rev){
//             list2.next = list1->next;
//             list1.next = list2;
//             list1 = list2;
//         }      
//     }while(rev)
//     return listHead;
// }

// // 获取链表的长度
// gNode gToGetLengthOfLinkList(gNode* listHead)
// {
//     gNode* list = listHead->next;
//     int i = 0;
//     while (list)
//     {
//         i++;
//         list = list->next;
//     }
//     return i;    
// }


// // 两个链表的合并，按照升序
// gNode* gToSortDoubleLinkList(gNode* listHead1,gNode* listHead2)
// {
//     gNode *list1 = listHead1->next,*list2 = listHead2->next;
//     // 需要一个新的链表
//     gNode* mergeListHead = gToCreatelist();
//     gNode* templist = mergeListHead;
//     while (list1 && list2)
//     {
//         if(list1->elem < list2->elem)
//         {
//             templist->next = list1;
//             list1 = list1->next;
//             templist = templist->next;

//         }else
//         {
//             templist->next = list1;
//             list1 = list1->next;
//             templist = templist->next;
//         }
//         templist->next = NULL;
//         if(list1)
//         {
//             templist->next = list1;
//         }
//         if(list2)
//         {
//             templist->next = list2;
//         }       
//     }    
//     return mergeListHead;
// }

// void gToPrintMergeLinkList(gNode* listHead)
// {
//     gNode* list = listHead->next;
//     if(list->next == NULL)
//     {
//         printf("单链表的内容为空！请重新输入单链表~\n");
//         exit(0);
//     }
//     while (list)
//     {
//         printf("排序后的结果为：\n");
//         printf("%d   ",list->elem);
//         list = list->next;
//     }   
// }
// // 链表的销毁
// gNode* gToDeleteLinkList(gNode* listHead)
// {
//     gNode* list = listHead;
//     while (listHead)
//     {
//         list = listHead;
//         listHead = listHead->next;
//         free(list);
//         list = NULL;
//     }  
// }

// // 链表的清空
// gNode gToClearThisLinkList(gNode* listHead)
// {
//     gNode *list1 = listHead,*list2 = listHead;

    

// }

