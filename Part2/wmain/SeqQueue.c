/*
 * @Author: your name
 * @Date: 2021-07-13 17:40:20
 * @LastEditTime: 2021-07-13 21:37:55
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
    printQueue(queue);                         // 打印队列中的元素
    destroyQueue(queue);                       // 销毁循环队列
    return 0;
}