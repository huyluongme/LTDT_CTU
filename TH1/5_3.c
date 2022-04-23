#include <stdio.h>

#define MAX_N 100

typedef struct{
    int u, v;
}Edge;

typedef struct{
    int n, m;
    Edge edges[MAX_N];
}Graph;

void init_graph(Graph *pG, int n){
    pG->n = n;
    pG->m = 0;
}

void add_edge(Graph *pG, int u, int v){
    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;
    pG->m++;
}

int degree(Graph G, int u){
    int deg_u = 0;
    for(int i = 0; i < G.m; i++){
        if(G.edges[i].u == u)
            deg_u++;
        if(G.edges[i].v == u)
            deg_u++;
    }
    return deg_u;
}

int main(){
    freopen("dt.txt", "r", stdin);
    int n, m;
    Graph G;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);
    for(int e = 0; e < m; e++){
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&G, u, v);
    }

    for(int u = 1; u <= G.n; u++)
        printf("deg(%d) = %d\n", u, degree(G, u));
    return 0;
}