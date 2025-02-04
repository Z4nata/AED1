#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        int M;
        scanf("%d", &M);

        int notas[M];      
        int notasOrdenadas[M]; 

        for (int i = 0; i < M; i++) {
            scanf("%d", &notas[i]);
            notasOrdenadas[i] = notas[i]; 
        }

        qsort(notasOrdenadas, M, sizeof(int), compare);

        int naoTrocaram = 0;
        for (int i = 0; i < M; i++) {
            if (notas[i] == notasOrdenadas[i]) {
                naoTrocaram++;
            }
        }

        printf("%d\n", naoTrocaram);
    }

    return 0;
}
