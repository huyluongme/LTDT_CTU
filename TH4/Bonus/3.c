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

void copy_list(List *pS1, List *pS2){
    make_null_list(pS1);
    for(int i = 1; i <= pS2->size; i++)
        push_back(pS1, element_at(pS2, i));    
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

int r[MAX_N];

void rank(Graph *pG){
    int d[MAX_N];
    for(int u = 1; u <= pG->n; u++){
        d[u] = 0;
        for(int v = 1; v <= pG->n; v++){
            if(pG->A[v][u] > 0)
                d[u]++;
        }
    }

    List S1, S2;
    make_null_list(&S1);
    for(int u = 1; u <= pG->n; u++)
        if(d[u] == 0)
            push_back(&S1, u);
    
    int k = 0;
    while(S1.size > 0){
        make_null_list(&S2);
        for(int i = 1; i <= S1.size; i++){
            int u = element_at(&S1, i);
            r[u] = k;
            for(int v = 1; v <= pG->n; v++){
                if(pG->A[u][v] != 0){
                    d[v]--;
                    if(d[v] == 0)
                        push_back(&S2, v);
                }
            }
        }
        k++;
        copy_list(&S1, &S2);
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
        add_edge(&G, v, u);
    }
    rank(&G);
    int sum = 0;
    for(int u = 1; u <= G.n; u++){
        printf("%d\n", r[u] + 1);
        sum += (r[u] + 1);
    }
    printf("%d", sum);
    return 0;
}
