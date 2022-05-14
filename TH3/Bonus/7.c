#include <stdio.h>

#define MAXN 100
#define NO_EDGE 0
#define oo 999999

int mark[MAXN], pi[MAXN], p[MAXN], park[MAXN];

typedef struct
{
    int src, dest, weight;
} Edge;

typedef struct
{
    int n, m;
    Edge edge[MAXN];
} Graph;

void init_graph(Graph *pG, int n)
{
    pG->n = n;
    pG->m = 0;
}

void add_edge(Graph *pG, int u, int v, int w)
{
    Edge tmp = {u, v, w};
    pG->edge[pG->m++] = tmp;
}

// void MooreDijkstra(Graph *pG, int s)
// {
//     int u, v, it;
//     for (u = 1; u <= pG->n; u++)
//     {
//         pi[u] = oo;
//         mark[u] = 0;
//     }
//     pi[s] = 0;
//     p[s] = -1;

//     for (it = 1; it <= pG->n; it++)
//     {
//         int j, min_pi = oo;
//         for (j = 1; j <= pG->n; j++)
//             if (mark[j] == 0 && pi[j] < min_pi)
//             {
//                 min_pi = pi[j];
//                 u = j;
//             }

//         mark[u] = 1;

//         for (v = 1; v <= pG->n; v++)
//             if (pG->W[u][v] != NO_EDGE && mark[v] == 0)
//                 if (pi[u] + pG->W[u][v] < pi[v])
//                 {
//                     pi[v] = pi[u] + pG->W[u][v];
//                     p[v] = u;
//                 }
//     }
// }

void BellmanFord(Graph *pG, int s)
{
    int u, v, w, it, k;
    for (u = 1; u <= pG->n; u++)
        pi[u] = oo;
    pi[s] = 0;
    p[s] = -1;

    for (it = 1; it < pG->n; it++)
    {
        for (k = 0; k < pG->m; k++)
        {
            u = pG->edge[k].src;
            v = pG->edge[k].dest;
            w = pG->edge[k].weight;
            if (pi[u] == oo)
                continue;
            if (pi[u] + w < pi[v])
            {
                pi[v] = pi[u] + w;
                p[v] = u;
            }
        }
    }
   
}

int is_cycle(Graph *pG)
{
    int k;
    for (k = 0; k < pG->m; k++)
    {
        int u = pG->edge[k].src;
        int v = pG->edge[k].dest;
        int w = pG->edge[k].weight;
        if (pi[u] == oo)
                continue;
        if (pi[u] + w < pi[v])
            return 1;
    }
    return 0;
}

// void find_path(int s, int t)
// {
//     int path[MAXN], count = 0;
//     while (t != s)
//     {
//         path[count] = t;
//         t = p[t];
//         count++;
//     }

//     printf("%d -> ", s);
//     for (int i = count - 1; i > 0; i--)
//         printf("%d -> ", path[i]);
//     printf("%d", path[0]);
// }

int main()
{
    int n, m, s;
    Graph G;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }

    scanf("%d", &s);

    BellmanFord(&G, s);

    if (is_cycle(&G))
        printf("YES");
    else
        printf("NO");
    return 0;
}
