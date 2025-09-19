#include <stdio.h>
#include <stdlib.h> // Necessário para as funções malloc e free

// A função agora recebe um ponteiro para ponteiro (matriz alocada dinamicamente)
int is_sudoku_solution(int **g) {
    
    // 1. Verifica linhas e colunas
    for (int i = 0; i < 9; i++) {
        int r[10] = {0}; // Rastreia números da linha
        int c[10] = {0}; // Rastreia números da coluna
        
        for (int j = 0; j < 9; j++) {
            // Verifica a linha
            int rn = g[i][j];
            if (rn < 1 || rn > 9 || r[rn]) {
                return 0;
            }
            r[rn] = 1;
            
            // Verifica a coluna
            int cn = g[j][i];
            if (cn < 1 || cn > 9 || c[cn]) {
                return 0;
            }
            c[cn] = 1;
        }
    }
    
    // 2. Verifica as sub-matrizes 3x3
    for (int br = 0; br < 3; br++) {
        for (int bc = 0; bc < 3; bc++) {
            int s[10] = {0}; // Rastreia números da sub-matriz
            
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int num = g[br * 3 + i][bc * 3 + j];
                    if (num < 1 || num > 9 || s[num]) {
                        return 0;
                    }
                    s[num] = 1;
                }
            }
        }
    }
    
    // Se passar em todas as verificações
    return 1;
}

int main() {
    int n, k;
    scanf("%d", &n);
    
    for (k = 1; k <= n; k++) {
        // Alocação dinâmica da matriz 9x9
        int **g = (int **)malloc(9 * sizeof(int *));
        if (g == NULL) {
            return 1; // Erro de alocação
        }
        for (int i = 0; i < 9; i++) {
            g[i] = (int *)malloc(9 * sizeof(int));
            if (g[i] == NULL) {
                // Em caso de falha, liberar a memória já alocada
                for (int j = 0; j < i; j++) {
                    free(g[j]);
                }
                free(g);
                return 1;
            }
        }
        
        // Leitura dos dados para a matriz alocada dinamicamente
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &g[i][j]);
            }
        }
        
        printf("Instancia %d\n", k);
        if (is_sudoku_solution(g)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
        
        // ** LIBERAR A MEMÓRIA ALOCADA **
        for (int i = 0; i < 9; i++) {
            free(g[i]);
        }
        free(g);
    }
    
    return 0;
}
