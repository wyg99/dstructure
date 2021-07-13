/*
 * @Author: your name
 * @Date: 2021-07-12 22:52:36
 * @LastEditTime: 2021-07-13 17:13:51
 * @LastEditors: Please set LastEditors
 * @Description: 链栈.C文件
 * @FilePath: \Dstructure\Part2\src\linkStack.c
 */
#include"linkStack.h"

void initLinkStack(LinkStack* stack)
{
    stack->len = 0;
    stack->top = NULL;
}
void ReadFileCreateStack(const char* filePath,LinkStack* stack)
{
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
            // 创建结点空间
            Elem* elem = (Elem*)malloc(sizeof(Elem));
            if(elem == NULL)
            {
                printf("开辟空间失败！请重新开辟空间~\n");
                exit(0);
            }
            elem->data = tempdata;
            elem->next = NULL;
            // 将数据压栈
            pushStack(stack,elem);
        }        
    } while (flag>0);
    fclose(fp);
}
void pushStack(LinkStack* stack,Elem* elem)
{
    // 运用指针
    elem->next = stack->top;
    //stack->top/*->next*/ = elem;
    stack->top = elem;
    stack->len++;
}

void popStack(LinkStack* stack,Elem* elem)
{
    if(!LinkStackIsEmpty(stack))
    {
        elem->data = stack->top->data;
        stack->top = stack->top->next;
        stack->len--;
    }
}
void PrintStack(LinkStack* stack)
{
    while (!LinkStackIsEmpty(stack))
    {
        /* code */
        Elem temp;
        popStack(stack,&temp);
        printf("%d ",temp.data);
    }   
}



BOOL LinkStackIsEmpty(LinkStack* stack)
{
    if(stack->len == 0)
        return TRUE;
    return FALSE;
}
int GetLen(LinkStack* stack)
{
    return stack->len;
}

void Destroy(LinkStack* stack)
{
    while (stack->top)
    {
        /* code */
        Elem* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
        temp = NULL;
    }
    
}


void createNodeFromTerminal(Elem* elem)
{
    printf("开始创建结点的数据：\n请输入数据：");
    scanf("%d",&elem->data);
    elem->next = NULL;
}


