//#include <stdio.h>
//#include <limits.h>
//
//#define MVNum 100 // 最大顶点数
//#define INF INT_MAX // 无穷大值
//
//typedef struct {
//    int vexnum, arcnum; // 图的当前点数和边数
//    int arcs[MVNum][MVNum]; // 邻接矩阵存储边信息
//    char vexs[MVNum]; // 顶点信息
//} AMGraph;
//
//void ShortestPath_DIJ(AMGraph* g, int v0) {
//    int v, w, min;
//    int s[MVNum], d[MVNum], path[MVNum];
//
//    int n = g->vexnum;
//
//    for (v = 0; v < n; ++v) {
//        s[v] = 0; // 标记是否找到最短路径
//        d[v] = g->arcs[v0][v]; // 初始化源点到各顶点的距离
//        if (d[v] < INF) {
//            path[v] = v0; // 记录路径
//        }
//        else {
//            path[v] = -1; // 源点到v0不可达时的标记
//        }
//    }
//
//    d[v0] = 0; // 源点到自身距离为0
//    s[v0] = 1; // 将源点v0加入s中
//
//    for (int i = 0; i < n - 1; ++i) {
//        min = INF;
//        for (w = 0; w < n; ++w) {
//            if (!s[w] && d[w] < min) {
//                v = w;
//                min = d[w]; // 寻找最小路径
//            }
//        }
//        s[v] = 1; // 标记顶点v已加入s中
//
//        for (w = 0; w < n; ++w) {
//            if (!s[w] && min + g->arcs[v][w] < d[w]) {
//                d[w] = min + g->arcs[v][w]; // 更新最短路径
//                path[w] = v; // 记录路径
//            }
//        }
//    }
//
//    // 输出结果
//    printf("迪杰斯特拉算法：\n");
//    for (v = 0; v < n; ++v) {
//        if (v == v0) {
//            printf("Path %c to %c:\nLength:0\n", g->vexs[v], g->vexs[v]);
//        }
//        else if (d[v] == INF) {
//            printf("Path %c to %c:\nLength:∞\n", g->vexs[v0], g->vexs[v]);
//        }
//        else {
//            printf("Path %c to %c:\n", g->vexs[v0], g->vexs[v]);
//            printf("Length:%d\n", d[v]);
//
//            printf("Path: %c", g->vexs[v]);
//            w = v;
//            while (path[w] != v0) {
//                printf(" <- %c", g->vexs[path[w]]);
//                w = path[w];
//            }
//            printf(" <- %c\n", g->vexs[v0]);
//        }
//    }
//}
//
//int main() {
//    AMGraph G;
//    int i, j, k, v0;
//    printf("输入总顶点数：");
//    scanf_s("%d", &G.vexnum);
//    printf("输入总边数：");
//    scanf_s("%d", &G.arcnum);
//
//    printf("输入顶点信息：\n");
//    getchar(); // 读取换行符
//    for (i = 0; i < G.vexnum; ++i) {
//        scanf_s(" %c", &G.vexs[i], 1);
//    }
//
//    // 初始化邻接矩阵
//    for (i = 0; i < G.vexnum; ++i) {
//        for (j = 0; j < G.vexnum; ++j) {
//            G.arcs[i][j] = INF;
//        }
//    }
//
//    // 输入有边的顶点和权值
//    printf("输入有边的顶点和权值：\n");
//    getchar(); // 读取换行符
//    for (k = 0; k < G.arcnum; ++k) {
//        char v1, v2;
//        int weight;
//        scanf_s(" %c %c %d", &v1, 1, &v2, 1, &weight);
//        getchar(); // 读取换行符
//        i = v1 - 'a';
//        j = v2 - 'a';
//        G.arcs[i][j] = weight;
//    }
//
//    // 输出邻接矩阵
//    printf("邻接矩阵：\n");
//    for (i = 0; i < G.vexnum; ++i) {
//        for (j = 0; j < G.vexnum; ++j) {
//            if (G.arcs[i][j] == INF) {
//                printf("∞ ");
//            }
//            else {
//                printf("%2d ", G.arcs[i][j]);
//            }
//        }
//        printf("\n");
//    }
//
//    printf("迪杰斯特拉算法，输入开始的顶点：");
//    char startVertex;
//    scanf_s(" %c", &startVertex, 1);
//    v0 = startVertex - 'a'; // 将字符转换为下标索引
//    ShortestPath_DIJ(&G, v0); // 调用迪杰斯特拉算法
//
//    return 0;
//}