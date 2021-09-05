/*
 * @Author: your name
 * @Date: 2021-08-28 16:41:53
 * @LastEditTime: 2021-08-29 15:09:28
 * @LastEditors: Please set LastEditors
 * @Description: 二叉树递归实现
 * @FilePath: \Dstructure\Part4\BinaryTreeRecursion.cpp
 */
#include<iostream>
using namespace std;
// 定义二叉树的结点类型
typedef struct BinaryTreeRecursion
{
    /* data */
    char data;                               // 数据域
    struct BinaryTreeRecursion* lchild;     // 左子树
    struct BinaryTreeRecursion* rchild;     // 右子树
}BTreeNode;

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
        tree->data = ch;
        tree->lchild = tree->rchild = NULL;
        gToCreateBinaryTree(tree->lchild,fp);
        gToCreateBinaryTree(tree->rchild,fp);
    }
}

// 前序遍历
int preOrderTraverse(BTreeNode* tree)
{
    if(tree == NULL)
    {
        return 0;
    }
    else{
        cout<<tree->data<<endl;
        preOrderTraverse(tree->lchild);
        preOrderTraverse(tree->rchild);
    }
    return 1;
}

// 中序遍历
int inOrderTraverse(BTreeNode* tree)
{
    char ch;
    if(tree ==NULL)
    {
        return 0;
    }
    else
    {
        inOrderTraverse(tree->lchild);
        cout<<tree->data<<endl;
        inOrderTraverse(tree->rchild);
        
    }
    return 1;
    
}
// 后序遍历
int postOrderTraverse(BTreeNode* tree)
{
    if(tree ==NULL)
    {
        return 0;

    }
    else
    {
        postOrderTraverse(tree->lchild);
        postOrderTraverse(tree->rchild);
        cout<<tree->data<<endl;
    }
    return 1;
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


int main()
{
    const char* filePath = "BinTree.txt";
    FILE* fp = fopen(filePath,"r");
    BTreeNode* tree = NULL;
    gToCreateBinaryTree(tree,fp);
    cout<<"前序遍历:"<<endl;
    //preOrderTraverse(tree);
    
    cout<<"中序遍历:"<<endl;
    //inOrderTraverse(tree);

    cout<<"后序遍历:"<<endl;
    postOrderTraverse(tree);
    
    destroyBtree(tree);
    fclose(fp);
    return 0;
}
