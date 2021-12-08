/*
 * @Author: your name
 * @Date: 2021-09-10 10:04:57
 * @LastEditTime: 2021-09-10 10:11:40
 * @LastEditors: Please set LastEditors
 * @Description: 本程序为冒泡排序
 * @FilePath: \Dstructure\tenSorts\bubbleSort.cpp
 */
#include<iostream>
#include<vector>
using namespace std;

// 定义类
class bubbleSort
{
private:
    /* data */
    vector<int> data = {9,5,6,8,2,7,3,4,1};
public:
    bubbleSort(/* args */);
    
    ~bubbleSort();
    // 进行排序操作
    void sort();
};

bubbleSort::bubbleSort(/* args */)
{
}

bubbleSort::~bubbleSort()
{
}

void bubbleSort::sort()
{
    int temp;
    int len = data.size();
    for (int i = 0 ;i < len;i++)
    {
        for (int j = 0;j < len - i-1;j++)
        {
            if(data[j] > data[j+1])
            {
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
    for(int i = 0; i <len;i++)
    {
        cout<<data[i]<<endl;
    }

}
int main()
{
    bubbleSort pro;
    pro.sort();
    return 0;
}