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
	int data[MAX];
	int front, rear;
}queue;

void make_null_queue(queue* pQ) {
	pQ->front = 0;
	pQ->rear = -1;
}

void enqueue(queue* pQ, int u) {
	pQ->rear++;
	pQ->data[pQ->rear] = u;
}

void dequeue(queue* pQ) {
	pQ->front++;
}

int front(queue Q) {
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

int adjacent(Graph *pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if (pG->edges[e].u == u && pG->edges[e].v == v)
			return 1;
	return 0;
}

int mark[MAX];

void BFS(Graph* pG, int u) {
	queue Q;
	make_null_queue(&Q);
	enqueue(&Q, u);
	while (!empty(Q)) {
		int s = front(Q);
		dequeue(&Q);
		if (mark[s] != 0)
			continue;

		printf("%d\n", s);
		mark[s] = 1;

		for (int v = 1; v <= pG->n; v++)
			if (adjacent(pG, s, v))
				enqueue(&Q, v);
	}
}

int main() {
	int n, m, s;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}

	scanf("%d", &s);
	BFS(&G, s);
	return 0;
}
