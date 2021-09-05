/*
 * @Author: your name
 * @Date: 2021-09-05 19:33:14
 * @LastEditTime: 2021-09-05 22:45:17
 * @LastEditors: Please set LastEditors
 * @Description: 排序的相关操作
 * @FilePath: \Dstructure\part6\sort.cpp
 */
#include<iostream>
using namespace std;
#define MAXNUMBER 8
class SortObjection
{
private:
    int data[MAXNUMBER] = {49,38,65,97,76,13,27,49};
public:
    SortObjection(/* args */);
    ~SortObjection();

    // 打印排序后的结果
    void print();
    // 直接插入排序
    void InsertSort();
    // 起泡排序
    void BubbleSort();

    // 快速排序
    void QuickSort(int low,int high);
    // 选择排序
    void SelectSort();
    // 堆排序
    void heapSort();
    // 构建堆
    void siftHeap(int low,int high);
};
void SortObjection::print()
{
    printf("排序后的结果为：\n");
    for (int i =0;i<MAXNUMBER;i++)
    {
        printf("%d   ",data[i]);
    }
}
SortObjection::SortObjection(/* args */)
{

}

SortObjection::~SortObjection()
{
}
void SortObjection::InsertSort()
{
    for (int i = 0;i < MAXNUMBER;i++)
    {
        int temp = data[i];
        int j = i-1;
        while (j>=0 && temp<data[j])
        {
            /* code */
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = temp;
        
    }

}

void SortObjection::BubbleSort()
{
    for (int i = 0;i <MAXNUMBER;i++)
    {
        for(int j= 0 ;j < MAXNUMBER-i;j++)
        {
            if(data[j] > data[j+1])
            {
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}
void SortObjection::QuickSort(int low,int high)
{
    
    int i = low,j = high;
    if (low < high)
    {
        /* code */
        // 定义标志位
        int temp = data[low];
        while (i< j)
        {
            /* code */
            while (j > i && data[j] >= temp)   // 从右王左扫描
            {
                /* code */
                j--;
            }
            // 找到了比temp小的数
            if(i < j)
            {
                data[i] = data[j];
                ++i;

            }
            while (j > i && data[i] < temp)
            {
                /* code */
                i++;
            }
            if(i < j)
            {
                data[j] = data[i];
                --j;
            }
            
            
        }
        data[i] = temp;
        QuickSort(low,i-1);
        QuickSort(j+1,high);        
        

    }
    
}

void SortObjection::SelectSort()
{
    for(int i = 0; i< MAXNUMBER;i++)
    {
        //int temp = data[i];
        int index = i;
        // 在剩下的元素中中找到最小的
        for(int j = i+1;j <MAXNUMBER;j++)
        {
            if(data[index] > data[j])
            {
                index = j;

            }
        }
        // 将找到的最小元素加入到有序表中去
        int temp = data[i];
        data[i] = data[index];
        data[index] = temp;
    }
    

}
void SortObjection::heapSort()
{
    for (int i = MAXNUMBER/2-1;i>=0;i--)
    {
        siftHeap(i,7);
    }
    int temp;
    // 接下来进行n-1次循环，构建堆排序
    for(int i = MAXNUMBER-1;i >= 1;--i)
    {
        temp = data[0];
        data[0] = data[i];
        data[i] = temp;
        siftHeap(0,i-1);
    }
}
void SortObjection::siftHeap(int low,int high)
{
    int i = low,j = 2*i+1;
    int temp = data[i];
    while (j <= high)
    {
        /* code */
        if(j <high && data[j] < data[j+1])   // 也就是右孩子较大的情况下
        {
            ++j; // j改变为2*i+2
        }
        if(temp<data[j])
        {
            data[i] = data[j];
            i = j;// 修改i和j的位置，使其能够继续向下移动
            j = i*2+1;
        }
        else
        {
            break;
        }
        
    }
    data[i] = temp;
    

}



int main()
{
    SortObjection obj;
    //obj.InsertSort();
    // obj.BubbleSort();
    // obj.QuickSort(0,MAXNUMBER-1);
    // obj.SelectSort();
    obj.heapSort();   // 掌握的不是很熟练
    obj.print();
    return 0;
}


