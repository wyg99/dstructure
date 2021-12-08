/*
 * @Author: your name
 * @Date: 2021-09-11 10:16:18
 * @LastEditTime: 2021-09-21 22:50:03
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Dstructure\tenSorts\test.cpp
 */
// /*
//  * @Author: your name
//  * @Date: 2021-09-11 10:16:18
//  * @LastEditTime: 2021-09-11 11:14:28
//  * @LastEditors: Please set LastEditors
//  * @Description: In User Settings Edit
//  * @FilePath: \Dstructure\tenSorts\test.cpp
//  */

// #include<iostream>
// #include<vector>
// using namespace std;
// class solution{
//     public:
//     vector<string> str_s;
//     solution();
//     ~solution();
//     void cheak();
// };
// void solution::cheak()
// {    
//     int len = str_s.size();
//     for(int i = 0;i < len;i++)// 对每一行进行遍历
//     {
//         // 对第一种情况进行检查
//         string temp = str_s[i];
//         for(int j = 0;j < temp.length()-2;j++)
//         {
//             if(temp[j] == temp[j+1] && temp[j+1] ==temp[j+2])
//             {
//                 temp.erase(j,1);
//             }
//         }
        
//         //temp = str_s[i];
//         for(int j = 0;j < temp.length()-3;j++)
//         {
//             if(temp[j] == temp[j+1] && temp[j+2] == temp[j+3])
//             {
//                 temp.erase(j+2,1);
//             }
//         }
//         for(int j = 0;j < temp.length()-2;j++)
//         {
//             if(temp[j] == temp[j+1] && temp[j+1] ==temp[j+2])
//             {
//                 temp.erase(j,1);
//             }
//         }
//         str_s[i] = temp;
        
//     }
    
// }
// solution::solution()
// {
// }
// solution::~solution()
// {
// }
// int main()
// {
//     // 申请一个个对象
//     solution sol;
//     int NUMS;
//     cin>>NUMS;
//     string str;
//     for(int i = 0;i < NUMS;i++)
//     {
//         cin>>str;
//         sol.str_s.push_back(str);
//         ///cout<<str<<endl;   
//     }
//     sol.cheak();
//     return 0;
// }

// #include<iostream>
// #include<vector>
// using namespace std;
// class solution{
//     public:
//     vector<int> like;
//     vector<int>ret;
//     solution();
//     ~solution();
//     void Find(int l,int r,int k);
// };
// void solution::Find(int l,int r,int k)
// {
//     int Left = l-1;
//     int Right = r-1;
//     int num = 0;
//     for(int i =Left;i <= Right;i++)
//     {
//         if(like[i] == k)
//                num++;
//     }
//     ret.push_back(num);
//     //cout<<num;
// }
// solution::solution(){
    
// }
// solution::~solution()
// {
    
// }
// int main()
// {
//     solution sol;
//     int n; // n代表用户数目
//     cin>>n;
//     int likeNumber;
//     for(int i= 0;i <n;i++)
//     {
//         cin>>likeNumber;
//         sol.like.push_back(likeNumber);
//     }
//     int q;
//     cin>>q;
//     while(q>0)
//     {
//         int l,r,k;
//         //for(int j = 0;j < q;j++)
//         {
//             cin>>l>>r>>k;
//         }
//         sol.Find(l,r,k);
        
        
//         q--;
//     }
//     for(int i = 0;i < sol.ret.size();i++)
//     {
//         cout<<sol.ret[i];
//     }
//     return 0;
// }
// #include<iostream>
// #include<vector>
// using namespace std;
// class solution{
//     public:
//     int n,m,c;
//     vector<vector<int>> color;
//     solution();
//     ~solution();
// };
// solution::solution()
// {
    
// }
// solution::~solution()
// {
    
// }
// int main()
// {
//     solution sol;
//     // 输入nmc数据
//     cin>>sol.n>>sol.m>>sol.c;
//     // 便利了循环
//     int temp;
    
//     for(int i =0;i < sol.n;i++)
//     {
//         cin>>temp;
//         sol.color[i].push_back(temp);
//         for(int k = 0;k < temp;k++)
//         {
//             cin>>temp;
//             sol.color[i].push_back(temp);

//         }
        
//     }
//     return 0;
// }

// #include<iostream>
// #include<vector>
// using namespace std;

