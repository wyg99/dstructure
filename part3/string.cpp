/*
 * @Author: your name
 * @Date: 2021-08-27 23:15:04
 * @LastEditTime: 2021-08-28 01:08:36
 * @LastEditors: Please set LastEditors
 * @Description: 串的相关操作
 * @FilePath: \Dstructure\partt3\string.cpp
 */

/*
 * 本程序为实现串的2种匹配算法
 */

#include"stdlib.h"
#include"stdio.h"
#include"string.h"
#define MAXLEN 50
// 定义串的结构
typedef struct SString
{
    /* data */
    char ch[MAXLEN];   // 串的顺序存储表示
    int length;     // 保留串的长度
}SString;

// 目标串 P_str
// 模式串 T_str
// 设定的位置
int _BF_Algorithm(SString P_str,SString T_str,int pos)
{
    int i = pos,j = 0;
    while ( i < P_str.length && j < T_str.length)
    {
        /* code */
        if( P_str.ch[i] == T_str.ch[j])
        {
            i++;
            j++;
        }
        else{
            i = i - j + 1;
            j = 0;
        }
    }
    if ( j >= T_str.length)
        return i - j;
    else
        return 0;
}

// 求解next数组
void get_Next(SString str,int array[])
{
    int j = 0,k = -1;
    array[0] = -1;
    while (j < str.length - 1)
    {
        /* code */
        if(k == -1 || str.ch[j] == str.ch[k])
        {
            j++;
            k++;
            array[j] = k;
        }
        else
            k = array[k];
    }
}

// KMP算法
int _KMP_algorithm(SString P_str,SString T_str,int pos)
{
    int _next[20];
    get_Next(T_str,_next); // 求解next数组
    int i = pos, j = 0;
    while (i < P_str.length &&j<T_str.length)
    {
        if(j == -1 || P_str.ch[i] == T_str.ch[j])
        {
            ++i;++j;
        }
        else 
            j  = _next[j];
        }
    if(j >= T_str.length)
        return  i - j;
    else
        return 0;
    

}


int main()
{
    char p[] = {'a','b','c','d','e','f','\0'};
    char q[] = {'c','d','e','\0'};
    SString T_str;
    SString P_str;
    strcpy(P_str.ch,p);
    strcpy(T_str.ch,q);   // 为其赋值
    P_str.length = strlen(P_str.ch);
    T_str.length = strlen(T_str.ch);
    int index = _BF_Algorithm(P_str,T_str,0);
    
    int index = _KMP_algorithm(P_str,T_str,0);
    printf("T在P中的位置为：%d",index);






    
    return 0;
}
