#include <stdio.h>
#define MAX 100

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

int mark[MAX];
int max_cnt = 0, tmp_cnt = 0;

void DFS(Graph* pG, int s) {
	mark[s] = 1;
	tmp_cnt++;
	for (int v = 1; v <= pG->n; v++)
		if (adjacent(pG, s, v) && mark[v] == 0)
			DFS(pG, v);
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
	}

	for (int u = 1; u <= n; u++)
		if (mark[u] == 0) {
			tmp_cnt = 0;
			DFS(&G, u);
			if (tmp_cnt > max_cnt) max_cnt = tmp_cnt;
		}

	printf("%d", max_cnt);

	return 0;
}
