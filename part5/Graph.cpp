/*
 * @Author: your name
 * @Date: 2021-09-04 15:12:52
 * @LastEditTime: 2021-09-04 23:43:38
 * @LastEditors: Please set LastEditors
 * @Description: 图的相关的操作
 * @FilePath: \Dstructure\part5\Graph.cpp
 */
#include<iostream>
using namespace std;


// 定义边表的结构体
typedef struct ArcNode
{
    /* data */
    int nodeIndex;// 指向的下一个结点的编号
    struct ArcNode* next;// 下一条边
}ArcNode;

// 定义顶点的结构体
typedef struct VertexNode
{
    /* data */
    int data;// 顶点中存储的数据
    ArcNode* AdjacencyTable;// 该顶点的邻接表
    //struct VertexNode* next;
}VertexNode;

// 定义一个图
typedef struct Graph
{
    /* data */
    int NodeNum;// 图中结点的个数
    VertexNode* nodes;// 存储的各个顶点

}Graph;

#define MAXQUEUE 50
// 定义一个队列
typedef struct QueueVerNode
{
    /* data */
    //VertexNode* front;
    //VertexNode* rear;
    int data[MAXQUEUE];
    int front,rear;
    int len;
}QueueVerNode;
// 初始化一个队列
void initQueue(QueueVerNode* &queue)
{
    queue = new QueueVerNode;
    queue->front = queue->rear = 0;
    queue->len = 0;

}
// 元素加入到队列中
void pushQueue(QueueVerNode* &queue,int &elem)
{

    queue->data[queue->rear] = elem;
    queue->rear++;
    queue->len++;
}
// 判断队中的元素是否为空
bool isQueueEmpty(QueueVerNode* queue)
{
    if(queue->len == 0)
        return true;
    return false;

}
// 元素出队列
void popQueue(QueueVerNode* &queue,int &elem)
{
    if(!isQueueEmpty(queue))
    {
        // int temp = queue->front;
        elem = queue->data[queue->front];
        queue->front++;
        queue->len--;
    }
}

// 构造图
class GraphOperation
{
private:
    Graph* graph;
    int* visited;
public:
    GraphOperation(/* args */);
    // 读取文件中的数据，创建有一个图
    GraphOperation(FILE* fp);
    // 进行深度遍历
    void DepthTravel();
    // 进行广度遍历
    void BfsTravel();
    void BfsTravelCore(int &index);
    // 将图的空间进行释放
    void FreeGraph();
    void DepthCore(Graph* graph,int &index);


    ~GraphOperation();
};
void GraphOperation::FreeGraph()
{
    free(graph->nodes);
    graph->nodes = NULL;

    free(graph);
    graph = NULL;

    delete []visited;

}
void GraphOperation::DepthCore(Graph* graph, int &index)
{
    printf("%c" ,graph->nodes[index].data);
    visited[index] = 1;
    ArcNode* arc = graph->nodes[index].AdjacencyTable; // 获取头结点的连接的第一个第一条边
    while (arc)
    {
        /* code */
        if(!visited[arc->nodeIndex])
        {
            DepthCore(graph,arc->nodeIndex);
        }
        arc = arc->next;
    }
    
    
}

GraphOperation::GraphOperation(/* args */)
{
    
}

GraphOperation::~GraphOperation()
{
}
GraphOperation::GraphOperation(FILE* fp)
{
    if(fp == NULL) {
        cout<<"文件读取失败"<<endl;
        exit(0);
    }
    graph = (Graph* )malloc(sizeof(Graph)); // 申请一个新的对象
    
    fscanf(fp,"%d\n",&graph->NodeNum);
    if (graph->NodeNum == 0){
        cout<<"构造邻接表的结点个数为0"<<endl;
        exit(0);
    }
    // int Nodenum = graph->NodeNum;// VertexNode
    graph->nodes = (VertexNode*)malloc( graph->NodeNum * sizeof(VertexNode));// new VertexNode(58);
    visited = new int[graph->NodeNum]; // 用于标识结点是否被访问过

    for (int index1 = 0;index1<graph->NodeNum; index1++)
    {
        visited[index1] = 0;
        int arcNode = 0;
        // 头结点的初始化
       // char m;
        fscanf(fp,"%c %d",&graph->nodes[index1].data,&arcNode);
        graph->nodes[index1].AdjacencyTable = NULL;
        
        for(int index2 =0;index2<arcNode;index2++)
        {           
            // 创建该头结点链接的头结点
            if(graph->nodes[index1].AdjacencyTable = NULL)
            {
                ArcNode* node = (ArcNode*)malloc(sizeof(ArcNode));
                fscanf(fp," %d",&node->nodeIndex);
                node->next = NULL;
                graph->nodes[index1].AdjacencyTable = node;
            }
            else
            {
                ArcNode* node = (ArcNode*)malloc(sizeof(ArcNode));
                fscanf(fp," %d",&node->nodeIndex);
                node->next = graph->nodes[index1].AdjacencyTable;
                graph->nodes[index1].AdjacencyTable = node;
            }
            
            
        }
        char m;
        fscanf(fp,"%c",&m);
    }
    
}

// DFS算法的遍历出现在对一个头结点的连接表中进行遍历，也就是for循环需要放在外面
void GraphOperation::DepthTravel()
{
    for (int index = 0;index < graph->NodeNum;index++)
    {
        if (!visited[index])
            DepthCore(graph,index);
    }
    
}
void GraphOperation::BfsTravel()
{
    for (int index = 0;index < graph->NodeNum;index++)
    {
        if (!visited[index])
            BfsTravelCore(index);
    }
}
void GraphOperation::BfsTravelCore(int &index)
{
    // c
    printf("%c",graph->nodes[index].data);
    visited[index] = 1;
    // 初始化一个队列
    QueueVerNode* queue = NULL;
    initQueue(queue);
    // 将头结点入队
    pushQueue(queue,index);
    while (!isQueueEmpty(queue))
    {
        int w; // 用于标志
        popQueue(queue,w);
        while (graph->nodes[w].AdjacencyTable)
        {
            int index_1 = graph->nodes[w].AdjacencyTable->nodeIndex;
            /* code */
            if(!visited[index_1])
            {
                printf("%c",graph->nodes[index_1].data);
                visited[index_1] = 1;
                pushQueue(queue,w);
            }
            graph->nodes[w].AdjacencyTable = graph->nodes[w].AdjacencyTable->next;
        }
        
    }
}

int main()
{
    const char* filePath = "g.txt";
    FILE* fp = fopen(filePath,"r");
    GraphOperation* graph = new GraphOperation(fp);
    //graph->DepthTravel();
    
    graph->BfsTravel();
    graph->FreeGraph();
    fclose(fp);
    return 0;
}

