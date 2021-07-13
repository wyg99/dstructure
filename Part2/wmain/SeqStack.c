/*
 * @Author: your name
 * @Date: 2021-07-12 21:34:59
 * @LastEditTime: 2021-07-12 22:00:07
 * @LastEditors: Please set LastEditors
 * @Description: 栈操作主函数
 * @FilePath: \Dstructure\Part2\wmain\SeqStack.c
 */

#include "SeqStack.h"
int main()
{
    SeqStack stack;                             // 定义栈
    const char* filePath = "../data/seq.txt";
    initStatic(&stack);                         // 初始化栈
    readFile(filePath,&stack);                  // 读取文件，构建栈的实例
    Elem elem;                                  // 定义需要插入的元素
    CreateElem(&elem);                          // 终端输入结点的信息
    PushElemToStack(&stack,&elem);              // 将元素压栈
    PrintStack(&stack);                         // 打印栈中的元素
    DestroyStack(&stack);                       // 销毁栈
    return 0;
}