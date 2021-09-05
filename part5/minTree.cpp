/*
 * @Author: your name
 * @Date: 2021-09-05 10:45:51
 * @LastEditTime: 2021-09-05 18:15:25
 * @LastEditors: Please set LastEditors
 * @Description: 最小生成树的两种算法,克鲁斯卡尔算法没有实现，另外迪杰特斯拉还有……也没有实现
 * @FilePath: \Dstructure\part5\minTree.cpp
 */
#include<iostream>
using namespace std;
#define MAXNODES 7
#define INF 9999
#define ROW 7
#define COL 7
typedef struct _Graph
{
    /* 用邻接矩阵进行表示 */
    char VerNode[MAXNODES];// 图中的结点
    int ArcTable[ROW][COL]; // 图的边表
    int ver,arc; //图中的结点的个数以及边的个数
}_Graph;

// 定义最小生成树中，用边表示
// 构造一个图
void CreateGraph(_Graph* &graph,int matrix[][9])
{
    for (int i = 0; i < ROW; i++)
    {
        graph->VerNode[i] = i+65;
        for (int j = 0; j < COL;j++)
        {
            graph->ArcTable[i][j] = matrix[i][j];
        }
    }
}
// 将矩阵进行打印
void printGraph(_Graph* &graph)
{
    for(int i = 0;i < ROW;i++)
    {
        printf("%c  ",graph->VerNode[i]);
        for (int j = 0; j < COL; j++)
        {
            /* code */
            printf("%d\t",graph->ArcTable[i][j]);
            
        }
        printf("\n");
        
    }
}

// 对图进行prim算法进行最小生成树算法
int _Prim(_Graph* graph, int _start)     // _start表示从这个顶点作为开始结点
{
    int sum = 0;
    // 定义两个数组，一个用于存储找出来的顶点，一个用于存储每次找出来的最小的边
    int vset[ROW];
    int lowcost[ROW];
    // colset数组为填入的头结点集合
    // lowcost为已经构造的生成树的邻近代价
    // 接下来构造第一个结点
    int index = _start;
    int k;
    for (int i = 0;i < ROW;i++)
    {
        lowcost[i] = graph->ArcTable[index][i];
        vset[i]=0;
    }
    vset[_start] = 1;
    for (int i = 1; i < ROW; i++)
    {
        int min = INF;
        // 找最下的边
        for (int j = 1;j < ROW;j++)
        {
            //
            if (vset[j] == 0 &&lowcost[j] < min)
            {
                /* code */
                min = lowcost[j];
                k = j;
            }
            
        }

        vset[k] = 1;
        index= k;
        printf("%c",graph->VerNode[k]);
        sum = sum + min;
        // 然后将找到的index加入到最小生成树中
        for (int j = 0;j < ROW;j++)
        {
            if(vset[j] == 0 && graph->ArcTable[index][j] < lowcost[j])
            {
                lowcost[j] = graph->ArcTable[index][j];
                
            }
        }
    }
    
    
    return sum; 
}



//




int main()
{
    int matrix[][9] = {
        /*A*//*B*//*C*//*D*//*E*//*F*//*G*/
        /*A*/ {   0,  12, INF, INF, INF,  16,  14},
        /*B*/ {  12,   0,  10, INF, INF,   7, INF},
        /*C*/ { INF,  10,   0,   3,   5,   6, INF},
        /*D*/ { INF, INF,   3,   0,   4, INF, INF},
        /*E*/ { INF, INF,   5,   4,   0,   2,   8},
        /*F*/ {  16,   7,   6, INF,   2,   0,   9},
        /*G*/ {  14, INF, INF, INF,   8,   9,   0} };
    _Graph *graph = new _Graph;
    CreateGraph(graph,matrix);
    printGraph(graph);
    _Prim(graph,0);
    return 0;
}
