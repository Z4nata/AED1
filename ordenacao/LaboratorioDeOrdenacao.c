#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000  // tamanho máximo do vetor

// ===================== ALGORITMOS =====================

// ---------- INSERTION SORT ----------
void insertionSort(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}

// ---------- SELECTION SORT ----------
void selectionSort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (v[j] < v[min])
                min = j;
        int temp = v[i];
        v[i] = v[min];
        v[min] = temp;
    }
}

// ---------- MERGE SORT ----------
void merge(int v[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = v[inicio + i];
    for (int j = 0; j < n2; j++) R[j] = v[meio + 1 + j];

    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) v[k++] = L[i++];
        else v[k++] = R[j++];
    }

    while (i < n1) v[k++] = L[i++];
    while (j < n2) v[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}

// ---------- QUICK SORT ----------
void quickSort(int v[], int inicio, int fim) {
    int i = inicio, j = fim;
    int pivo = v[(inicio + fim) / 2];

    while (i <= j) {
        while (v[i] < pivo) i++;
        while (v[j] > pivo) j--;
        if (i <= j) {
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }
    }

    if (inicio < j) quickSort(v, inicio, j);
    if (i < fim) quickSort(v, i, fim);
}

// ---------- HEAP SORT ----------
void heapify(int v[], int n, int i) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && v[esq] > v[maior]) maior = esq;
    if (dir < n && v[dir] > v[maior]) maior = dir;

    if (maior != i) {
        int temp = v[i];
        v[i] = v[maior];
        v[maior] = temp;
        heapify(v, n, maior);
    }
}

void heapSort(int v[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(v, n, i);
    for (int i = n - 1; i > 0; i--) {
        int temp = v[0];
        v[0] = v[i];
        v[i] = temp;
        heapify(v, i, 0);
    }
}

// ===================== FUNÇÕES AUXILIARES =====================

void preencherVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 100000;
    }
}

void copiarVetor(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++)
        destino[i] = origem[i];
}

void mostrarVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

// ===================== LABORATÓRIO =====================

void testarAlgoritmo(void (*sort)(int[], int), int v[], int n, char nome[]) {
    int *temp = malloc(n * sizeof(int));
    copiarVetor(v, temp, n);

    clock_t inicio = clock();
    sort(temp, n);
    clock_t fim = clock();

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("%-15s -> Tempo: %.6f segundos\n", nome, tempo);

    free(temp);
}

void testarMergeQuickHeap(int v[], int n) {
    int *temp = malloc(n * sizeof(int));

    // Merge Sort
    copiarVetor(v, temp, n);
    clock_t t1 = clock();
    mergeSort(temp, 0, n - 1);
    clock_t t2 = clock();
    printf("%-15s -> Tempo: %.6f segundos\n", "Merge Sort", (double)(t2 - t1) / CLOCKS_PER_SEC);

    // Quick Sort
    copiarVetor(v, temp, n);
    t1 = clock();
    quickSort(temp, 0, n - 1);
    t2 = clock();
    printf("%-15s -> Tempo: %.6f segundos\n", "Quick Sort", (double)(t2 - t1) / CLOCKS_PER_SEC);

    // Heap Sort
    copiarVetor(v, temp, n);
    t1 = clock();
    heapSort(temp, n);
    t2 = clock();
    printf("%-15s -> Tempo: %.6f segundos\n", "Heap Sort", (double)(t2 - t1) / CLOCKS_PER_SEC);

    free(temp);
}

// ===================== MAIN =====================

int main() {
    srand(time(NULL));

    int n;
    printf("Tamanho do vetor para teste: ");
    scanf("%d", &n);
    if (n > MAX) n = MAX;

    int *v = malloc(n * sizeof(int));
    preencherVetor(v, n);

    printf("\n===== TESTANDO ORDENAÇÕES =====\n");

    if (n <= 10000) { // insertion e selection só pra vetores menores
        testarAlgoritmo(insertionSort, v, n, "Insertion Sort");
        testarAlgoritmo(selectionSort, v, n, "Selection Sort");
    } else {
        printf("(Insertion e Selection ignorados por tamanho grande)\n");
    }

    testarMergeQuickHeap(v, n);

    free(v);
    return 0;
}
