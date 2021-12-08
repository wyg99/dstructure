/*
 * @Author: your name
 * @Date: 2021-09-10 10:29:39
 * @LastEditTime: 2021-09-10 11:33:00
 * @LastEditors: Please set LastEditors
 * @Description: 插入排序
 * @FilePath: \Dstructure\tenSorts\insertSort.cpp
 */
#include<iostream>
#include<vector>
using namespace std;

class insertSort
{
private:
    /* data */
        vector<int> data = {9,5,6,8,2,7,3,4,1};

public:
    insertSort(/* args */);
    ~insertSort();
    void sort();
};
void insertSort::sort()
{
    int len = data.size();
    for(int i =0;i < len;i++)
    {
        int temp = data[i];
        int j =i-1;
        for(;(j >= 0) && (temp < data[j]);j=j-1)
        {
            
            data[j+1] = data[j];
            
        }
        data[j+1] = temp;
    }
    for(int i = 0;i <data.size();i++){
        cout<<data[i]<<endl;
    }
}
insertSort::insertSort(/* args */)
{
}

insertSort::~insertSort()
{
}

int main()
{
    insertSort m;
    m.sort();
    return 0;
}