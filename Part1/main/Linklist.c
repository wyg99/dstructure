/*
 * @Author: WEI-YUGUO
 * @Date: 2021-05-30 15:49:57
 * @LastEditTime: 2021-07-04 20:19:59
 * @LastEditors: Please set LastEditors
 * @Description: 单链表验证
 * @FilePath: \Program_\Datastructure\Part1\src\Linklist.c
 */

#include"..\include\Linklist.h"
int main()
{
    // 创建单链表
    LinkList list = gToCreateListHead();
    const char* filepath = "..\\data\\singlelistdata.txt";
    gToReadFile(filepath,list);
    
    gToPrintList(list);

    // gToClearLinkList(list); // 清空单链表

    // gToDeleteIndexDataOfLinkList(list,8); // 删除一个元素

    // LinkList node = gToCreateNodeOfLinkList();
    // gToInsertElem(list,node,3); // 在第i个位置前插入一个结点元素
    // gToInsertAtLinkListLast(list,node);
    
    // LinkList node = gToGeIndexDataOfLinkList(list,5);
    // gToPrintNode(node);
    // gToDeleteIndexDataOfLinkList(list,3); //删除单链表指定位置的结点
    // BubbleSortLinkList(list);
    // gToPrintList(list);
    // gToDestroyLinkList(list);


    NumberListPtr list1,list2;
    nlToCreateTwoLinkList(list1,list2);
    nlToPrintNumberLinkList(list1);
    return 0;
}