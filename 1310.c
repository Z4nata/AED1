#include <stdio.h>
#include <stdlib.h>

long long kadane(int N, int *margens) {
    long long current_max_local = 0;
    long long global_max = 0; 
    
    int i;
    for (i = 0; i < N; i++) {
        if (current_max_local + margens[i] > margens[i]) {
            current_max_local += margens[i];
        } else {
            current_max_local = margens[i];
        }
        
        if (current_max_local > global_max) {
            global_max = current_max_local;
        }
        
        if (current_max_local < 0) {
            current_max_local = 0;
        }
    }

    return global_max;
}


int main() {
    int N;             
    int custoPorDia;   
    
    while (scanf("%d", &N) != EOF) {
        if (scanf("%d", &custoPorDia) == EOF) {
            break; 
        }

        int *margens = (int *)malloc(N * sizeof(int));
        if (margens == NULL) {
            return 1;
        }

        int i;
        int receitaDiaria;
        
        for (i = 0; i < N; i++) {
            if (scanf("%d", &receitaDiaria) == EOF) {
                free(margens);
                return 1;
            }
            margens[i] = receitaDiaria - custoPorDia;
        }
        
        long long maxLucro = kadane(N, margens);
        
        printf("%lld\n", maxLucro);
        
        free(margens);
    }
    
    return 0;
}
