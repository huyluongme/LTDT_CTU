#include <stdio.h>

typedef struct{
    int n, m;
    int A[100][100];
}Graph;

void init_graph(Graph *pG, int n){
    pG->n = n;
    pG->m = 0;
    for(int u = 1; u <= n; u++)
        for(int v = 1; v <= n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v){
    pG->A[u][v] = 1;
    pG->A[v][u] = 1;
    pG->m++;
}

int main(){
    freopen("dt1.txt", "r", stdin);
    int n, m;
    Graph G;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);
    for(int e = 1; e <= m; e++){
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&G, u, v);
    }

    for(int u = 1; u <= n; u++){
        for(int v = 1; v <= n; v++)
            printf("%d ", G.A[u][v]);
        printf("\n");
    }
    return 0;
}