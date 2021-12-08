/*
 * @Author: your name
 * @Date: 2021-09-10 16:07:41
 * @LastEditTime: 2021-09-27 18:23:51
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Dstructure\tenSorts\heapSort.cpp
 */
#include<iostream>
#include<vector>
using namespace std;
#
class heapSort
{
public:
    /* data */
    vector<int> data = {4,5,1,6,2,7,3,8};
public:
    heapSort(/* args */);
    ~heapSort();

    void sort();
    void heapChange(int parent);
};

void heapSort::heapChange(int parent)
{
    if(parent >= data.size())return;
    int lch = parent*2+1;
    int rch = parent*2+2;
    int max = parent;
    if(lch < data.size() && data[lch]>data[max])
        max = lch;
    if(rch < data.size() && data[rch]>data[max])
        max = rch;
    // 进行交换
    if(max != parent)
    {
        int temp = data[parent];
        data[parent] = data[max];
        data[max] = temp;
        heapChange(max);
    }
    
}
void heapSort::sort()
{
    // 首先建立一个堆
    int last_node = data.size()-1;
    int parent = (last_node-1)/2;
    for(int i = parent;i >=0;i--)
    {
        //对parent结点进行交换操作
        heapChange(i);
    }
    for(int i = data.size()-1;i>=0;i--){
        // 交换树的根结点和最后一个结点
        int temp = data[i];
        data[i] = data[0];
        data[0] = temp;
        cout<<data[i]<<endl;
        data.pop_back();
        heapChange(0);
    }
}
heapSort::heapSort(/* args */)
{
}

heapSort::~heapSort()
{
}
int main()
{
    heapSort m;
    m.sort();

    for(int i = 0;i < m.data.size();i++)
    {
        cout<<m.data[i]<<endl;
    }
    return 0;
}