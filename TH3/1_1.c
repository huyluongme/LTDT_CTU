#include <stdio.h>

#define NO_EDGE -1

typedef struct {
	int n, m;
	int W[100][100];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
	for (int u = 1; u <= n; u++)
		for (int v = 1; v <= n; v++)
			pG->W[u][v] = NO_EDGE;
}

void add_edge(Graph* pG, int u, int v, int w) {
	pG->W[u][v] = w;
	pG->m++;
}

#define oo 999999

int mark[100];
int pi[100];
int p[100];

void MooreDijkstra(Graph* pG, int s) {
	for (int u = 1; u <= pG->n; u++) {
		pi[u] = oo;
		mark[u] = 0;
	}

	pi[s] = 0;
	p[s] = -1;
	int u, v;
	for (int i = 1; i < pG->n; i++) {
		int min_pi = oo;
		for (int j = 1; j <= pG->n; j++) {
			if (mark[j] == 0 && pi[j] < min_pi) {
				min_pi = pi[j];
				u = j;
			}
		}
		mark[u] = 1;

		for (v = 1; v <= pG->n; v++) {
			if (pG->W[u][v] != NO_EDGE && mark[v] == 0)
				if (pi[u] + pG->W[u][v] < pi[v]) {
					pi[v] = pi[u] + pG->W[u][v];
					p[v] = u;
				}
		}
	}
}

int main() {
	int n, m;
	Graph G;
	scanf("%d %d", &n, &m);
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}

	MooreDijkstra(&G, 1);

	for (int u = 1; u <= G.n; u++)
		printf("pi[%d] = %d, p[%d] = %d\n", u, pi[u], u, p[u]);

	return 0;
}
