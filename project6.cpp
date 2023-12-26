//#include <stdio.h>
//#include <limits.h>
//
//#define MVNum 100 // ��󶥵���
//#define INF INT_MAX // �����ֵ
//
//typedef struct {
//    int vexnum, arcnum; // ͼ�ĵ�ǰ�����ͱ���
//    int arcs[MVNum][MVNum]; // �ڽӾ���洢����Ϣ
//    char vexs[MVNum]; // ������Ϣ
//} AMGraph;
//
//void ShortestPath_DIJ(AMGraph* g, int v0) {
//    int v, w, min;
//    int s[MVNum], d[MVNum], path[MVNum];
//
//    int n = g->vexnum;
//
//    for (v = 0; v < n; ++v) {
//        s[v] = 0; // ����Ƿ��ҵ����·��
//        d[v] = g->arcs[v0][v]; // ��ʼ��Դ�㵽������ľ���
//        if (d[v] < INF) {
//            path[v] = v0; // ��¼·��
//        }
//        else {
//            path[v] = -1; // Դ�㵽v0���ɴ�ʱ�ı��
//        }
//    }
//
//    d[v0] = 0; // Դ�㵽�������Ϊ0
//    s[v0] = 1; // ��Դ��v0����s��
//
//    for (int i = 0; i < n - 1; ++i) {
//        min = INF;
//        for (w = 0; w < n; ++w) {
//            if (!s[w] && d[w] < min) {
//                v = w;
//                min = d[w]; // Ѱ����С·��
//            }
//        }
//        s[v] = 1; // ��Ƕ���v�Ѽ���s��
//
//        for (w = 0; w < n; ++w) {
//            if (!s[w] && min + g->arcs[v][w] < d[w]) {
//                d[w] = min + g->arcs[v][w]; // �������·��
//                path[w] = v; // ��¼·��
//            }
//        }
//    }
//
//    // ������
//    printf("�Ͻ�˹�����㷨��\n");
//    for (v = 0; v < n; ++v) {
//        if (v == v0) {
//            printf("Path %c to %c:\nLength:0\n", g->vexs[v], g->vexs[v]);
//        }
//        else if (d[v] == INF) {
//            printf("Path %c to %c:\nLength:��\n", g->vexs[v0], g->vexs[v]);
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
//    printf("�����ܶ�������");
//    scanf_s("%d", &G.vexnum);
//    printf("�����ܱ�����");
//    scanf_s("%d", &G.arcnum);
//
//    printf("���붥����Ϣ��\n");
//    getchar(); // ��ȡ���з�
//    for (i = 0; i < G.vexnum; ++i) {
//        scanf_s(" %c", &G.vexs[i], 1);
//    }
//
//    // ��ʼ���ڽӾ���
//    for (i = 0; i < G.vexnum; ++i) {
//        for (j = 0; j < G.vexnum; ++j) {
//            G.arcs[i][j] = INF;
//        }
//    }
//
//    // �����бߵĶ����Ȩֵ
//    printf("�����бߵĶ����Ȩֵ��\n");
//    getchar(); // ��ȡ���з�
//    for (k = 0; k < G.arcnum; ++k) {
//        char v1, v2;
//        int weight;
//        scanf_s(" %c %c %d", &v1, 1, &v2, 1, &weight);
//        getchar(); // ��ȡ���з�
//        i = v1 - 'a';
//        j = v2 - 'a';
//        G.arcs[i][j] = weight;
//    }
//
//    // ����ڽӾ���
//    printf("�ڽӾ���\n");
//    for (i = 0; i < G.vexnum; ++i) {
//        for (j = 0; j < G.vexnum; ++j) {
//            if (G.arcs[i][j] == INF) {
//                printf("�� ");
//            }
//            else {
//                printf("%2d ", G.arcs[i][j]);
//            }
//        }
//        printf("\n");
//    }
//
//    printf("�Ͻ�˹�����㷨�����뿪ʼ�Ķ��㣺");
//    char startVertex;
//    scanf_s(" %c", &startVertex, 1);
//    v0 = startVertex - 'a'; // ���ַ�ת��Ϊ�±�����
//    ShortestPath_DIJ(&G, v0); // ���õϽ�˹�����㷨
//
//    return 0;
//}