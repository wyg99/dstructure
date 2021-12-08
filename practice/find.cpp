/*
 * @Author: your name
 * @Date: 2021-09-06 11:00:57
 * @LastEditTime: 2021-09-06 11:34:51
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Dstructure\practice\find.cpp
 */
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> result;
        for (int i = 0;i < nums.size();i++)
        {
            //int sum = 0;
            for (int j = i+1; j < nums.size(); j++)
            {
                /* code */
                if (nums[i] + nums[j] == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                }
            }
            
        }
        return result;
    }
    
};
int main()
{
    Solution m;
    vector<int> w = {2,7,11,15};
    vector<int> s = m.twoSum(w,9);
    return 0;
}