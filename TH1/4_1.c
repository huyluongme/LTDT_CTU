#include <stdio.h>

#define MAX_M 500
typedef struct {
    int u, v;
} Edge;

typedef struct {
    int n, m;
    Edge edges[MAX_M];
} Graph;

void init_graph(Graph *pG, int n){
    pG->n = n;
    pG->m = 0;
}

void add_edge(Graph *pG, int u, int v){
    for(int i = 0; i < pG->m; i++)
        if((pG->edges[i].u == u && pG->edges[i].v == v)
        || (pG->edges[i].u == v && pG->edges[i].v == u)) return;
    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;
    pG->m++;
}

int adjacent(Graph *pG, int u, int v){
    for(int i = 0; i < pG->m; i++)
        if((pG->edges[i].u == u && pG->edges[i].v == v)
        || (pG->edges[i].u == v && pG->edges[i].v == u)) return 1;
    return 0;
}

int main(){
    Graph G;
    init_graph(&G, 3);
    add_edge(&G, 1, 3);
    add_edge(&G, 2, 3);
    add_edge(&G, 2, 2);
    return 0;
}