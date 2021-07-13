/*
 * @Author: WEI-YICHEN
 * @Date: 2021-05-16 13:54:54
 * @LastEditTime: 2021-07-04 20:09:10
 * @LastEditors: Please set LastEditors
 * @Description: 线性表顺序链表的相关操作程序
 * @FilePath: \Program_\Datastructure\Part1\src\SeqListMain.c
 */
#include"..\\include\\SeqList.h"
int main()
{
    //创建顺序链表
    SeqListNode* SeqNode =  SEQ_gToCreateSequentialList();
    const char* FilePath = "..\\data\\StudentInformation.txt";  
    SEQ_gToReadFileData(FilePath,SeqNode);// 顺序链表中存入数据
    
    // SEQ_gToDeleteNode(SeqNode,12);  // 对顺序链表进行删除操作

    // float sco[3] = {23,34,56};
    // SeqListNodeData m = {20,"ncjd",sco};
    // SEQ_gToInsertAtHead(SeqNode,m);
    // SEQ_gToInsertAtLast(SeqNode,m);
    // SEQ_gToInsertAtLocation(SeqNode,m,2);  // 对顺序链表的插入操作
    
    // SEQ_gToSort(SeqNode);  // 对顺序链表进行排序
    // SeqListNodeData* tar = SEQ_gToFindByIndex(SeqNode,2); // 按照游标进行查找
    // SEQ_gToPrintNode(tar);  // 打印顺序链表的结点信息
    
    // int index = SEQ_gToFindByInformation(SeqNode,3);
    // printf("%d",index);
    SEQ_gToPrint(SeqNode);
    SEQ_gToFreeSpace(SeqNode);
    return 0;
}