#include <stdio.h>

#define MAX 100
#define NO_COLOR 0
#define BLUE 1
#define RED 2

typedef struct {
	int data[MAX];
	int topindex;
}Stack;

void make_null_stack(Stack* pS) {
	pS->topindex = -1;
}

void push_back(Stack* pS, int u) {
	pS->topindex++;
	pS->data[pS->topindex] = u;
}

void pop_back(Stack* pS) {
	pS->topindex--;
}

int top(Stack* pS) {
	return pS->data[pS->topindex];
}

int empty(Stack* pS) {
	return pS->topindex == -1;
}

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
		if ((pG->edges[e].u == u && pG->edges[e].v == v))
			return 1;
	return 0;
}

int num[MAX], min_num[MAX];
int k;
Stack S;
int on_stack[MAX];

int min(int a, int b) {
	return (a > b ? b : a);
}

int cnt = 0;
int strong_connect = 0;

void SCC(Graph* pG, int u) {
	num[u] = min_num[u] = k; k++;
	push_back(&S, u);
	on_stack[u] = 1;

	for (int v = 1; v <= pG->n; v++) {
		if (adjacent(pG, u, v)) {
			if (num[v] < 0) {
				SCC(pG, v);
				min_num[u] = min(min_num[u], min_num[v]);
			}
			else if (on_stack[v])
				min_num[u] = min(min_num[u], num[v]);
		}
	}

	if (num[u] == min_num[u]) {
		cnt++;
		int w;
		do {
			w = top(&S);
			pop_back(&S);
			on_stack[w] = 0;
		} while (w != u);
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
	
	for (int u = 1; u <= G.n; u++) {
		num[u] = -1;
		on_stack[u] = 0;
	}

	k = 1;
	make_null_stack(&S);


	for (int u = 1; u <= G.n; u++)
		if (num[u] == -1) {
			SCC(&G, u);
		}
	
	printf("%d", cnt);

	return 0;
}
