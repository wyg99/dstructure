/*
 * @Author: your name
 * @Date: 2021-08-26 13:11:06
 * @LastEditTime: 2021-08-26 17:07:28
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Dstructure\Part2\src\LinkQueue.cpp
 */
#include "LinkQueue.h"


LinkQueue InitQueue()
{
    LinkQueue queue = (LinkQueue)malloc(sizeof(struct gLinkQueue));
    if (queue == NULL)
    {
        printf("空间开辟失败~请重新开辟空间\n");
        exit(0);
    }
    queue->rear = queue->front = (ptrQueue)malloc(sizeof(QNode));
    queue->front->next = NULL;
    queue->len = 0;
    return queue;
}

void readFile(LinkQueue queue,const char* filePath)
{
    FILE* fp =NULL;
    if ((fp = fopen(filePath,"r")) == NULL){
        printf("打开文件失败~请重新打开文件！");
        exit(0);
    }
    int index = 0;
    while (index < 6)
    {
        /* code */
        QNode* node = (QNode*)malloc(sizeof(QNode));
        fscanf(fp,"%d ",&node->elem.data);
        node->next = NULL;
        pushElem(queue,node);



        index++;
    }
    fclose(fp);
}


void pushElem(LinkQueue queue,QNode* node)
{
    if(Length(queue) == 0)
    {
        queue->rear->elem.data = node->elem.data;
        queue->rear->next = NULL;
        
    }        
    else
    {
        
        queue->rear->next = node;
        queue->rear = node;
    }
    
    queue->len++;
}

void popElem(LinkQueue queue,QNode* node)
{
    
    ptrQueue elem = queue->front;
    node->elem.data = elem->elem.data;
    queue->front = queue->front->next;
    free(elem);
    elem = NULL;
    queue->len--;
}

void destroyQueue(LinkQueue queue)
{
    if(queue)
    {
        ptrQueue node = queue->front;
        while (node)
        {
            /* code */
            queue->front = node->next;
            free(node);
            node = queue->front;
        }
        free(queue);
        queue = NULL;
    } 
}

void printQueue(LinkQueue queue)
{
    QNode node;
    while (Length(queue))
    {
        popElem(queue,&node);
        printf("%d",node.elem.data);
    }
    
}

int Length(LinkQueue queue)
{
    return queue->len;
}




