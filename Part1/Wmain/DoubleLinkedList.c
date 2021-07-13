/*
 * @Author: WEI-YICHEN
 * @Date: 2021-07-08 17:57:20
 * @LastEditTime: 2021-07-08 21:25:32
 * @LastEditors: Please set LastEditors
 * @Description: 双向链表的主函数
 * @FilePath: \Dstructure\Part1\Wmain\DoubleLinkedList.c
 */

#include "DoubleLinkedList.h"
int main()
{
    DoubLinkList list= initDoubleLinkList();               // 初始化循环链表
    const char* filePath = "../data/doubleLinkedList.txt"; 
    GtoReadFile(filePath,list);                            // 读取文件中的数据
    GtoPrintDoubleLinkedList(list);                        // 打印双向循环链表的信息
    struct Elem* elem =  GtoFindElemByIndex(list,3);       // 创建一个Elem结点
    GtoPrintDoubleLinkedListNode(elem);                    // 打印结点中的数据信息
    DoubLinkList node = GtoCreateLintNodeByTerminal();     // 创建双向链表的结点
    GtoInsertLinkedListNodeBeforeIndex(list,2,node);       // 在索引值前面插入一个结点元素
    GtoPrintDoubleLinkedList(list);                        // 打印双向循环链表的信息
    GtoDeleteDoubleLinkedList(list);                       // 销毁双向循环链表
    return 0;
}


