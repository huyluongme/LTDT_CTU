#include <stdio.h>

#define MAX 100

#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

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

int parent[MAX];
int color[MAX];
int has_circle;

int start, end;

void DFS(Graph* pG, int s, int p) {
	color[s] = GRAY;
	parent[s] = p;

	for (int v = 1; v <= pG->n; v++)
		if (adjacent(pG, s, v)) {
			if (v == p) continue;
			if (color[v] == WHITE)
				DFS(pG, v, s);
			else if (color[v] == GRAY) {
				has_circle = 1;
				start = s;
				end = v;
			}
		}
	color[s] = BLACK;
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
		color[u] = WHITE;
		parent[u] = -1;
	}

	has_circle = 0;
	for (int u = 1; u <= n; u++) {
		if (color[u] == WHITE) {
			DFS(&G, u, -1);
		}
	}
	if (has_circle == 1) {
		int A[MAX], i = 0;
		A[0] = start;
		int u = start, v = end;
		do {
			u = parent[u];
			i++;
			A[i] = u;
		} while (u != v);

		for (int j = i; j >= 0; j--)
			printf("%d ", A[j]);

		printf("%d\n", A[i]);
	}
	else printf("-1");

	return 0;
}
