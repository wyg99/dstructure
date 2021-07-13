/*
 * @Author: your name
 * @Date: 2021-07-11 08:32:27
 * @LastEditTime: 2021-07-11 17:49:04
 * @LastEditors: Please set LastEditors
 * @Description: Programe about DOUBLE CIRCULAR LINKEDLIST
 * @FilePath: \Dstructure\Part1\include\doubleCircularList.h
 */

struct Elem
{
    int data;
};


typedef struct DoubleCircularList
{
    struct Elem elem;
    struct DoubleCircularList* next;
    st
}dcListNode,*dcList;

// 初始化双向循环链表
