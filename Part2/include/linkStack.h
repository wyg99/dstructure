/*
 * @Author: your name
 * @Date: 2021-07-12 22:01:16
 * @LastEditTime: 2021-07-13 17:12:10
 * @LastEditors: Please set LastEditors
 * @Description: 链栈的练习
 * @FilePath: \Dstructure\Part2\include\linkStack.h
 */
#include<stdlib.h>
#include<stdio.h>
#define MAXSIZE 50

typedef enum BOOL{
    FALSE,
    TRUE
}BOOL;
// 定义数据类型
typedef struct Elem
{
    int data;            // 数据域
    struct Elem* next;    // 指针指向下一个元素
}Elem;
// 定义链栈类型
typedef struct LinkStack
{
    int len;    // 栈的长度
    Elem* top;  // 栈顶
}LinkStack;



// 初始化链栈
void initLinkStack(LinkStack* stack);

// 读取文件中的元素
void ReadFileCreateStack(const char* filePath,LinkStack* stack);

// 输出栈中的元素
void PrintStack(LinkStack* stack);

// 判断栈是否为空
BOOL LinkStackIsEmpty(LinkStack* stack);

// 判断栈是否溢出
BOOL LinkStackOverLen(LinkStack* stack);

// 获取链栈的长度
int GetLen(LinkStack* stack);

// 压栈
void pushStack(LinkStack* stack,Elem* elem);

// 出栈
void popStack(LinkStack* stack,Elem* elem);

// 销毁栈
void Destroy(LinkStack* stack);

// 终端创建结点的数据域进行压栈
void createNodeFromTerminal(Elem* elem);
