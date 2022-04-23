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
    if(u < 1 || u > pG->n || v < 1 || v > pG->n) return;
    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;
    pG->m++;
}

int main(){
    printf("Hello");
    return 0;
}