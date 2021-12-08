/*
 * @Author: your name
 * @Date: 2021-10-17 19:00:41
 * @LastEditTime: 2021-10-20 19:23:46
 * @LastEditors: your name
 * @Description: In User Settings Edit（
 * @FilePath: \Dstructure\test11.cpp
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> A,B;
    int temp;
    scanf("%d",&temp);
    while(temp != '\n')
    {
        A.push_back(temp);
        scanf("%d",&temp);
    }
    scanf("%d",&temp);
    while(temp!='\n'){
        B.push_back(temp);
        scanf("%d",&temp);
    }
    sort(A.begin(),A.end());
    sort(B.begin(), B.end());
    int i = 0;
    if(A.size()!=B.size())cout<<"No";
    else {
        for(;i < A.size();i++)
        {
            if(A[i]!= B[i]){
                cout<<"No";
                break;
            }
        }
    }
    if(i == A.size())cout<<"Yes";
    return 0;
}