// #include<iostream>
// #include<vector>
// using namespace std;
// int main()
// {
//     int n;
//     cin>>n;
//     vector<vector<int>> arr(n);
//     for(int i = 0;i < n;i++)
//     {
//         int X,H;
//         cin>>X>>H;
//         arr[i].push_back(X);
//         arr[i].push_back(H);
//         // 存入该宝物的总数
//         arr[i].push_back(X+H);
//     }
//     // 进行排序
//     for(int i = 0;i < n;i++)
//     {
//         for(int j = 0;j < n-i-1;j++)
//         {
//             if(arr[j][2]>arr[j+1][2])
//             {
//                 vector<int> temp;
//                 temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//         }
//     }
//     // 从最低位置开始找
//     int sum = 1;
//     int xmin = 99999,hmin = 999999;
//     for(int i = 1;i < n;i++)
//     {
//         if(arr[i][0] >= arr[i-1][0] && arr[i][1] >= arr[i-1][1])
//             sum++;
//     }
//     cout <<sum;
    
//     return 0;
    
// }

// #include<iostream>
// #include<vector>
// using namespace std;
// bool choose(int i,int tar)
// {
//     int sum = 0,k,n = i;
//     while(n)
//     {
//         k = n%10;
//         sum = sum+k;
//         n = n /10;
//     }
//     if(tar == sum)
//         return true;
//     return false;
// }
// int main()
// {
//     int n;
//     cin>>n;
//     int max = 1000;
//     vector<int> arr;
//     for(int i= 1;i < max;i++)
//     {
//         if(choose(i,n))
//             arr.push_back(i);
        
//     }
//     if(arr.empty()) cout<<-1;
//     else{
//         cout<<arr[0];
//     }
//     return 0;
// // }
// #include<iostream>
// #include<vector>
// using namespace std;

// int find(int N,vector<int> Ai,int M)
// {
//     vector<int> temp;
//     int ret = 0;

//     // 不同区间的遍历，共有N个不同的区间长度
//     for(int i = 1;i <= N;i++)
//     {
//         int len = i;
        
//         for(int j =0;j + len <= N;j++)
//         {
//             int sum = 0;
//             for(int k = j;k < j + len;k++)
//             {
//                 sum+=Ai[k];
//             }
//             if(sum%M == 0)
//                 ret++;
//         }
        
//     }
//     return ret;
// }
// int main()
// {
//     int N,M;
//     vector<int> Ai;
//     cin>>N>>M;
//     int temp;
//     for(int i = 0;i < N;i++)
//     {
//         cin>>temp;
//         Ai.push_back(temp);
//     }
//     int ret = find(N,Ai,M);
//     cout<<ret;
    
//     return 0;
// }





// class Solution {
// public:
//     int myAtoi(string str) {

//         int flag = 1;
//         int i = 0;
//         int len = str.length();
//         while(str[i] == ' '){

//             i++;
//         }
//         if(len == i || (!isdigit(str[i]) && str[i] != '+' && str[i] != '-')){

//             return 0;
//         }
         
//         if(str[i] == '-' || str[i] == '+'){  
         
//             if(str[i] == '-'){

//                 flag = -1;
//             }
//             i++;   
//         }
//         long num = 0;
//         while(i<len && isdigit(str[i])){

//             num = num*10+(str[i]-'0');
//             i++;
//             if(num > INT_MAX && flag == 1)
//                 return INT_MAX;
//             if(num >INT_MAX && flag == -1)
//                 return INT_MIN; 
//         }
//         return num*flag;
//     }
// };



// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;

// int main()
// {
//     int n,x,y;
//     vector<int> score;
//     cin>>n>>x>>y;
//     int sco = 0;
//     for(int i = 0;i < n;i++)
//     {
//         cin>>sco;
//         score.push_back(sco);       
//     }
//     // 将分数进行排序
//     sort(score.begin(),score.end());
    
//     vector<int> ret;
//     for(int i =0;i < score.size();i++)
//     {
//         int min_num = 0,max_num = 0;
//         int index = score[i];
//         for(int j = 0;j < score.size();j++)
//         {
//             if(score[j] <  index)
//             {
//                 min_num++;
//             }
//             if(score[j] > index)
//             {
//                 max_num++;
//             }
//         }
//         if((min_num>=x&&min_num<=y)&&(max_num>=x&&max_num<=y))
//             ret.push_back(index);
        
//     }
//     sort(ret.begin(),ret.end());
//     if(ret.empty())
//         cout<< -1;
//     else
//         cout<<ret[0];
//     return 0;
// }


// class Solution {
// public:
//     vector<string> ret;
//     bool boolIs(string s)
//     {
//         for(int i = 0;i <s.length()/2;i++)
//         {
//             if(s[i]!=s[s.length()-1-i])return false;

//         }
//         return true;
//     }
//     string longestPalindrome(string s) {
//         // 将字符串每一个开始的字符的不同长度的字符串进行逐一的判断
//         int len =s.length();
//         for(int i = 0;i < len;i++)
//         {
//             string temp;
//             for(int j = i;j < len;j++)
//             {
//                 temp = temp+s[j];
//                 if(boolIs(temp)){
//                     ret.push_back(temp);
//                 }

