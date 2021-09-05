/*
 * @Author: your name
 * @Date: 2021-08-26 12:21:06
 * @LastEditTime: 2021-08-26 16:54:53
 * @LastEditors: Please set LastEditors
 * @Description: 链队列的相关的操作
 * @FilePath: \Dstructure\Part2\include\LinkQueue.h
 */

// 定义链队列的数据结构
#include<stdlib.h>
#include<stdio.h>

struct Elem
{
    /* data */
    int data;
};

typedef struct LinkQueueNode
{
    /* data */
    struct Elem elem;
    struct LinkQueueNode* next;
}QNode,*ptrQueue;

typedef struct gLinkQueue
{
    /* data */    
    ptrQueue front;
    ptrQueue rear;
    int len;
    
}*LinkQueue;

// 初始化链队列
LinkQueue InitQueue();

// 读入文件，构造链表的队列
void readFile(LinkQueue queue,const char* filePath);

// #入队 插入一个元素到队列中 
void pushElem(LinkQueue queue,QNode* node);

// #出队 删除队列的首元素~
void popElem(LinkQueue queue,QNode* node);

// 获取队列头元素
void GetHeadElem(LinkQueue queue,QNode* node);

// 销毁队列
void destroyQueue(LinkQueue queue);

// 获取队列的长度
int Length(LinkQueue queue);

// 打印输出队列
void printQueue(LinkQueue queue);

// 判断链队列是否为空
