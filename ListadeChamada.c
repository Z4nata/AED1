#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    
    char alunos[N][21];
    
    for (int i = 0; i < N; i++) {
        scanf("%s", alunos[i]);
    }
    
    qsort(alunos, N, sizeof(alunos[0]), compare);
    
    printf("%s\n", alunos[K - 1]);

    return 0;
}
