#include <stdio.h>

// Função para executar o Insertion Sort
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];  // Elemento a ser inserido no subarray ordenado
        int j = i - 1;

        // Move os elementos do subarray ordenado para encontrar a posição do 'key'
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insere o 'key' na posição correta
        arr[j + 1] = key;
    }
}

// Função auxiliar para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Programa principal para testar o Insertion Sort
int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, size);

    insertionSort(arr, size);

    printf("Array ordenado:\n");
    printArray(arr, size);

    return 0;
}
