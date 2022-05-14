#include <stdio.h>

typedef struct {
	int u, v;
	int w;
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
	if (u != v) {
		pG->edges[pG->m].v = u;
		pG->edges[pG->m].u = v;
		pG->edges[pG->m].w = w;
	}
	pG->m++;
}

void Swap(Edge* a, Edge* b) {
	Edge tmp = *a;
	*a = *b;
	*b = tmp;
}

void BubbleSort(Graph* pG) {
	for (int i = 0; i < pG->m - 1; i++) {
		for (int j = pG->m - 1; j > i; j--) {
			if (pG->edges[j].w < pG->edges[j - 1].w)
				Swap(&pG->edges[j], &pG->edges[j - 1]);
		}
	}
}

int findroot(int parent[], int u) {
	if (u == parent[u]) {
		return u;
	}
	else {
		return findroot(parent, parent[u]);
	}
}

int parent[100];

int Kruskal(Graph* pG, Graph* pT) {
	BubbleSort(pG);
	for (int u = 1; u <= pG->n; u++)
		parent[u] = u;
	int sum = 0;
	init_graph(pT, pG->n);
	for (int e = 0; e < pG->m; e++) {
		int u = pG->edges[e].u;
		int v = pG->edges[e].v;
		int w = pG->edges[e].w;
		int root_u = findroot(parent, u);
		int root_v = findroot(parent, v);
		if (root_u != root_v) {
			add_edge(pT, u, v, w);
			sum += w;
			parent[root_v] = root_u;
		}
	}
	return sum;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G, T;
	init_graph(&G, n);
	for (int e = 0; e < m; e++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	int sum_w_G = 0;
	for (int e = 0; e < G.m; e++)
		sum_w_G += G.edges[e].w;
	printf("%d", sum_w_G - Kruskal(&G, &T));
	return 0;
}
