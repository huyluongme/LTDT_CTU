#include <stdio.h>
#define MAX 100

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

typedef struct {
	int data[MAX];
	int top_id;
}stack;

void make_null_stack(stack* pS) {
	pS->top_id = -1;
}

void push_back(stack* pS, int x) {
	pS->top_id++;
	pS->data[pS->top_id] = x;
}

void pop_back(stack* pS) {
	pS->top_id--;
}

int back(stack S) {
	return S.data[S.top_id];
}

int empty(stack S) {
	return S.top_id == -1;
}

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if ((pG->edges[e].u == u && pG->edges[e].v == v)
			|| (pG->edges[e].u == v && pG->edges[e].v == u))
			return 1;
	return 0;
}

int mark[MAX];

void DFS(Graph* pG, int u) {
	stack S;
	make_null_stack(&S);

	push_back(&S, u);

	while (!empty(S)) {
		int s = back(S);
		pop_back(&S);
		if (mark[s] != 0)
			continue;

		printf("%d\n", s);
		mark[s] = 1;
		for (int v = pG->n; v >= 1; v--)
			if (adjacent(pG, s, v))
				push_back(&S, v);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}

	for (int u = 1; u <= n; u++)
		mark[u] = 0;
	int s;
	scanf("%d", &s);
	DFS(&G, s);
	return 0;
}
