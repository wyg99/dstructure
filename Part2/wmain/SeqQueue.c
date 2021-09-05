/*
 * @Author: your name
 * @Date: 2021-07-13 17:40:20
 * @LastEditTime: 2021-08-26 12:19:26
 * @LastEditors: Please set LastEditors
 * @Description: 循环队列.main
 * @FilePath: \Dstructure\Part2\wmain\SeqQueue.c
 */
#include "SeqQueue.h"
int main()
{
    // 创建一个队列
    SeqQueue* queue = initQueue();
    const char* filePath = "../data/seq.txt";
    readFile(filePath,queue);                  // 读取文件数据
    int len = GetqueueLen(queue);
    printf("\n队列的长度为：%d\n",len);        // 获取队列中的元素

    // Elem elem;                                 // 创建一个结点元素插入队列中
    // createQueueNode(&elem);
    // pushQueue(queue,&elem);


    // GetHeadElemOfQueue(queue,&elem);
    // printf("\n队头元素为：%d",elem.data);       
    printQueue(queue);                         // 打印队列中的元素
    destroyQueue(queue);                       // 销毁循环队列
    return 0;
}