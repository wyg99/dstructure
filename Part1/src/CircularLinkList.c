/*
 * @Author: your name
 * @Date: 2021-07-06 14:11:02
 * @LastEditTime: 2021-07-06 14:35:35
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