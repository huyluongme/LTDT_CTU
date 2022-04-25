#include <stdio.h>

typedef struct{
    int A[100][100];
    int n;
}Graph;

void init_graph(Graph *pG, int n){
    pG->n = n;
    for(int u = 1; u <= pG->n; u++)
        for(int v = 1; v <= pG->n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v){
    pG->A[u][v] = 1;
    pG->A[v][u] = 1;
}

int deg(Graph *pG, int u){
    int deg_u = 0;
    for(int v = 1; v <= pG->n; v++)
        deg_u += pG->A[u][v];
    return deg_u += pG->A[u][u];
}

void v_max_deg(Graph *pG){
    int v = 1, deg_max = deg(pG, v);
    for(int u = 2; u <= pG->n; u++)
        if(deg(pG, u) > deg_max){
            v= u;
            deg_max = deg(pG,u);
        }
    printf("%d %d", v, deg_max);
}              

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    Graph G;
    init_graph(&G, n);
    for(int e = 1; e <= m; e++){
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&G, u, v);
    }
    v_max_deg(&G);
    return 0;
}