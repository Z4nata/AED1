#include <stdio.h>
#include <string.h>

#define MAX_AMIGOS 1000
#define MAX_NOME 21

void inserir_amigos(char lista[][MAX_NOME], int *total, char nova_lista[][MAX_NOME], int total_novos, char *amigo_indicado) {
    int pos_insercao = *total; // Posição de inserção por padrão é o final da lista

    if (strcmp(amigo_indicado, "nao") != 0) {
        for (int i = 0; i < *total; i++) {
            if (strcmp(lista[i], amigo_indicado) == 0) {
                pos_insercao = i;
                break;
            }
        }
    }

    if (pos_insercao < *total) {
        for (int i = *total - 1; i >= pos_insercao; i--) {
            strcpy(lista[i + total_novos], lista[i]);
        }
    }

    for (int i = 0; i < total_novos; i++) {
        strcpy(lista[pos_insercao + i], nova_lista[i]);
    }

    *total += total_novos;
}

int main() {
    char lista_amigos[MAX_AMIGOS][MAX_NOME];
    char nova_lista[MAX_AMIGOS][MAX_NOME];
    char amigo_indicado[MAX_NOME];
    int total_amigos = 0, total_novos = 0;

    char linha[10000];
    fgets(linha, sizeof(linha), stdin);
    char *token = strtok(linha, " \n");
    while (token != NULL) {
        strcpy(lista_amigos[total_amigos++], token);
        token = strtok(NULL, " \n");
    }

    fgets(linha, sizeof(linha), stdin);
    token = strtok(linha, " \n");
    while (token != NULL) {
        strcpy(nova_lista[total_novos++], token);
        token = strtok(NULL, " \n");
    }

    fgets(amigo_indicado, sizeof(amigo_indicado), stdin);
    amigo_indicado[strcspn(amigo_indicado, "\n")] = '\0';  // Remove o '\n' do final

    inserir_amigos(lista_amigos, &total_amigos, nova_lista, total_novos, amigo_indicado);

    for (int i = 0; i < total_amigos; i++) {
        printf("%s", lista_amigos[i]);
        if (i < total_amigos - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
