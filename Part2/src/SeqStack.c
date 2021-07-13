/*
 * @Author: your name
 * @Date: 2021-07-12 16:56:54
 * @LastEditTime: 2021-07-12 21:57:56
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Dstructure\Part2\src\SeqStack.c
 */
#include "SeqStack.h"
void initStatic(SeqStack* stack)
{
    stack->base = (Elem*)malloc(MAXSIZE* sizeof(Elem));
    if(stack->base == NULL)
    {
        printf("栈空间开辟失败！请从新初始化栈~\n");
        exit(0);
    }
    stack->top = stack->base;
    stack->size = 0;
}

void readFile(const char* filePath,SeqStack* stack)
{
    // 文件判读
    FILE *fp = NULL;
    if( (fp = fopen(filePath,"r")) == NULL)
    {
        printf("读取文件失败！请重新打开文件~\n");
        exit(0);
    }
    // 获取数据    
    int tempdata = 0,flag;   // flag用于判定读取文件的返回值
    do
    {
        // 定义临时的编译作为判定的结果
        flag = fscanf(fp,"%d ",&tempdata);        
        if(flag > 0)
        { 
            stack->top->data = tempdata;
            stack->top++;
            stack->size++;            
        }        
    } while (flag>0);
    fclose(fp);
}

BOOL StackIsEmpty(SeqStack* stack)
{
    if(stack->top == stack->base)
        return TRUE;
    return FALSE;
}

BOOL StackIsFull(SeqStack* stack)
{
    if(stack->top - stack->base == MAXSIZE)
        return TRUE;
    return FALSE;
}

int GetStackLength(SeqStack* stack)
{
    return stack->size;
}

void PushElemToStack(SeqStack* stack,Elem* elem)
{
    // stack->top = elem; // 指针的赋值
    // 这里选择用stack已经创建好的值
    stack->top->data = elem->data;
    stack->top++;
    stack->size++;
}

void PopElemFromStack(SeqStack* stack,Elem* elem)
{
    stack->top--;
    elem->data = stack->top->data;
    
    stack->size--;
}
void CreateElem(Elem* elem)
{
    printf("开始创建元素：\n");
    printf("请输入数据元素：");
    scanf("%d",&elem->data);
}

void DestroyStack(SeqStack* stack)
{
    if(stack->base)
    {
        free(stack->base);
        stack->base = stack->top = NULL;  
        stack->size = 0;      
    }
}

void PrintStack(SeqStack* stack)
{
    while (!StackIsEmpty(stack))
    {
        /* code */
        Elem elem;
        PopElemFromStack(stack,&elem);
        printf("%d   ",elem.data);
    }
    
}







