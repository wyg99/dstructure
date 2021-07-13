/*
 * @Author: WEI-YICHEN
 * @Date: 2021-07-04 20:45:16
 * @LastEditTime: 2021-07-07 12:38:11
 * @LastEditors: Please set LastEditors
* @Description: 循环链表相关内容操作
  * @FilePath: \Datastructure\Part1\include\CircularLinkList.h
 */

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>
#define NAMELENTH 10
#define SCORENUM  3
/* 循环单链表的数据域 */
typedef struct ListElem
{
    int id;      // 学生的学号
    char name[NAMELENTH];   // 学生的姓名
    int score[SCORENUM];   // 有多少门成绩
}Elem;
enum BOOL{FALSE,TRUE};
typedef enum BOOL   Bool;
/* 循环链表的结点 */
typedef struct CirListNode
{
    Elem elem;
    struct CirListNode* next;
}CirLinkListNode,*CirLinkList;

// 初始化单链表
CirLinkList wToInitCircleLinkList();

// 判断结点开辟空间是否为空
void BoolLinkListNodeIsEmpty(CirLinkList node);

// 循环单链表数据读入
CirLinkList wToReadFile(const char* filepath,CirLinkList List);

// 单链表的可视化显示
void wToPrintCircularLinkList(CirLinkList List);

// 循环单链表的长度求解
int wToGetLength(CirLinkList List);

// 创建一个结点
CirLinkList wToCreateNode();

//循环单链表的插入操作
CirLinkList wToInsertListNode(CirLinkList List,int index, CirLinkList node);

// 循环单链表的清空
void wToClearLinkList(CirLinkList List);

// 判断循环单链表是否为空
Bool CircularLinkListIsEmpty(CirLinkList List);

// 删除单链表
void wToDeleteLinkList(CirLinkList List);

// 获取循环单链表的第i个位置的元素
// 从尾结点->next->next算起
Elem* wToGetElem(CirLinkList List,int i);

//打印结点的信息
void wToPrintNodeElem(Elem* elem);

// 按照输入的值进行查找
// 这里按照输入学生的id进行查找
void wToFindElem(CirLinkList List,int id,Elem* elem);

// 删除某一个结点的值
void wToFreeLinkListNode(CirLinkList List,int index);










