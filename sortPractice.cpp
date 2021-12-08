/*
 * @Author: your name
 * @Date: 2021-10-14 14:04:54
 * @LastEditTime: 2021-10-14 15:51:18
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Dstructure\sortPractice.cpp
 */
#include<iostream>
#include<vector>
using namespace std;

class sortMethods
{
private:
    /* data */
    vector<int> num = {1,9,8,8,65,89,7};
public:
    
    sortMethods(/* args */);
    // 冒泡排序
    void bubbleSort();

    // 选择排序
    void selectSort();

    // 插入排序
    void insertSort();

    //归并排序
    void mergSort();
    //打印结果
    void print()
    {
        for(int i = 0;i <num.size();i++)
        {
            cout<<num[i]<<" ";
        }
        cout<<"\n"<<endl;
    }
    ~sortMethods();
};
void sortMethods::mergSort()
{
    
}
void sortMethods::insertSort()
{
    int size = num.size();
    for(int i = 1;i < size;i++)
    {
        int key = num[i];
        int j;   // 用于数组的移动
        for(j = i-1;j >=0 && key < num[j];j--)        
        {
            num[j+1] = num[j];            
        }
        num[j +1 ] = key;
        
    }
    
}
void sortMethods::selectSort()
{
    int size = num.size();
    for(int i = 0;i < size;i++)
    {
        // 找到最小数所在的下标
        int min = i;
        for(int j = i+1;j < size;j++)
        {
            if(num[j] < num[min])
                min = j;

        }
        // 找到了最小的数
        int exChange = num[i];
        num[i] = num[min];
        num[min] = exChange;
    }
}
void sortMethods::bubbleSort()
{
    int size = num.size();
    int enChange = 0;
    for(int i = 0;i  < num.size();i++)
    {
        for(int j = 0;j < size-i-1;j++)
        {
            if(num[j+1] > num[j])
            {
                enChange = num[j+1];
                num[j+1] = num[j];
                num[j] = enChange;
            }
        }
    }
}
sortMethods::sortMethods(/* args */)
{
}

sortMethods::~sortMethods()
{
}
int main()
{
    sortMethods ft;
    //ft.bubbleSort();
    // ft.selectSort();
    ft.insertSort();




    ft.print();
    return  0;
}
