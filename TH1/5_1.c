#include <stdio.h>

#define MAX_N 100

typedef struct
{
    int u, v;
} Edge;

typedef struct
{
    int n, m;
    Edge edges[MAX_N];
} Graph;

void init_graph(Graph *pG, int n)
{
    pG->n = n;
    pG->m = 0;
}

void add_edge(Graph *pG, int u, int v)
{
    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;
    pG->m++;
}

int degree(Graph *pG, int u)
{
    int deg_u = 0;
    for (int i = 0; i < pG->m; i++){
        if (pG->edges[i].u == u)
            deg_u++;

        if (pG->edges[i].v == u)
            deg_u++;
    }
    return deg_u;
}

// Hàm main()
int main()
{
    Graph G;
    int n = 4, u;
init_graph(&G, n);
add_edge(&G, 1, 3);
add_edge(&G, 4, 2);
add_edge(&G, 2, 4);
add_edge(&G, 2, 4);
add_edge(&G, 3, 2);

    // In bậc của các đỉnh
    for (u = 1; u <= n; u++)
        printf("deg(%d) = %d\n", u, degree(&G, u));
    return 0;
}