//             }
//         }
//         //对ret中的数据进行遍历
//         int index;
//         int max = -1;
//         for(int i = 0;i < ret.size();i++)
//         {
//             if(ret[i].length()>max)
//             {
//                 max = ret[i].length();
//                 index = i;
//             }
//         }
//         return ret[index];
        

//     }
// };

// #include<iostream>
// #include<vector>
// #define MAX 1000
// using namespace std;
// int getSum(int n)
// {
//     int sum = 0;
    
//     while(n)
//     {
//         sum = sum+n%10;
//         n = n/10;
//     }
//     return sum;
// }
// int main()
// {
//     int N;
//     cin>>N;
//     for(int i = 0;i < MAX;i++)
//     {
//         if(getSum(i) == N)
//         {
//             cout<<i<<"   ";
//         }
//     }
//     return 0;
// }
// #include<iostream>
// #include<vector>
// using namespace std;
// int main()
// {
//     int N,M;
//     cin>>N>>M;
//     vector<int> Ai;
//     int num;
//     for(int i = 0;i < N;i++)
//     {
//         cin>>num;
//         Ai.push_back(num);
//     }
//     int ans = 0;
//     // 表示不同长度的区间
//     for(int i =1;i <=N;i++)
//     {
//         for(int j =0;j < N;j++)
//         {
//             int sum = 0;
//             for(int k = j;(k < i + j) && (i+j <= N);k++) // 临界条件有点问题
//             {
//                 sum = sum + Ai[k];
                
//             }
//             if(sum%M == 0 && sum!=0)
//                 ans++;
//         }
        
//     }
//     cout<<ans;
//     return 0;
// }


// class Solution {
// public:
//     bool isValid(string s) {
//         int n = s.size();
//         if (n % 2 == 1) {
//             return false;
//         }

//         unordered_map<char, char> pairs = {
//             {')', '('},
//             {']', '['},
//             {'}', '{'}
//         };
//         stack<char> stk;
//         for (char ch: s) {
//             if (pairs.count(ch)) {
//                 if (stk.empty() || stk.top() != pairs[ch]) {
//                     return false;
//                 }
//                 stk.pop();
//             }
//             else {
//                 stk.push(ch);
//             }
//         }
//         return stk.empty();
//     }
// };

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/valid-parentheses/solution/you-xiao-de-gua-hao-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         ListNode* preHead = new ListNode(-1);

//         ListNode* prev = preHead;
//         while (l1 != nullptr && l2 != nullptr) {
//             if (l1->val < l2->val) {
//                 prev->next = l1;
//                 l1 = l1->next;
//             } else {
//                 prev->next = l2;
//                 l2 = l2->next;
//             }
//             prev = prev->next;
//         }

//         // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
//         prev->next = l1 == nullptr ? l2 : l1;

//         return preHead->next;
//     }
// };

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/merge-two-sorted-lists/solution/he-bing-liang-ge-you-xu-lian-biao-by-leetcode-solu/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。



// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         ListNode* dummyHead = new ListNode(0);
//         dummyHead->next = head;
//         ListNode* temp = dummyHead;
//         while (temp->next != nullptr && temp->next->next != nullptr) {
//             ListNode* node1 = temp->next;
//             ListNode* node2 = temp->next->next;
//             temp->next = node2;
//             node1->next = node2->next;
//             node2->next = node1;
//             temp = node1;
//         }
//         return dummyHead->next;
//     }
// };


// lass Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         int i = nums.size() - 2;
//         while (i >= 0 && nums[i] >= nums[i + 1]) {
//             i--;
//         }
//         if (i >= 0) {
//             int j = nums.size() - 1;
//             while (j >= 0 && nums[i] >= nums[j]) {
//                 j--;
//             }
//             swap(nums[i], nums[j]);
//         }
//         reverse(nums.begin() + i + 1, nums.end());
//     }
// };

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/next-permutation/solution/xia-yi-ge-pai-lie-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// #include<iostream>
// using namespace std;
// int getAnswer(int n)
// {
//     int flag = 1;
//     int sum= 0;
//     for(int i = 1;i <=n;i++ )
//     {
//         sum = sum+flag*i;
//         flag = -flag;
//     }
//     return sum;
// }
// int main()
// {
//     char n = '9';
//     // cin>>n;
//     // int sum = getAnswer(n);
//     cout<<(int)n;
//     return 0;
// }

#include<iostream>
#include<vector>
using namespace std;
int getAns(int n)
{
    return n/2 + 1;
}
int main()
{
    int n;// 表示有有多少组数字
    vector<int> num;
    cin>>n;
    int temp = 0;
    for(int i = 0; i< n;i++)
    {
        cin>>temp;
        num.push_back(temp);
       
    }
    for(int  i = 0;i < n;i++){
        num[i] = getAns(num[i]);
        cout<<num[i]<<"\n";
    }
    
    return 0;
}





