/*
 * @Author: your name
 * @Date: 2021-09-10 10:17:02
 * @LastEditTime: 2021-09-10 10:28:21
 * @LastEditors: Please set LastEditors
 * @Description: 选择排序
 * @FilePath: \Dstructure\tenSorts\selectSort.cpp
 */
#include<iostream>
#include<vector>
using namespace std;

class selectSort
{
private:
    vector<int> data = {9,5,6,8,2,7,3,4,1};
public:
    selectSort(/* args */);
    ~selectSort();
    void sort();

};
void selectSort::sort()
{
    int len  = data.size();
    int temp = 0;
    for (int i =0;i < len;i++)
    {
        int minIndex = i;    // 将开始的数作为比较的数
        for(int j = i+1;j < len;j++)
        {
            if(data[j] < data[minIndex])
            {
                minIndex = j;
            }
        }
        temp = data[i];
        data[i] = data[minIndex];
        data[minIndex] = temp;
    }
    for(int i = 0;i < len;i++)
    {
        cout<<data[i]<<endl;
    }

}
selectSort::selectSort(/* args */)
{
}

selectSort::~selectSort()
{
}
int main()
{
    selectSort m;m.sort();
    return 0;
}


// 首先将第一个数作为比较的对象
/* 在后面的数中依次找出最小的数与前面最后一个数进行交换*/