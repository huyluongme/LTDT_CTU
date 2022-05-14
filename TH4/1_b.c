#include <stdio.h>

#define MAX_N 100
typedef int ElementType;

typedef struct
{
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;

typedef struct
{
    ElementType data[MAX_N];
    int size;
} List;

void make_null_list(List *pL)
{
    pL->size = 0;
}

void push_back(List *pL, int x)
{
    pL->data[pL->size] = x;
    pL->size++;
}

ElementType element_at(List *pL, int i)
{
    return pL->data[i - 1];
}

void init_graph(Graph *pG, int n)
{
    pG->n = n;
    pG->m = 0;
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v)
{
    pG->A[u][v]++;
    pG->m++;
}

int mark[MAX_N];

void dfs(Graph G, int u, List *pL){
    mark[u] = 1;
    for(int v = 1; v <= G.n; v++){
        if(G.A[u][v] > 0){
            if(mark[v] == 0)
                dfs(G, v, pL);
        }
    }
    push_back(pL, u);
}

void topo_sort(Graph G, List *pL){
    for(int u = 1; u <= G.n; u++) mark[u] = 0;

    for(int u = 1; u <= G.n; u++){
        if(mark[u] == 0)
            dfs(G, u, pL);
    }
}

int main()
{
    int n, m;
    Graph G;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);
    for (int e = 0; e < m; e++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&G, u, v);
    }
    List L;
    topo_sort(G, &L);
    for(int i = L.size; i > 0; i--)
        printf("%d ", element_at(&L, i));

    return 0;
}
