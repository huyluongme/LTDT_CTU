#include <stdio.h>

#include <stdio.h>
#define MAX_N 100
#define INF 99999

typedef struct {
    int C[MAX_N][MAX_N];
    int F[MAX_N][MAX_N];
    int n;
}Graph;

void init_graph(Graph* pG, int n) {
    pG->n = n;
}

typedef struct {
    int dir;
    int p;
    int sigma;
}Label;

Label label[MAX_N];

typedef struct {
    int Q[MAX_N];
    int front, rear;
}Queue;

void makenullQueue(Queue* pQ) {
    pQ->front = 0;
    pQ->rear = -1;
}

int empty(Queue Q) {
    return Q.front > Q.rear;
}

void enQueue(Queue* pQ, int x) {
    pQ->rear++;
    pQ->Q[pQ->rear] = x;
}

int pop(Queue* pQ) {
    int x = pQ->Q[pQ->front++];
    return x;
}

void init_flow(Graph* pG) {
    int i, j;
    for (i = 1; i <= pG->n; i++)
        for (j = 1; j <= pG->n; j++)
            pG->F[i][j] = 0;
}

int min(int a, int b) {
    return a > b ? b : a;
}

int FordFulkerson(Graph* pG, int s, int t) {
    int i, j;
    init_flow(pG);
    int max_flow = 0;
    Queue Q;
    do {
        for (i = 1; i <= pG->n; i++)
            label[i].dir = 0;
        label[s].dir = +1;
        label[s].p = s;
        label[s].sigma = INF;

        makenullQueue(&Q);
        enQueue(&Q, s);
        int found = 0;
        while (!empty(Q)) {
            int u = pop(&Q);
            for (j = 1; j <= pG->n; j++) {
                if (pG->C[u][j] != 0 && !label[j].dir && pG->F[u][j] < pG->C[u][j]) {
                    label[j].dir = +1;
                    label[j].p = u;
                    label[j].sigma = min(label[u].sigma, pG->C[u][j] - pG->F[u][j]);
                    enQueue(&Q, j);
                }
            }
            for (j = 1; j <= pG->n; j++) {
                if (pG->C[j][u] != 0 && !label[j].dir && pG->F[j][u] > 0) {
                    label[j].dir = -1;
                    label[j].p = u;
                    label[j].sigma = min(label[u].sigma, pG->F[j][u]);
                    enQueue(&Q, j);
                }
            }
            if (label[t].dir != 0) {
                found = 1;
                break;
            }
        }
        if (found) {
            int sigma = label[t].sigma;
            int u = t;
            while (u != s) {
                int p = label[u].p;
                if (label[u].dir > 0)
                    pG->F[p][u] += sigma;
                else
                    pG->F[u][p] -= sigma;
                u = p;
            }
            max_flow += sigma;
        }
        else break;
    } while (1);
    return max_flow;
}


int main() {
    Graph G;
    int n, m, u, v, e, c, i;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);
    //Đọc trực tiếp các cung vào ma trận trọng số không cần hàm add_edge()
    for (e = 0; e < m; e++) {
        scanf("%d%d%d", &u, &v, &c);
        G.C[u][v] = c;
    }
    int max_flow = FordFulkerson(&G, 1, n);
    printf("Max flow: %d\n", max_flow);
    printf("S: ");
    for (i = 1; i <= n; i++) {
        if (label[i].dir)
            printf("%d ", i);
    }
    printf("\nT: ");
    for (i = 1; i <= n; i++) {
        if (!label[i].dir)
            printf("%d ", i);
    }
    return 0;
}
