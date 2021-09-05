/*
 * @Author: your name
 * @Date: 2021-08-29 15:18:53
 * @LastEditTime: 2021-08-29 17:08:30
 * @LastEditors: Please set LastEditors
 * @Description: 二叉树的层次遍历
 * @FilePath: \Dstructure\part4\LevelOrderTraverse.cpp
 */


/*二叉树的层次遍历*/
#include<iostream>
using namespace std;
// 定义二叉树的结点类型
typedef struct LBTree
{
    /* data */
    char data;                               // 数据域
    struct LBTree* lchild;     // 左子树
    struct LBTree* rchild;     // 右子树
}LBTreeNode;

// 定义队列
typedef struct LQTreeElem // LinkQueueTree简写
{
    /* data */
    LBTreeNode node;
    struct LQTreeElem* next;
}LQTreeElem;

typedef struct _BQueue
{
    LQTreeElem* front;// 队头指针
    LQTreeElem* rear; // 队尾指针
    int len; // 队列中元素的个数
}_BQueue;

// 队列的初始化
void initQueue(_BQueue* &queue)
{
    queue = new _BQueue;   // new一个对象
    queue->front = queue->rear = new LQTreeElem;
    queue->len = 0; 
}

// 队列判断是否为空
bool isQueueEmpty(_BQueue* &queue)
{
    if(queue->len == 0)
        return true;
    return false;
}

// 元素入队
void enQueue(_BQueue* &queue,LQTreeElem* &elem)
{
    if(isQueueEmpty(queue))
    {
        initQueue(queue);
        queue->rear->node = elem->node;
        queue->rear->next = NULL;
    }
    else
    {
        //queue->rear->node = elem->node;
        elem->next = queue->rear->next;
        
        queue->rear->next = elem;
        queue->rear = elem;
        
    }
    queue->len++;
    
}

// 元素出队
void deQueue(_BQueue* &queue,LQTreeElem* &elem)
{
    if(!isQueueEmpty(queue))
    {
        LQTreeElem* temp = queue->front;
        elem->node = queue->front->node;
        queue->front = queue->front->next;
        free(temp);
        temp = NULL;
        queue->len--;
    }
    
}

// 创建二叉树
void gToCreateBinaryTree(LBTreeNode* &tree,FILE* fp)
{
    char ch; 
    if ((ch = fgetc(fp))== '#')
    {
        /* code */
        tree = NULL;
    }    
    else{
        /* code */
        tree = new LBTreeNode();
        tree->data = ch;
        tree->lchild = tree->rchild = NULL;
        gToCreateBinaryTree(tree->lchild,fp);
        gToCreateBinaryTree(tree->rchild,fp);
    }
}

// 将二叉树的元素建立一个队列中的元素
void initQueueElem(LQTreeElem* &node,LBTreeNode* &elem)
{
    node->node = *elem;
    node->next = NULL;
}
// 层析遍历
void LevelTraverse(LBTreeNode* &tree)
{
    // 初始化一个队列
    _BQueue* queue = NULL;
    initQueue(queue);
    // 运用二叉树的树根构造一个队列元素
    LQTreeElem* qNode = new LQTreeElem;
    // 将二叉树树根存入队列中
    initQueueElem(qNode,tree);
    // 元素入队列
    enQueue(queue,qNode);
    
    while (!isQueueEmpty(queue))
    {
        /* code */
        LQTreeElem* temp = new LQTreeElem;
        deQueue(queue,temp);
        cout<<temp->node.data<<endl;
        if(temp->node.lchild)
        {
            LQTreeElem* left_child = new LQTreeElem;
            // 将二叉树树根存入队列中
            initQueueElem(left_child,temp->node.lchild);
            // 元素入队列
            enQueue(queue,left_child);
        }
        if(temp->node.rchild)
        {
            LQTreeElem* right_child = new LQTreeElem;
            // 将二叉树树根存入队列中
            initQueueElem(right_child,temp->node.rchild);
            // 元素入队列
            enQueue(queue,right_child);
        }
        delete temp;
    }
    


    // 不管怎样，最后是要释放这个new的对象的
    delete queue;
}

// 销毁二叉树
int destroyBtree(LBTreeNode* tree)
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


int main()
{
    const char* filePath = "BinTree.txt";
    FILE* fp = fopen(filePath,"r");
    LBTreeNode* tree = NULL;
    gToCreateBinaryTree(tree,fp);     // 创建二叉树
    LevelTraverse(tree);     // 层次遍历二叉树
    destroyBtree(tree);
    fclose(fp);
    printf("\n程序成功执行!");
    return 0;
}

