/*
 * @Author: your name
 * @Date: 2021-07-06 14:11:02
 * @LastEditTime: 2021-07-12 16:14:47
 * @LastEditors: Please set LastEditors
 * @Description: 循环单链表的主函数
 * @FilePath: \datastructure\Part1\main\CircleLinkList.c
 */

// 进行验证
#include"CircularLinkList.h"
int main()
{
    CirLinkList list = wToInitCircleLinkList();
    const char* filePath = "../data/singlelistdata.txt";
    list = wToReadFile(filePath,list);
    
    // int len = wToGetLength(list);   // 求解循环单链表的元素的个数
    // CirLinkList pNode = wToCreateNode();
    // wToInsertListNode(list,5,pNode);
    // wToFreeLinkListNode(list,3);
    wToPrintCircularLinkList(list);    // 打印输出循环单链表
    
    //Elem* elem = wToGetElem(list,7);
    // Elem elem;
    // wToFindElem(list,8,&elem);
    // wToPrintNodeElem(&elem);
    
    wToDeleteLinkList(list);           // 销毁循环单链表
    return 0;
} 