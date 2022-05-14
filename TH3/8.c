#include <stdio.h>

typedef struct {
	int u, v, w;
}Edge;

typedef struct {
	int n, m;
	Edge edges[100];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v, int w) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->edges[pG->m].w = w;
	pG->m++;
}

#define oo 999999
int mark[100], p[100], pi[100];

void BellmanFord(Graph* pG, int s) {
	for (int u = 1; u <= pG->n; u++) {
		mark[u] = 0;
		pi[u] = oo;
	}
	pi[s] = 0;
	p[s] = -1;

	for (int i = 1; i < pG->n; i++) {
		for (int e = 0; e < pG->m; e++) {
			int u = pG->edges[e].u;
			int v = pG->edges[e].v;
			int w = pG->edges[e].w;

			if (pi[u] == oo)
				continue;

			if (pi[u] + w < pi[v]) {
				pi[v] = pi[u] + w;
				p[v] = u;
			}
		}
	}
}

int b[100];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	for (int e = 0; e < m; e++) {
		int u, v, w;
		scanf("%d %d", &u, &v);
		w = (b[v] - b[u]) * (b[v] - b[u]) * (b[v] - b[u]);
		add_edge(&G, u, v, w);
	}
	int s, t;
	scanf("%d %d", &s, &t);
	BellmanFord(&G, s);
	if (pi[t] < oo)
		printf("%d", pi[t]);
	else
		printf("?");
	return 0;
}
