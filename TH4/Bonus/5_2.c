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

void make_null_list(List* pL)
{
	pL->size = 0;
}

void push_back(List* pL, int x)
{
	pL->data[pL->size] = x;
	pL->size++;
}

ElementType element_at(List* pL, int i)
{
	return pL->data[i - 1];
}

void make_null_queue(Queue* pQ)
{
	pQ->front = 0;
	pQ->rear = -1;
}
void enqueue(Queue* pQ, ElementType u)
{
	pQ->rear++;
	pQ->data[pQ->rear] = u;
}

ElementType front(Queue* pQ)
{
	return pQ->data[pQ->front];
}

void dequeue(Queue* pQ)
{
	pQ->front++;
}

int empty(Queue* pQ)
{
	return pQ->front > pQ->rear;
}

void init_graph(Graph* pG, int n)
{
	pG->n = n;
	pG->m = 0;
	for (int u = 1; u <= n; u++)
		for (int v = 1; v <= n; v++)
			pG->A[u][v] = 0;
}

void add_edge(Graph* pG, int u, int v)
{
	pG->A[u][v]++;
	pG->m++;
}

void topo_sort(Graph* pG, List* pL)
{
	int d[MAX_N];
	for (int u = 1; u <= pG->n; u++)
	{
		d[u] = 0;
		for (int v = 1; v <= pG->n; v++)
		{
			if (pG->A[v][u] > 0)
				d[u]++;
		}
	}

	Queue Q;

	make_null_queue(&Q);

	for (int u = 1; u <= pG->n; u++)
		if (d[u] == 0)
			enqueue(&Q, u);

	make_null_list(pL);

	while (!empty(&Q))
	{
		ElementType u = front(&Q);
		// printf("%d\n", u);
		push_back(pL, u);
		dequeue(&Q);
		for (int v = 1; v <= pG->n; v++)
		{
			if (pG->A[u][v] > 0)
			{
				d[v]--;
				if (d[v] == 0)
					enqueue(&Q, v);
			}
		}
	}
}

int min(int a, int b)
{
	return (a > b) ? b : a;
}

int max(int a, int b)
{
	return (a < b) ? b : a;
}

int indeg(Graph G, int u)
{
	int indeg_u = 0;
	for (int v = 1; v <= G.n; v++)
		if (G.A[v][u] > 0)
			indeg_u++;
	return indeg_u;
}

int outdeg(Graph G, int u)
{
	int indeg_u = 0;
	for (int v = 1; v <= G.n; v++)
		if (G.A[u][v] > 0)
			indeg_u++;
	return indeg_u;
}

int d[MAX_N];
int main()
{
	int n;
	Graph G;
	scanf("%d", &n);
	init_graph(&G, n + 2);
	int alpha = n + 1, beta = n + 2;
	d[alpha] = 0;
	for (int u = 1; u <= n; u++)
	{
		scanf("%d", &d[u]);
		int v;
		scanf("%d", &v);
		while (v != 0)
		{
			add_edge(&G, v, u);
			scanf("%d", &v);
		}
	}

	for (int u = 1; u <= n; u++)
	{
		if (indeg(G, u) == 0)
			add_edge(&G, alpha, u);
	}

	for (int u = 1; u <= n; u++)
	{
		if (outdeg(G, u) == 0)
			add_edge(&G, u, beta);
	}
	List L;
	topo_sort(&G, &L);
	int t[MAX_N];
	t[alpha] = 0;

	for (int j = 2; j <= L.size; j++)
	{
		int u = element_at(&L, j);
		t[u] = -999999;
		for (int x = 1; x <= G.n; x++)
			if (G.A[x][u] > 0)
				t[u] = max(t[u], t[x] + d[x]);
	}
	int T[MAX_N];
	T[beta] = t[beta];
	for (int j = L.size - 1; j >= 1; j--)
	{
		int u = element_at(&L, j);
		T[u] = +999999;
		for (int v = 1; v <= G.n; v++)
			if (G.A[u][v] > 0)
				T[u] = min(T[u], T[v] - d[u]);
	}
	for (int u = 1; u <= n + 2; u++)
		if (t[u] == T[u])
			printf("%d\n", u);
	return 0;
}
