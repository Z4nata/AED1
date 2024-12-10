#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct cel {
    char Name[30];
    char ColorSize[30];
    struct cel *nxt;
} camisas;

void incluir_lista(char *N, char *CT, camisas *p) {
    camisas *New = (camisas *)malloc(sizeof(camisas));
    if (New == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    strcpy(New->Name, N);
    strcpy(New->ColorSize, CT);
    New->nxt = p->nxt;
    p->nxt = New;
}

void ordernar_lista(camisas *p) {
    if (p == NULL || p->nxt == NULL) {
        printf("Erro na ordenação. Lista vazia ou com um único elemento.\n");
        return;
    }

    camisas *l;
    int trocado;

    do {
        trocado = 0;

        for (l = p->nxt; l != NULL && l->nxt != NULL; l = l->nxt) {
            if (strcmp(l->Name, l->nxt->Name) > 0) {
               
                char Nometemp[30], CorTamtemp[30];

                
                strcpy(Nometemp, l->Name);
                strcpy(CorTamtemp, l->ColorSize);

                
                strcpy(l->Name, l->nxt->Name);
                strcpy(l->ColorSize, l->nxt->ColorSize);

                
                strcpy(l->nxt->Name, Nometemp);
                strcpy(l->nxt->ColorSize, CorTamtemp);

                trocado = 1;
            }
        }
    } while (trocado);
}

void imprimir_lista(camisas *p) {
    camisas *l;
    for (l = p->nxt; l != NULL; l = l->nxt) {
        printf("Nome: %s\tTamanho e Cor: %s\n", l->Name, l->ColorSize);
    }
}

int main() {
    camisas *Nova = (camisas *)malloc(sizeof(camisas));
    if (Nova == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }
    Nova->nxt = NULL;

    int N;
    char Nome[30];
    char CorTam[30];

    printf("Quantas camisas deseja produzir:\n");
    scanf("%i", &N);
    getchar(); 
    while (N > 0 && N <= 60) {
        printf("Nome:\n");
        fgets(Nome, sizeof(Nome), stdin);
        Nome[strcspn(Nome, "\n")] = '\0'; 

        printf("Cor e Tamanho:\n");
        fgets(CorTam, sizeof(CorTam), stdin);
        CorTam[strcspn(CorTam, "\n")] = '\0'; 

        incluir_lista(Nome, CorTam, Nova);
        N--;
    }

    printf("\nLista antes da ordenação:\n");
    imprimir_lista(Nova);

    ordernar_lista(Nova);

    printf("\nLista após a ordenação:\n");
    imprimir_lista(Nova);

    return 0;
}
