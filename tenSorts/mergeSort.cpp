/*
 * @Author: your name
 * @Date: 2021-09-10 14:59:05
 * @LastEditTime: 2021-09-10 15:18:22
 * @LastEditors: Please set LastEditors
 * @Description: 归并排序
 * @FilePath: \Dstructure\tenSorts\mergeSort.cpp
 */
#include<iostream>
#include<vector>
using namespace std;

class mergeSort
{
public:
    /* data */
    vector<int> data = {9,5,6,8,2,7,3,4,1};

public:
    mergeSort(/* args */);
    ~mergeSort();
    void sort(int left,int right);
    void mergeCore(int L,int Q,int R);
};
void mergeSort::mergeCore(int L,int Q,int R){
    int n = R-L+1;
    int *temp = new int[n];
    int i =0;
    int left =L;
    int right = Q+1;
    while (left <=Q &&right <=R)
    {
        /* code */
        temp[i++] = data[left]<=data[right]?data[left++]:data[right++];
        while (left <= Q)
        {
            /* code */
            temp[i++] = data[left++];
        }
        while (right<=R)
        {
            /* code */
            temp[i++] = data[right++];
        }
        for(int j = 0;j < n;j++)
        {
            data[L+j] = temp[j];
        }
        delete []temp;
        
        
    }
    
}
void mergeSort::sort(int left,int right)
{
    if(left == right){
        return;
    }
    int q = (left+right)/2;
    sort(left,q);
    sort(q+1,right);
    mergeCore(left,q,right);

}
mergeSort::mergeSort(/* args */)
{
}

mergeSort::~mergeSort()
{
}

int main()
{
    mergeSort m;
    m.sort(0,8);
    for(int i = 0;i <m.data.size();i++)
    {
        cout<<m.data[i]<<endl;
    }
    return 0;
}