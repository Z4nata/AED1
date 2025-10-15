#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int NC;
    scanf("%d", &NC);

    while (NC--) {
        int N;
        scanf("%d", &N);
        int *alturas = (int*) malloc(N * sizeof(int));

        for (int i = 0; i < N; i++) {
            scanf("%d", &alturas[i]);
        }

        insertion_sort(alturas, N);

        for (int i = 0; i < N; i++) {
            if (i > 0) printf(" ");
            printf("%d", alturas[i]);
        }
        printf("\n");

        free(alturas);
    }

    return 0;
}
