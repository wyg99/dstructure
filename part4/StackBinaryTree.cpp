/*
 * @Author: your name
 * @Date: 2021-08-28 17:41:24
 * @LastEditTime: 2021-11-30 21:34:49
 * @LastEditors: Please set LastEditors
 * @Description: 运用栈技术实现二叉树的相关的操作
 * @FilePath: \Dstructure\Part4\StackBinaryTree.cpp
 */
#include<iostream>
using namespace std;
/*
 *本程序采用链栈技术实现
 */

// 定义二叉树的结点结构
typedef struct BTreeNode
{
    /* data */
    char ch; // 数据域
    struct BTreeNode* lchild;
    struct BTreeNode* rchild;
}BTreeNode;


// 定义栈的结点空间
typedef struct BTStackNode
{
    /* data */
    BTreeNode node;
    int index; // 用于后续遍历访问控制，因为压栈两次
    struct BTStackNode* next;
}BTStackNode;

// 定义一个栈
typedef struct _stack
{
    /* data */
    int len; // 栈中元素的个数
    BTStackNode* top;    // 栈中存放的元素
}BTStack;



// 初始化栈空间
void InitStack(BTStack* &stack)
{
    stack->top = NULL;
    stack->len = 0;   // 栈中的元素的个数为0
}

// 判断栈是否为空
bool stackIsEmpty(BTStack* &stack)
{
    if(stack->len == 0)
        return true;
    return false;
}

// 栈不为空，返回栈中元素的个数
int numStackNode(BTStack* stack)
{
    return stack->len;
}

// 元素入栈
void pushStack(BTStack* &stack,BTStackNode* elem)
{
    elem->next = stack->top;
    stack->top = elem;
    stack->len++;
}
// 元素出栈
void popStack(BTStack* &stack,BTStackNode* &elem)
{
    if(!stackIsEmpty(stack))
    {
        elem->node = stack->top->node;
        elem->index = stack->top->index;
        BTStackNode* temp = stack->top;
        stack->top = stack->top->next;
        // BTStackNode* temp = stack->top;
        delete temp;      // 将出栈的元素的空间释放掉
        stack->len--;
        
    }
}

// 由二叉树结点构建链栈的一个栈元素
void initStackElem(BTStackNode* &node,BTreeNode* &elem)
{
    node->node = *elem;
    node->next = NULL;
}


// 将栈空间释放完
void ClearStack(BTStack* &stack)
{
    while (stack->len)
    {
        /* code */
        BTStackNode* temp = stack->top;
        stack->top = stack->top->next;
        delete temp;
        temp = NULL;
    }
}
// 从文件中读取数据，构建二叉树
void gToCreateBinaryTree(BTreeNode* &tree,FILE* fp)
{
    char ch; 
    if ((ch = fgetc(fp))== '#')
    {
        /* code */
        tree = NULL;
    }    
    else{
        /* code */
        tree = new BTreeNode();
        tree->ch = ch;
        tree->lchild = tree->rchild = NULL;
        gToCreateBinaryTree(tree->lchild,fp);
        gToCreateBinaryTree(tree->rchild,fp);
    }
}

// 销毁二叉树
int destroyBtree(BTreeNode* tree)
{
    if(tree == NULL)
    {
        return 0;
    }
    else{
        
        destroyBtree(tree->lchild);
        destroyBtree(tree->rchild);
        delete tree;
    }
    return 1;
}

int preOrderTraverse(BTreeNode* &tree)
{
    // 初始化一个栈
    BTStack* stack = new BTStack;
    InitStack(stack);
    BTreeNode* gTree = tree;  // 保留原值，防止操作修改值的大小
    BTStackNode* elem2 = new BTStackNode;
    while (gTree || !stackIsEmpty(stack))
    {
        /* code */
        if(gTree)
        {
            // 构建一个链栈空间的元素
            BTStackNode* elem1 = new BTStackNode;
            initStackElem(elem1,gTree);
            cout<<gTree->ch<<endl;
            elem1->index = 1;
            pushStack(stack,elem1);
            gTree = gTree->lchild;
        }            
        else{
            
            popStack(stack,elem2);
            
            gTree = elem2->node.rchild;
        }
    }
    // 最后销毁stack
    ClearStack(stack);
    delete elem2;
    return 1;
}
int inOrderTraverse(BTreeNode* &tree)
{
    // 初始化一个栈
    BTStack* stack = new BTStack;
    InitStack(stack);
    BTreeNode* gTree = tree;  // 保留原值，防止操作修改值的大小
    BTStackNode* elem2 = new BTStackNode;
    while (gTree || !stackIsEmpty(stack))
    {
        /* code */
        if(gTree)
        {
            // 构建一个链栈空间的元素
            BTStackNode* elem1 = new BTStackNode;
            initStackElem(elem1,gTree);
            
            pushStack(stack,elem1);
            gTree = gTree->lchild;
        }            
        else{
            
            popStack(stack,elem2);
            cout<<elem2->node.ch<<endl;
            gTree = elem2->node.rchild;
        }
    }
    // 最后销毁stack
    ClearStack(stack);
    delete elem2;
    return 1;
}
int postOrderTraverse(BTreeNode* &tree)
{
    // 初始化一个栈
    BTStack* stack = new BTStack;
    InitStack(stack);
    BTreeNode* gTree = tree;  // 保留原值，防止操作修改值的大小
    BTStackNode* elem2 = new BTStackNode;
    while (gTree || !stackIsEmpty(stack))
    {
        /* code */
        if(gTree)
        {
            // 构建一个链栈空间的元素
            BTStackNode* elem1 = new BTStackNode;
            initStackElem(elem1,gTree);
            elem1->index = 1;
            pushStack(stack,elem1);
            gTree = gTree->lchild;
        }            
        else{
            
            popStack(stack,elem2);
            if(elem2->index == 1)
            {
                BTStackNode* temp = new BTStackNode;
                //initStackElem(temp,(elem2->node));
                *temp = *elem2;
                temp->index++;
                pushStack(stack,temp);
                gTree = temp->node.rchild;
            }
            else if(elem2->index== 2)
            {
                cout<<elem2->node.ch<<endl;
            }

        }
    }
    // 最后销毁stack
    ClearStack(stack);
    delete elem2;
    return 1;
}
// 主函数
int main()
{
    const char* filePath = "BinTree.txt";
    FILE* fp = fopen(filePath,"r");
    BTreeNode* tree = NULL;
    gToCreateBinaryTree(tree,fp);
    
    // 前序遍历
    preOrderTraverse(tree);
        // 中序遍历
    //inOrderTraverse(tree);
    // 后续遍历
    // postOrderTraverse(tree);
    // destroyBtree(tree);
    fclose(fp);
    return 0;
}