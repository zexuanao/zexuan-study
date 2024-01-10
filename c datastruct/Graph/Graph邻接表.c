#include<stdio.h>
#define MAXVEX 100
#define INFINITY 65535
typedef char VertexType;
typedef int EdgeType;

typedef struct EdgeNode {
    int adjvex;
    EdgeType weight;
    struct EdgeNode *next;
} EdgeNode;

typedef struct VertexNode {
    VertexType data;
    EdgeNode *firstedge;
} VertexNode, AdjList[MAXVEX];

typedef struct {
    AdjList adjList;
    int numVertexes, numEdges;
} GraphAdjList;
//这是无边表的创建
void CreateALGraph(GraphAdjList *G) {
    int i, j, k;
    EdgeNode *e;

    printf("输入顶点数和边数:\n");
    /* 输入顶点数和边数 */
    scanf("%d,%d", &G->numVertexes, &G->numEdges);

    /* 读入顶点信息，建立顶点表 */
    for (i = 0; i < G->numVertexes; i++) {
        /* 输入顶点信息 */
        scanf(&G->adjList[i].data);
        /* 将边表置为空表 */
        G->adjList[i].firstedge = NULL;
    }

    /* 建立边表 */
    for (k = 0; k < G->numEdges; k++) {
        printf("输入边(vi,vj)上的顶点序号:\n");
        /* 输入边(vi,vj)上的顶点序号 */
        scanf("%d,%d", &i, &j);

        /* 向内存申请空间，生成边表结点 */
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        /* 邻接序号为j */
        e->adjvex = j;
        /* 将e指针指向当前顶点指向的结点 */
        e->next = G->adjList[i].firstedge;
        /* 将当前顶点的指针指向e */
        G->adjList[i].firstedge = e;

        /* 向内存申请空间，生成边表结点 */
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        /* 邻接序号为i */
        e->adjvex = i;
        /* 将e指针指向当前顶点指向的结点 */
        e->next = G->adjList[j].firstedge;
        /* 将当前顶点的指针指向e */
        G->adjList[j].firstedge = e;
    }
}
typedef int Boolean;
Boolean visited[MAXVEX];
void DFS(GraphAdjList GL, int i) {
    EdgeNode *p;
    visited[i] = 1;
    /* 打印顶点，也可以进行其他操作 */
    printf("%c ", GL.adjList[i].data);
    p = GL.adjList[i].firstedge;
    while (p) {
        if (!visited[p->adjvex])
            /* 对未访问的邻接顶点递归调用 */
            DFS(GL, p->adjvex);
        p = p->next;
    }
}

void DFSTraverse(GraphAdjList GL) {
    int i;
    for (i = 0; i < GL.numVertexes; i++)
        /* 初始所有顶点状态都是未访问过状态 */
        visited[i] = 0;
    for (i = 0; i < GL.numVertexes; i++)
        /* 对未访问过的顶点调用DFS，若是连通图，只会执行一次 */
        if (!visited[i])
            DFS(GL, i);
}
//dfs相当于前序遍历
//bfs相当于层序遍历
/*
void BFSTraverse(GraphAdjList GL) {
    int i;
    EdgeNode *p;
    Queue Q;

    for (i = 0; i < GL->numVertexes; i++)
        visited[i] = FALSE;

    InitQueue(&Q);

    for (i = 0; i < GL->numVertexes; i++) {
        if (!visited[i]) {
            visited[i] = TRUE;
            printf("%c ", GL->adjList[i].data);
            EnQueue(&Q, i);

            while (!QueueEmpty(Q)) {
                DeQueue(&Q, &i);
                p = GL->adjList[i].firstedge;
                while (p) {
                    if (!visited[p->adjvex]) {
                        visited[p->adjvex] = TRUE;
                        printf("%c ", GL->adjList[p->adjvex].data);
                        EnQueue(&Q, p->adjvex);
                    }
                    p = p->next;
                }
            }
        }
    }
}

*/