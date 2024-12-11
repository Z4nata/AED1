#include <stdio.h>
#include <stdlib.h>

// Função para mesclar duas subarrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Tamanho do subarray esquerdo
    int n2 = right - mid;    // Tamanho do subarray direito

    // Arrays temporários para armazenar os subarrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copia os elementos para os subarrays temporários
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Mescla os subarrays de volta no array original
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Libera a memória alocada
    free(L);
    free(R);
}

// Função recursiva para dividir o array e ordenar
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Calcula o índice do meio

        // Ordena recursivamente as duas metades
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Mescla as duas metades
        merge(arr, left, mid, right);
    }
}

// Função auxiliar para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Programa principal para testar o Merge Sort
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    printf("Array ordenado:\n");
    printArray(arr, size);

    return 0;
}
