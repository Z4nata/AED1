#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 50
#define MAX_LENGTH 51

void stableSort(char palavras[][MAX_LENGTH], int tam) {
    char aux[MAX_LENGTH];
    for (int i = 1; i < tam; i++) {
        strcpy(aux, palavras[i]);
        int j = i - 1;

        while (j >= 0 && strlen(aux) > strlen(palavras[j])) {
            strcpy(palavras[j + 1], palavras[j]);
            j--;
        }
        strcpy(palavras[j + 1], aux);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();  

    for (int k = 0; k < N; k++) {
        char linha[3000];  
        char palavras[MAX_STRINGS][MAX_LENGTH];
        int tam = 0;

        fgets(linha, sizeof(linha), stdin);
        linha[strcspn(linha, "\n")] = '\0'; 

        char *ptr = strtok(linha, " ");
        while (ptr != NULL) {
            strcpy(palavras[tam++], ptr);
            ptr = strtok(NULL, " ");
        }

        stableSort(palavras, tam);

        printf("%s", palavras[0]);
        for (int i = 1; i < tam; i++) {
            printf(" %s", palavras[i]);
        }
        printf("\n");
    }

    return 0;
}
