/*
 * @Author: WEI-YICHEN
 * @Date: 2021-07-04 20:45:16
 * @LastEditTime: 2021-07-06 14:22:08
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
    float score[SCORENUM];   // 有多少门成绩
}Elem;

/* 循环链表的结点 */
typedef struct CirListNode
{
    Elem* elem;
    struct CirListNode* next;
}CirLinkListNode,*CirLinkList;

// 初始化单链表
CirLinkList wToInitCircleLinkList();

// 判断结点开辟空间是否为空
void BoolLinkListNodeIsEmpty(CirLinkList node);