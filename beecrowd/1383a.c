#include <stdio.h>

// A função retorna 1 para SIM (solução válida) e 0 para NAO.
int is_sudoku_solution(int g[9][9]) {
    
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
        int g[9][9];
        
        // Leitura da matriz
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
    }
    
    return 0;
}
