#include <stdio.h>
#include <limits.h>

#define INF 1000000000

int main() {
    int N, E;

    while (1) {
        scanf("%d %d", &N, &E);
        if (N == 0 && E == 0) break;

        int grafo[501][501];

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                grafo[i][j] = INF;

        for (int i = 0; i < E; i++) {
            int X, Y, H;
            scanf("%d %d %d", &X, &Y, &H);

            // Se já existe Y -> X, ambos viram 0
            if (grafo[Y][X] != INF) {
                grafo[X][Y] = 0;
                grafo[Y][X] = 0;
            } else {
                grafo[X][Y] = H;
            }
        }

        int K;
        scanf("%d", &K);

        while (K--) {
            int O, D;
            scanf("%d %d", &O, &D);

            int dist[501], vis[501];

            for (int i = 1; i <= N; i++) {
                dist[i] = INF;
                vis[i] = 0;
            }

            dist[O] = 0;

            for (int i = 1; i <= N; i++) {
                int u = -1;
                int menor = INF;

                for (int j = 1; j <= N; j++) {
                    if (!vis[j] && dist[j] < menor) {
                        menor = dist[j];
                        u = j;
                    }
                }

                if (u == -1) break;

                vis[u] = 1;

                for (int v = 1; v <= N; v++) {
                    if (grafo[u][v] < INF && !vis[v]) {
                        if (dist[u] + grafo[u][v] < dist[v]) {
                            dist[v] = dist[u] + grafo[u][v];
                        }
                    }
                }
            }

            if (dist[D] == INF)
                printf("Nao e possivel entregar a carta\n");
            else
                printf("%d\n", dist[D]);
        }

        printf("\n");
    }

    return 0;
}
