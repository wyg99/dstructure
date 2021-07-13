/*
 * @Author: your name
 * @Date: 2021-07-08 10:39:19
 * @LastEditTime: 2021-07-08 20:45:06
 * @LastEditors: Please set LastEditors
 * @Description: 双向链表练习头文件
 * @FilePath: \Dstructure\Part1\include\DoubleLinkedList.h
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 定义双向链表的结构体
struct Elem
{
    /* data */
    int data;
};
typedef struct DoubleLinkedList
{
    /* data */
    struct Elem elem;   // 数据域
    struct DoubleLinkedList* prior;    // 前向指针
    struct DoubleLinkedList* next;     // 后向指针
}DoubLinkListNode,*DoubLinkList;

// 初始化双向链表
DoubLinkList initDoubleLinkList();

// 读取文件数据
DoubLinkList GtoReadFile(const char* filePath, DoubLinkList List);

// 打印双向链表的数据
void GtoPrintDoubleLinkedList(DoubLinkList List);

// 按照位置进行查找数据
struct Elem* GtoFindElemByIndex(DoubLinkList List, int index);

// 按照值进行查找数据
struct Elem* GtoFindElemByValue(DoubLinkList List,int value);



// 获取双向链表的长度
int GtoGetDoubleLinkedListLength(DoubLinkList List);

// 打印双向链表结点的值
void GtoPrintDoubleLinkedListNode(struct Elem* elem);

// 销毁双向循环链表
void GtoDeleteDoubleLinkedList(DoubLinkList List);

// 通过终端输入，录入链表的结点
DoubLinkList GtoCreateLintNodeByTerminal();

// 在双向链表第i个结点之前插入一个结点
DoubLinkList GtoInsertLinkedListNodeBeforeIndex(DoubLinkList List,int index,DoubLinkList node);

