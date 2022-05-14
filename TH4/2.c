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


typedef struct
{
    ElementType data[MAX_N];
    int front, rear;
} Queue;

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

void make_null_queue(Queue *pQ)
{
    pQ->front = 0;
    pQ->rear = -1;
}
void enqueue(Queue *pQ, ElementType u)
{
    pQ->rear++;
    pQ->data[pQ->rear] = u;
}

ElementType front(Queue *pQ)
{
    return pQ->data[pQ->front];
}

void dequeue(Queue *pQ)
{
    pQ->front++;
}

int empty(Queue *pQ)
{
    return pQ->front > pQ->rear;
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

void topo_sort(Graph *pG, List *pL){
    int d[MAX_N];
    for(int u = 1; u <= pG->n; u++){
        d[u] = 0;
        for(int v = 1; v <= pG->n; v++){
            if(pG->A[v][u] > 0)
                d[u]++;
        }
    }

    Queue Q;

    make_null_queue(&Q);

    for(int u = 1; u <= pG->n; u++)
        if(d[u] == 0)
            enqueue(&Q, u);

    make_null_list(pL);
    
    while(!empty(&Q)){
        ElementType u = front(&Q);
        printf("%d\n", u);
        push_back(pL, u);
        dequeue(&Q);
        for(int v = 1; v <= pG->n; v++){
            if(pG->A[u][v] > 0){
                d[v]--;
                if(d[v] == 0)
                    enqueue(&Q, v);
            }
        }
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
    topo_sort(&G, &L);
    return 0;
}
