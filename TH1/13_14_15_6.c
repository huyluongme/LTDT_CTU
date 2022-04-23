#include <stdio.h>
#define MAX_N 100

typedef struct {
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG, int n){
    pG->n = n;
    pG->m = 0;
    for(int u = 1; u <= n; u++)
        for(int v = 1; v <= n; v++)
            pG->A[u][v] = 0;
}

int main() {
    int n;
    Graph G;
    scanf("%d", &n);
    init_graph(&G, n);
    for(int u = 1; u <= n; u++){
        int v;
        do{
            scanf("%d", &v);
            G.A[u][v]++;
        }while(v != 0);
    }

    for(int u = 1; u <= n; u++){
        for(int v = 1; v <= n; v++)
            printf("%d ", G.A[u][v]);
        printf("\n");
    }
    return 0;
}