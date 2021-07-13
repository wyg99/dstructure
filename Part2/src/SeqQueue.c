/*
 * @Author: your name
 * @Date: 2021-07-13 17:40:10
 * @LastEditTime: 2021-07-13 21:36:43
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Dstructure\Part2\src\SeqQueue.c
 */
#include "SeqQueue.h"

SeqQueue* initQueue()
{
    SeqQueue* queue = NULL;
    queue = (SeqQueue*)malloc(sizeof(SeqQueue));
    if(queue == NULL)
    {
        printf("队列空间开辟失败，请重新开辟空间~\n");
        exit(0);
    }
    else
    {
        queue->base = (Elem*)malloc(sizeof(Elem) * MAXSIZE);
        if(queue->base == NULL)
        {
            printf("队列的元素空间开辟失败，请重新开辟空间~\n");
            exit(0);
        }
        else
        {
            queue->front = queue->rear = 0;
            return queue;
        }
    }
}

void readFile(const char* filePath,SeqQueue* queue)
{
    FILE* fp = NULL;
    if ((fp = fopen(filePath,"r")) == NULL)
    {
        printf("打开文件失败，请重新打开文件~\n");
        exit(0);
    }
    int tempdata = 0,flag;   // flag用于判定读取文件的返回值
    do
    {
        /* code */
        flag = fscanf(fp,"%d ",&tempdata);        
        if(flag > 0)
        { 
            // 创建结点空间
            Elem* elem = (Elem*)malloc(sizeof(Elem));
            if(elem == NULL)
            {
                printf("开辟空间失败！请重新开辟空间~\n");
                exit(0);
            }
            elem->data = tempdata;

            pushQueue(queue,elem);
        }
    }while(flag > 0);
    
    fclose(fp);
}


void pushQueue(SeqQueue* queue,Elem* elem)
{
    if(!QueueIsFull(queue) && elem)
    {
        queue->base[(queue->rear++)%MAXSIZE].data = elem->data;
    }
}

void popQueue(SeqQueue* queue,Elem* elem)
{
    if(!QueueIsEmpty(queue) && elem)
    {
        elem->data =  queue->base[(queue->front++)%MAXSIZE].data;
    }
}


BOOL QueueIsEmpty(SeqQueue* queue)
{
    if(queue->front == queue->rear)
        return TRUE;
    return FALSE;
}


BOOL QueueIsFull(SeqQueue* queue)
{
    if((queue->rear+1) % MAXSIZE == queue->front)
        return TRUE;
    return FALSE;
}

int GetqueueLen(SeqQueue* queue)
{
    return (queue->rear - queue->front + MAXSIZE) % MAXSIZE;
}

void printQueue(SeqQueue* queue)
{
    printf("队列中的对象为：\n");
    while(!QueueIsEmpty(queue)){
        Elem elem;
        popQueue(queue,&elem);
        
        printf("%d  ",elem.data);
    }
    
}


void destroyQueue(SeqQueue* queue)
{
    if(queue->base)
    {
        free(queue->base);
        queue->base = NULL;
        
    }
    free(queue);
    queue = NULL;
}







