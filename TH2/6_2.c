#include <stdio.h>
#define MAX 100

typedef struct {
	int u, p;
}elementype;

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

typedef struct {
	elementype data[MAX];
	int front, rear;
}queue;

void make_null_queue(queue* pQ) {
	pQ->front = 0;
	pQ->rear = -1;
}

void enqueue(queue* pQ, elementype u) {
	pQ->rear++;
	pQ->data[pQ->rear] = u;
}

void dequeue(queue* pQ) {
	pQ->front++;
}

elementype front(queue Q) {
	return Q.data[Q.front];
}

int empty(queue Q) {
	return Q.front > Q.rear;
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

void BFS(Graph* pG, int s) {
	queue Q;
	make_null_queue(&Q);
	elementype pair;
	pair.u = s; pair.p = -1;
	enqueue(&Q, pair);
	while (!empty(Q)) {
    	elementype pair = front(Q); dequeue(&Q);
		int u = pair.u, p = pair.p;
		if (mark[u] != 0)
			continue;

		mark[u] = 1;
		parent[u] = p;

		for (int v = 1; v <= pG->n; v++)
			if (adjacent(pG, u, v)) {
				elementype pair = { v, u };
				enqueue(&Q, pair);
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
			BFS(&G, u);

	for (int u = 1; u <= n; u++)
		printf("%d %d\n", u, parent[u]);
	return 0;
}
