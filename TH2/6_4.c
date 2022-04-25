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
	int u, p;
}elementtype;

typedef struct {
	elementtype data[MAX];
	int top_id;
}stack;

void make_null_stack(stack* pS) {
	pS->top_id = -1;
}

void push_back(stack* pS, elementtype x) {
	pS->top_id++;
	pS->data[pS->top_id] = x;
}

void pop_back(stack* pS) {
	pS->top_id--;
}

elementtype back(stack S) {
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
		if (pG->edges[e].u == u && pG->edges[e].v == v)
			return 1;
	return 0;
}

int mark[MAX];
int parent[MAX];
void DFS(Graph* pG, int s) {
	stack S;
	make_null_stack(&S);
	elementtype pair = { s, -1 };
	push_back(&S, pair);

	while (!empty(S)) {
		elementtype pair = back(S);
		pop_back(&S);

		int u = pair.u, p = pair.p;

		if (mark[u] != 0)
			continue;

		mark[u] = 1;
		parent[u] = p;
		for (int v = pG->n; v >= 1; v--)
			if (adjacent(pG, u, v)) {
				elementtype pair = { v, u };
				push_back(&S, pair);
			}
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

	for (int u = 1; u <= n; u++) {
		mark[u] = 0;
		parent[u] = -1;
	}

	for (int u = 1; u <= n; u++)
		if (mark[u] == 0)
			DFS(&G, u);

	for (int u = 1; u <= n; u++)
		printf("%d %d\n", u, parent[u]);
	return 0;
}
