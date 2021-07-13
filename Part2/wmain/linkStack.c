/*
 * @Author: your name
 * @Date: 2021-07-13 16:47:21
 * @LastEditTime: 2021-07-13 17:26:00
 * @LastEditors: Please set LastEditors
 * @Description: 链栈的主程序
 * @FilePath: \Dstructure\Part2\wmain\linkStack.c
 */
#include "linkStack.h"
int main()
{
    // 定义链栈
    LinkStack stack;
    // 初始化链栈
    initLinkStack(&stack);
    // 读取文件
    const char* filePath = "../data/seq.txt";
    ReadFileCreateStack(filePath,&stack);
    Elem elem;
    createNodeFromTerminal(&elem);
    pushStack(&stack,&elem);
    int len = GetLen(&stack);
    printf("链栈中的元素个数为：%d\n",len);
    // 打印链栈中的元素
    PrintStack(&stack);
    // 销毁链栈，释放空间
    
    Destroy(&stack);    
    return 0;
}