#include <stdio.h>

#define MAX 9


int verificar(int M[MAX][MAX]) {
    int Vet[9];

    // Verificar linhas
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            for (int k = j + 1; k < MAX; k++) {
                if (M[i][j] == M[i][k]) {
                    return 0;
                }
            }
        }
    }

    // Verificar colunas
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            for (int k = j + 1; k < MAX; k++) {
                if (M[j][i] == M[k][i]) {
                    return 0;
                }
            }
        }
    }

    // Verificar blocos 3x3
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            int pos = 0;
            for (int i = 3 * x; i < 3 * (x + 1); i++) {
                for (int j = 3 * y; j < 3 * (y + 1); j++) {
                    Vet[pos] = M[i][j];
                    pos++;
                }
            }
            for (int i = 0; i < 9; i++) {
                for (int j = i + 1; j < 9; j++) {
                    if (Vet[i] == Vet[j]) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

int main() {
    int n;
    int M[MAX][MAX];

    scanf("%i", &n);
    for (int t = 1; t <= n; t++) {
        // Leitura da matriz 9x9
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                scanf("%i", &M[i][j]);
            }
        }

        printf("Instancia %i\n", t);
        if (verificar(M) == 1) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }
    return 0;
}
