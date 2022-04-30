#include <stdio.h>

#define MAX 100
#define NO_COLOR 0
#define BLUE 1
#define RED 2

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

int color[MAX];
int conflict;

void colorize(Graph* pG, int u, int c) {
	color[u] = c;

	for (int v = 1; v <= pG->n; v++) {
		if (adjacent(pG, u, v)) {
			if (color[v] == NO_COLOR)
				colorize(pG, v, 3 - c);
			else if (color[v] == color[u])
				conflict = 1;
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
		color[u] = NO_COLOR;
	}
	conflict = 0;
	for (int u = 1; u <= n; u++) {
		if (color[u] == NO_COLOR) {
			colorize(&G, u, BLUE);
		}
	}

	if (conflict == 1) {
		printf("NO");
	}
	else printf("YES");

	return 0;
}
