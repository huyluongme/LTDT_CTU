#include <stdio.h>

#define NO_EDGE -1

typedef struct {
	int n, m;
	int W[100][100];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
	for (int u = 1; u <= n; u++) {
		for (int v = 1; v <= n; v++) {
			pG->W[u][v] = NO_EDGE;
		}
	}
}

void add_edge(Graph* pG, int u, int v, int w) {
	pG->W[u][v] = w;
	pG->m++;
}

#define oo 999999
int mark[100], p[100], pi[100];

void Dijkstra(Graph* pG, int s) {
	for (int u = 1; u <= pG->n; u++) {
		mark[u] = 0;
		pi[u] = oo;
	}
	pi[s] = 0;
	p[s] = -1;
	int u;
	for (int i = 1; i < pG->n; i++) {
		int minpi = oo;
		for (int v = 1; v <= pG->n; v++) {
			if (!mark[v] && pi[v] < minpi) {
				minpi = pi[v];
				u = v;
			}
		}
		mark[u] = 1;
		for (int v = 1; v <= pG->n; v++) {
			if (!mark[v] && pG->W[u][v] != NO_EDGE) {
				if (pi[u] + pG->W[u][v] < pi[v]) {
					pi[v] = pi[u] + pG->W[u][v];
					p[v] = u;
				}
			}
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &m, &n);
	Graph G;
	init_graph(&G, n * m);
	for (int i = 1; i <= n * m; i++) {
		int w;
		scanf("%d", &w);
		if (i > n) {
			add_edge(&G, i - n, i, w);
			if (i + n <= n * m)
				add_edge(&G, i + n, i, w);
		}
		if ((i - 1) % n != 0)
			add_edge(&G, i - 1, i, w);
		if (i % n != 0)
			add_edge(&G, i + 1, i, w);
	}
	Dijkstra(&G, 1);
	
	printf("%d", pi[n*m]);
	return 0;
}
