#include <stdio.h>

#define MAX 100

typedef int ElementType;
typedef struct{
    ElementType data[MAX];
    int size;
}List;

typedef struct{
    int A[100][500];
    int n, m;
}Graph;

void make_null(List *pL){
    pL->size = 0;
}

void push_back(List *pL, ElementType x){
    pL->data[pL->size] = x;
    pL->size++;
}

ElementType element_at(List *pL, int i){
    return pL->data[i - 1];
}

int count_list(List *pL){
    return pL->size;
}

void init_graph(Graph *pG, int n, int m){
    pG->n = n;
    pG->m = m;
    for(int u = 1; u <= n; u++)
        for(int e = 1; e <= m; e++)
            pG->A[u][e] = 0; 
}

void add_edge(Graph *pG, int e, int x, int y){
    pG->A[x][e] = 1;
    pG->A[y][e] = 1;
}

int adjacent(Graph *pG, int u, int v){
    for(int e = 1; e <= pG->m; e++)
        if(pG->A[u][e] == 1 && pG->A[v][e] == 1)
            return 1;
    return 0;    
}

List neighbors(Graph *pG, int u){
    List L;
    make_null(&L);
    for(int v = 1; v <= pG->n; v++)
        if(u != v && adjacent(pG, u, v))
            push_back(&L, v);
    return L;
}

int main(){
    int n = 4, m = 5;
    Graph G;
    init_graph(&G, n, m);
    add_edge(&G, 1,1,2);
    add_edge(&G, 2,1,3);
    add_edge(&G, 3,1,4);
    add_edge(&G, 4,2,3);
    add_edge(&G, 5,1,3);
    List L = neighbors(&G, 1);
    for(int i = 0; i < L.size; i++)
        printf("%d\n", L.data[i]);
    return 0;
}