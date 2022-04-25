#include <stdio.h>

typedef struct{
    int A[100][500];
    int n, m;
}Graph;

void init_graph(Graph *pG, int n, int m){
    pG->n = n;
    pG->m = m;
    for(int u = 1; u <= n;  u++)
        for(int e = 1; e <= m; e++)
            pG->A[u][e] = 0;
}

void add_edge(Graph *pG, int e, int x, int y){
    pG->A[x][e] = 1;
    pG->A[y][e] = 1;
}

int main(){
    int n = 3, m = 1;
    Graph G;
    init_graph(&G, n, m);
    add_edge(&G, 1, 2, 3);
    printf("%d %d\n", G.A[2][1], G.A[3][1]);
    return 0;
}