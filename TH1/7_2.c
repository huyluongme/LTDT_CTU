#include <stdio.h>
#define MAX_N 100

typedef struct {
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG, int n){
    pG->n = n;
    pG->m = 0;

    for(int u = 1; u <= pG->n; u++)
        for(int v = 1; v <= pG->n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v){
    pG->A[u][v]++;
    if(u != v)
        pG->A[v][u]++;
    pG->m++;
}

int main() {
    Graph G;
    int n, m;
    
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (int e = 0; e < m; e++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    
    for (int u = 1; u <= G.n; u++) {
        for (int v = 1; v <= G.n; v++)
            printf("%d \n", G.A[u][v]);
        printf("\n");	
    }	
    return 0;
}