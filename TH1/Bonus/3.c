#include <stdio.h>

typedef struct{
    int A[100][100];
    int n;
}Graph;

// void init_graph(Graph *pG, int n){
//     pG->n = n;
//     for(int u = 1; u <= pG->n; u++)
//         for(int v = 1; v <= pG->n; v++)
//             pG->A[u][v] = 0;
// }

// void add_edge(Graph *pG, int u, int v){
//     pG->A[u][v] = 1;
//     pG->A[v][u] = 1;
// }

int deg(Graph *pG, int u){
    int deg_u = 0;
    for(int v = 1; v <= pG->n; v++)
        deg_u += pG->A[u][v];
    return deg_u += pG->A[u][u];
}