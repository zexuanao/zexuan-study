#define MAXVEX 100
#define INFINITY 65535
#include<stdio.h>
typedef struct 
{
    char vexs[MAXVEX];
    int arc[MAXVEX][MAXVEX];
    int numVertexes,numEdges;
    /* data */
}MGraph;


typedef int Patharc[MAXVEX];
typedef int ShortPathTable[MAXVEX];

/* Dijkstra算法，求有向网G的v0顶点到其余顶点v最短路径P[v]及带权长度D[v] */
void ShortestPath_Dijkstra(MGraph G, int v0, Patharc *P, ShortPathTable *D) {
    int v, w, k, min;
    int final[MAXVEX]; // final[w]=1表示求得顶点v0至v w的最短路径

    // 初始化数据
    for (v = 0; v < G.numVertexes; v++) {
        final[v] = 0; // 全部顶点初始化为未知最短路径状态
        (*D)[v] = G.arc[v0][v]; // 将与v0点有连线的顶点加上权值
        (*P)[v] = -1; // 初始化路径数组P为-1
    }

    (*D)[v0] = 0; // v0至v0路径为0
    final[v0] = 1; // v0至v0不需要求路径

    // 开始主循环，每次求得v0到某个v顶点的最短路径
    for (v = 1; v < G.numVertexes; v++) {
        min = INFINITY; // 当前所知离v0顶点的最近距离

        // 寻找离v0最近的顶点
        for (w = 0; w < G.numVertexes; w++) {
            if (!final[w] && (*D)[w] < min) {
                k = w; // w顶点离v0顶点更近
                min = (*D)[w]; // 更新最近距离
            }
        }

        final[k] = 1; // 将目前找到的最近的顶点置为1

        // 修正当前最短路径及距离
        for (w = 0; w < G.numVertexes; w++) {
            if (!final[w] && (min + G.arc[k][w] < (*D)[w])) {
                // 如果经过v顶点的路径比现在这条路径的长度短的话，更新最短路径信息
                (*D)[w] = min + G.arc[k][w]; // 更新当前路径长度
                (*P)[w] = k; // 修改路径信息
            }
        }
    }
}


typedef int Pathmatirx[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];

/* Floyd算法，求网图G中各顶点v到其余顶点w最短路径P[v][w]及带权长度D[v][w] */
void ShortestPath_Floyd(MGraph G, Pathmatirx *P, ShortPathTable *D) {
    int v, w, k;

    // 初始化D与P
    for (v = 0; v < G.numVertexes; ++v) {
        for (w = 0; w < G.numVertexes; ++w) {
            // D[v][w]值即为对应点间的权值
            (*D)[v][w] = G.matirx[v][w];
            // 初始化P
            (*P)[v][w] = w;
        }
    }

    for (k = 0; k < G.numVertexes; ++k) {
        for (v = 0; v < G.numVertexes; ++v) {
            for (w = 0; w < G.numVertexes; ++w) {
                if ((*D)[v][w] > (*D)[v][k] + (*D)[k][w]) {
                    // 如果经过下标为k顶点路径比原两点间路径更短
                    // 将当前两点间权值设为更小的一个
                    (*D)[v][w] = (*D)[v][k] + (*D)[k][w];
                    // 路径设置经过下标为k的顶点
                    (*P)[v][w] = (*P)[v][k];
                }
            }
        }
    }

    //print
    for (v = 0; v < G.numVertexes; ++v) 
    {
        for (w = v + 1; w < G.numVertexes; w++) {
            printf("v%d-v%d weight: %d ", v, w, D[v][w]);  // 打印顶点v到w的权值
        k = P[v][w];  // 获得第一个路径顶点下标
        printf(" path: %d", v);  // 打印源点
        while (k != w) 
        {
            printf(" -> %d", k);  // 打印路径顶点
            k = P[k][w];  // 获得下一个路径顶点下标
        }
        printf(" -> %d\n", w);  // 打印终点
    }
    printf("\n");
    }
}
