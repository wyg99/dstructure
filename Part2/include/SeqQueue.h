/*
 * @Author: your name
 * @Date: 2021-07-13 17:32:16
 * @LastEditTime: 2021-08-26 12:17:07
 * @LastEditors: Please set LastEditors
 * @Description: 顺序队列.h FILE
 * @FilePath: \Dstructure\Part2\include\SeqQueue.h
 */
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20

// 定义BOOL类型
typedef enum BOOL{
    FALSE,
    TRUE
}BOOL;
// 结点存储数据
typedef struct Elem
{
    /* data */
    int data;      // 结点中数据域中存储的数据
}Elem;

// 定义队列数据类型
typedef struct SeqQueue
{
    /* data */
    Elem* base;   // 数据
    int front,rear;  // 表示队列的头和尾部
}SeqQueue;

// 队列的初始化
SeqQueue* initQueue();

// 读取文件数据
void readFile(const char* filePath,SeqQueue* queue);

// 打印队列的信息
void printQueue(SeqQueue* queue);

// 获取队列的元素的个数
int GetqueueLen(SeqQueue* queue);

// 销毁队列
void destroyQueue(SeqQueue* queue);

// 出队列
void popQueue(SeqQueue* queue,Elem* elem);

// 进队列
void pushQueue(SeqQueue* queue,Elem* elem);

// 创建一个队列元素
void createQueueNode(Elem* elem);

// 判断队列是否为空
BOOL QueueIsEmpty(SeqQueue* queue);

// 判断队列是否已经满了
BOOL QueueIsFull(SeqQueue* queue);

// 获取队列的队头元素
void GetHeadElemOfQueue(SeqQueue* queue,Elem* elem);




