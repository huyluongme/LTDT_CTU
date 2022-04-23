#include <stdio.h>
#define MAX_N 100

typedef struct {
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;

int main() {
    int n;
    Graph G;
    scanf("%d", &n);
    for(int u = 1; u <= n; u++)
        for(int v = 1; v <= n; v++)
            scanf("%d", &G.A[u][v]);

    for(int u = 1; u <= n; u++){
        for(int v = 1; v <= n; v++){
            for(int i = 0; i < G.A[u][v]; i++)
                printf("%d ", v);
        }
        printf("0\n");
    }
    return 0;
}