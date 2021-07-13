/*
 * @Author: your name
 * @Date: 2021-07-12 16:01:50
 * @LastEditTime: 2021-07-12 21:29:39
 * @LastEditors: Please set LastEditors
 * @Description: 顺序栈的实现
 * @FilePath: \Dstructure\Part2\include\SeqStack.h
 */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
// 定义BOOL类型
typedef enum BOOL{
    FALSE,
    TRUE
}BOOL;
// 创建数据域
typedef struct DataElem
{
    int data; // 栈空间中存储的值
}Elem;

// 创建顺序栈的类型
typedef struct SeqStack
{
    /* data */
    int size;    // 栈的元素个数
    Elem *top;   // 栈顶
    Elem *base;  // 栈底
}SeqStack;

// 初始化栈
void initStatic(SeqStack* stack);

// 判断栈是否为空
BOOL StackIsEmpty(SeqStack* stack);

// 判断栈是否已经满了
BOOL StackIsFull(SeqStack* stack);

// 获取栈中的元素的长度
int GetStackLength(SeqStack* stack);

// 入栈
void PushElemToStack(SeqStack* stack,Elem* elem);

// 出栈
void PopElemFromStack(SeqStack* stack,Elem* elem);

// 创建入栈的元素
void CreateElem(Elem* elem);

// 栈的销毁
void DestroyStack(SeqStack* stack);

// 栈的置空操作
void ClearStack(SeqStack* stack);


// 读取文件数据，构建应用栈
void readFile(const char* filePath,SeqStack* stack);

// 读取栈中的元素
void PrintStack(SeqStack* stack);









