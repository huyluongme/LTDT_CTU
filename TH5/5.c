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

void add_edge(Graph* pG, int u, int v, int c, int f) {
    pG->C[u][v] = c;
    pG->F[u][v] = f;
}


int sum_incoming_flow(Graph* pG, int u) {
    int res = 0;
    int i;
    for (i = 1; i <= pG->n; i++)
        if (pG->C[i][u] != 0)
            res += pG->F[i][u];
    return res;
}

int sum_outgoing_flow(Graph* pG, int u) {
    int res = 0;
    int i;
    for (i = 1; i <= pG->n; i++)
        if (pG->C[u][i] != 0)
            res += pG->F[u][i];
    return res;
}

int check_flow(Graph* pG, int s, int t) {
    int k;
    if (sum_outgoing_flow(pG, s) != sum_incoming_flow(pG, t)) return 0;
    for (k = 1; k <= pG->n; k++) {
        if (k != s && k != t) {
            if (sum_outgoing_flow(pG, k) != sum_incoming_flow(pG, k)) return 0;
        }
    }
    return 1;
}

int main() {
    Graph G;
    int n, m, u, v, e, c, f;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);
    for (e = 0; e < m; e++) {
        scanf("%d%d%d%d", &u, &v, &c, &f);
        if (c < f) {
            printf("NO");
            return 0;
        }
        add_edge(&G, u, v, c, f);
    }
    if (check_flow(&G, 1, n))
        printf("YES");
    else
    {
        printf("NO");
    }
    return 0;
}
