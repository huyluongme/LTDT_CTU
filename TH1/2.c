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

