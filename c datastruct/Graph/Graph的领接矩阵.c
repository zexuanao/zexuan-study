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

//无向图的创建
void CrearMGraph(MGraph *G)
{
    int i,j,k,w;
    printf("请输入顶点数和编数：\n");
    scanf("%d,%d",&G->numVertexes,&G->numEdges);
    for (i=0;i<G->numVertexes;i++)
        scanf(&G->vexs[i]);
    for(i=0;i<G->numVertexes;i++)
        for(j=0;j<G->numVertexes;j++)
            G->arc[i][j]=INFINITY;
    for(k=0;k<G->numEdges;k++)
    {
        printf("输入边(vi,vj)上的i,j和权w:\n");
        scanf("%d,%d,%d",&i,&j,&w);
        G->arc[i][j]=w;
        G->arc[j][i]=G->arc[i][j];
    }
}
typedef int Boolean;
Boolean visited[MAXVEX];

/* 邻接矩阵的深度优先递归算法 */
void DFS(MGraph G, int i) {
    int j;
    visited[i] = 1;
    /* 打印顶点，也可以进行其他操作 */
    printf("%c ", G.vexs[i]);
    for (j = 0; j < G.numVertexes; j++)
        if (G.arc[i][j] == 1 && !visited[j])
            /* 对未访问的邻接顶点递归调用 */
            DFS(G, j);
}

/* 邻接矩阵的深度遍历操作 */
void DFSTraverse(MGraph G) {
    int i;
    for (i = 0; i < G.numVertexes; i++)
        /* 初始所有顶点状态都是未访问过状态 */
        visited[i] = 0;
    for (i = 0; i < G.numVertexes; i++)
        /* 对未访问过的顶点调用DFS，若是连通图，只会执行一次 */
        if (!visited[i])
            DFS(G, i);
}
//dfs相当于前序遍历
//bfs相当于层序遍历
/*
void BFSTraverse(MGraph G) {
    int i, j;
    Queue Q;

    for (i = 0; i < G.numVertexes; i++)
        visited[i] = FALSE;

    InitQueue(&Q);

    for (i = 0; i < G.numVertexes; i++) {
        if (!visited[i]) {
            visited[i] = TRUE;
            printf("%c ", G.vexs[i]);
            EnQueue(&Q, i);

            while (!QueueEmpty(Q)) {
                DeQueue(&Q, &i);
                for (j = 0; j < G.numVertexes; j++) {
                    if (G.arc[i][j] == 1 && !visited[j]) {
                        visited[j] = TRUE;
                        printf("%c ", G.vexs[j]);
                        EnQueue(&Q, j);
                    }
                }
            }
        }
    }
}

*/
/*
prim算法
假设N=(V,{E})是连通网，TE是N上最小生成树中边的集合。
算法从U={u 0 }(u 0 ∈V)，TE={}开始。
重复执行下述操作：在所有u∈U,v∈V-U的边(u,v)∈E中找一条代价最小的边(u 0 ,v 0 )并入集合TE，
同时v 0 并入U，直至U=V为止。此时TE中必有n-1条边，则T=(V,{TE})为N的最小生成树。
*/
void MiniSpanTree_Prim(MGraph G) {
    int min, i, j, k;
    int adjvex[MAXVEX];
    int lowcost[MAXVEX];
    
    lowcost[0] = 0;
    adjvex[0] = 0;

    for (i = 1; i < G.numVertexes; i++) {
        lowcost[i] = G.arc[0][i];
        adjvex[i] = 0;
    }

    for (i = 1; i < G.numVertexes; i++) {
        min = INFINITY;
        j = 1;
        k = 0;

        while (j < G.numVertexes) {
            if (lowcost[j] != 0 && lowcost[j] < min) {
                min = lowcost[j];
                k = j;
            }
            j++;
        }

        printf("(%d,%d)", adjvex[k], k);
        lowcost[k] = 0;

        for (j = 1; j < G.numVertexes; j++) {
            if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j]) {
                lowcost[j] = G.arc[k][j];
                adjvex[j] = k;
            }
        }
    }
}


//Kruskal算法
/*
假设N=(V,{E})是连通网，则令最小生成树的初始状态为只有n个顶点而无边的非连通图T={V,{}}，
图中每个顶点自成一个连通分量。在E中选择代价最小的边，若该边依附的顶点落在T中不同的连通分量上，
则将此边加入到T中，否则舍去此边而选择下一条代价最小的边。
依次类推，直至T中所有顶点都在同一连通分量上为止。
*/
typedef struct {
    int begin;
    int end;
    int weight;
} Edge;
void MiniSpanTree_Kruskal(MGraph G) {
    int i, n, m;
    Edge edges[MAXVEX];
    int parent[MAXVEX];

    for (i = 0; i < G.numVertexes; i++)
        parent[i] = 0;

    /* 此处省略将邻接矩阵G转化为边集数组edges并按权由小到大排序的代码 */

    for (i = 0; i < G.numEdges; i++) {
        n = Find(parent, edges[i].begin);
        m = Find(parent, edges[i].end);

        if (n != m) {
            parent[n] = m;
            printf("(%d, %d) %d ", edges[i].begin, edges[i].end, edges[i].weight);
        }
    }
}

int Find(int *parent, int f) {
    while (parent[f] > 0)
        f = parent[f];
    return f;
}
