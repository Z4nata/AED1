#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 26

int visitados[MAXSIZE];
char adj[MAXSIZE][MAXSIZE];
char vertices[MAXSIZE];
int tam, m, n;

void dfs(int);
int compara(const void *, const void *);

int main() {
    int casos, caso = 0;
    char a, b;

    scanf("%d", &casos);

    while (casos--) {
        scanf("%d %d", &m, &n);

        // Resetando estruturas
        memset(adj, 0, sizeof(adj));
        memset(visitados, 0, sizeof(visitados));

        // Lendo as conexões
        for (int i = 0; i < n; ++i) {
            scanf(" %c %c", &a, &b);
            adj[a - 'a'][b - 'a'] = 1;
            adj[b - 'a'][a - 'a'] = 1;
        }

        printf("Case #%d:\n", ++caso);

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            if (!visitados[i]) {
                tam = 0;  // Resetando o tamanho antes de cada DFS
                ++ans;
                dfs(i);
                qsort(vertices, tam, sizeof(char), compara);

                // Imprimindo componente conexo ordenado
                for (int j = 0; j < tam; ++j)
                    printf("%c,", vertices[j] + 'a');
                printf("\n");
            }
        }

        printf("%d connected components\n\n", ans);
    }

    return 0;
}

// Busca em profundidade (DFS)
void dfs(int u) {
    visitados[u] = 1;
    vertices[tam++] = u;
    
    for (int i = 0; i < MAXSIZE; ++i) {
        if (adj[u][i] && !visitados[i])
            dfs(i);
    }
}

// Função de comparação para qsort
int compara(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}
