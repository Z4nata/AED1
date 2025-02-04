#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 105

typedef struct equipe {
    int qts_pontos; // Quantos pontos a equipe tem
    int marcadas;   // Gols marcados pela equipe
    int sofridas;   // Gols sofridos pela equipe
    int id;         // Identificador da equipe
} equipe;

// Função de comparação para ordenar as equipes
int compara(const void *a, const void *b) {
    equipe *e1 = (equipe *)a;
    equipe *e2 = (equipe *)b;

    if (e1->qts_pontos == e2->qts_pontos) {
        if (e1->sofridas == 0) e1->sofridas = 1;
        if (e2->sofridas == 0) e2->sofridas = 1;

        float ratio1 = (float)e1->marcadas / e1->sofridas;
        float ratio2 = (float)e2->marcadas / e2->sofridas;

        if (ratio1 == ratio2) {
            if (e1->marcadas == e2->marcadas) {
                return (e1->id < e2->id) ? -1 : 1;
            } else {
                return (e1->marcadas > e2->marcadas) ? -1 : 1;
            }
        } else {
            return (ratio1 > ratio2) ? -1 : 1;
        }
    }
    return (e1->qts_pontos > e2->qts_pontos) ? -1 : 1;
}

int main() {
    int n, i;
    int instancia = 0;
    int id1, id2, pt1, pt2;

    // Cria o array de times
    equipe times[MAXSIZE];

    while (scanf("%d", &n) && n != 0) {
        if (instancia > 0) {
            printf("\n");
        }

        // Reseta os dados dos times
        memset(times, 0, sizeof(times));

        unsigned short tmp = n * (n - 1) / 2;  // Substituindo 'us' por 'unsigned short'
        for (i = 0; i < tmp; ++i) {
            scanf("%d %d %d %d", &id1, &pt1, &id2, &pt2);

            if (pt1 > pt2) {
                times[id1].qts_pontos += 2;
                times[id2].qts_pontos += 1;
            } else {
                times[id2].qts_pontos += 2;
                times[id1].qts_pontos += 1;
            }

            times[id1].marcadas += pt1;
            times[id1].sofridas += pt2;
            times[id2].marcadas += pt2;
            times[id2].sofridas += pt1;

            times[id1].id = id1;
            times[id2].id = id2;
        }

        qsort(&times[1], n, sizeof(equipe), compara);

        // Imprime o resultado da instância
        printf("Instancia %d\n", ++instancia);
        for (i = 1; i <= n; ++i) {
            if (i > 1) {
                printf(" ");
            }
            printf("%d", times[i].id);
        }
        printf("\n");
    }

    return 0;
}
