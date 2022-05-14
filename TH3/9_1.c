#include <stdio.h>

#define NO_EDGE 0

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
int pi[100][100];
int next[100][100];

void FloydWarshall(Graph* pG) {
	for (int u = 1; u <= pG->n; u++) {
		for (int v = 1; v <= pG->n; v++) {
			pi[u][v] = oo;
			next[u][v] = -1;
		}
	}
	for (int u = 1; u <= pG->n; u++)
		pi[u][u] = 0;
	for (int u = 1; u <= pG->n; u++)
		for (int v = 1; v <= pG->n; v++)
			if (pG->W[u][v] != NO_EDGE) {
				pi[u][v] = pG->W[u][v];
				next[u][v] = v;
			}

	for (int k = 1; k <= pG->n; k++)
		for (int u = 1; u <= pG->n; u++) {
			if (pi[u][k] == oo)
				continue;
			for (int v = 1; v <= pG->n; v++) {
				if (pi[k][v] == oo)
					continue;
				if (pi[u][k] + pi[k][v] < pi[u][v]) {
					pi[u][v] = pi[u][k] + pi[k][v];
					next[u][v] = next[u][k];
				}
			}
		}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 0; e < m; e++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	FloydWarshall(&G);
	for (int u = 1; u <= n; u++) {
		for (int v = 1; v <= n; v++) {
			if (pi[u][v] < oo)
				printf("%d -> %d: %d\n", u, v, pi[u][v]);
			else
				printf("%d -> %d: NO PATH\n", u, v);
		}
	}
	return 0;
}
