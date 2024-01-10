#define MAXVEX 100
/* 边表结点 */
typedef struct EdgeNode {
    int adjvex;          // 邻接点域，存储该顶点对应的下标
    int weight;          // 用于存储权值，对于非网图可以不需要
    struct EdgeNode *next;  // 链域，指向下一个邻接点
} EdgeNode;

/* 顶点表结点 */
typedef struct VertexNode {
    int in;              // 顶点入度
    int data;            // 顶点域，存储顶点信息
    EdgeNode *firstedge; // 边表头指针
} VertexNode, AdjList[MAXVEX];  // 定义顶点表数组AdjList

typedef struct {
    AdjList adjList;     // 顶点表数组
    int numVertexes;     // 图中当前顶点数
    int numEdges;        // 图中当前边数
} graphAdjList, *GraphAdjList;  // 图的邻接表结构
/* 拓扑排序，若GL无回路，则输出拓扑排序序列并返回OK，若有回路返回ERROR */
int TopologicalSort(GraphAdjList GL) {

    EdgeNode *e;
    int i, k, gettop;
    int top = 0;  // 用于栈指针下标
    int count = 0;  // 用于统计输出顶点的个数
    int *stack;  // 建栈存储入度为0的顶点

    stack = (int *)malloc(GL->numVertexes * sizeof(int));

    // 初始化栈，将入度为0的顶点入栈
    for (i = 0; i < GL->numVertexes; i++)
        if (GL->adjList[i].in == 0)
            stack[++top] = i;

    // 遍历栈
    while (top != 0) {
        // 出栈
        gettop = stack[top--];
        // 打印此顶点
        printf("%d -> ", GL->adjList[gettop].data);
        // 统计输出顶点数
        count++;
        // 对此顶点弧表遍历
        for (e = GL->adjList[gettop].firstedge; e; e = e->next) {
            k = e->adjvex;
            // 将k号顶点邻接点的入度减1
            if (!(--GL->adjList[k].in))
                // 若为0则入栈，以便于下次循环输出
                stack[++top] = k;
        }
    }

    // 如果count小于顶点数，说明存在环
    if (count < GL->numVertexes)
        return 0;
    else
        return 1;
}

#include <stdio.h>
#include <stdlib.h>

int *etv, *ltv;       // 事件最早发生时间和最迟发生时间数组
int *stack2;          // 用于存储拓扑序列的栈
int top2;             // 用于stack2的指针

int TopologicalSort(GraphAdjList GL) {
    EdgeNode *e;
    int i, k, gettop;
    int top = 0;          // 用于栈指针下标
    int count = 0;        // 用于统计输出顶点的个数
    int *stack;           // 建栈将入度为0的顶点入栈

    stack = (int *)malloc(GL->numVertexes * sizeof(int));

    for (i = 0; i < GL->numVertexes; i++)
        if (GL->adjList[i].in == 0)
            stack[++top] = i;

    top2 = 0;             // 初始化为0
    etv = (int *)malloc(GL->numVertexes * sizeof(int));
    for (i = 0; i < GL->numVertexes; i++)
        etv[i] = 0;       // 初始化为0

    stack2 = (int *)malloc(GL->numVertexes * sizeof(int));

    while (top != 0) {
        gettop = stack[top--];
        count++;
        stack2[++top2] = gettop; // 将弹出的顶点序号压入拓扑序列的栈

        for (e = GL->adjList[gettop].firstedge; e; e = e->next) {
            k = e->adjvex;

            if (!(--GL->adjList[k].in))
                stack[++top] = k;

            if ((etv[gettop] + e->weight) > etv[k])
                etv[k] = etv[gettop] + e->weight;
        }
    }

    if (count < GL->numVertexes)
        return 0;
    else
        return 1;
}

void CriticalPath(GraphAdjList GL) {
    EdgeNode *e;
    int i, gettop, k, j;
    int ete, lte;  // 活动最早发生时间和最迟发生时间变量

    // 求拓扑序列，计算数组etv和stack2的值
    TopologicalSort(GL);

    // 事件最晚发生时间
    ltv = (int *)malloc(GL->numVertexes * sizeof(int));
    for (i = 0; i < GL->numVertexes; i++)
        ltv[i] = etv[GL->numVertexes - 1];  // 初始化ltv

    // 计算ltv
    while (top2 != 0) {
        gettop = stack2[top2--];  // 将拓扑序列出栈，后进先出

        for (e = GL->adjList[gettop].firstedge; e; e = e->next) {
            // 求各顶点事件的最迟发生时间ltv值
            k = e->adjvex;

            // 求各顶点事件最晚发生时间ltv
            if (ltv[k] - e->weight < ltv[gettop])
                ltv[gettop] = ltv[k] - e->weight;
        }
    }

    // 求ete，lte和关键活动
    for (j = 0; j < GL->numVertexes; j++) {
        for (e = GL->adjList[j].firstedge; e; e = e->next) {
            k = e->adjvex;
            ete = etv[j];  // 活动最早发生时间
            lte = ltv[k] - e->weight;  // 活动最迟发生时间

            // 两者相等即在关键路径上
            if (ete == lte)
                printf("<v%d,v%d> length: %d , ", GL->adjList[j].data, GL->adjList[k].data, e->weight);
        }
    }
}
