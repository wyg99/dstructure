/*
 * @Author: your name
 * @Date: 2021-08-26 13:13:55
 * @LastEditTime: 2021-08-26 17:09:31
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Dstructure\Part2\wmain\LinkQueue.cpp
 */

#include"LinkQueue.h"
int main()
{
    LinkQueue queue = InitQueue();
    const char* filePath = "../data/seq.txt";
    readFile(queue,filePath);                  // 读取文件数据
    printQueue(queue);
    destroyQueue(queue);
    return 0;
}












