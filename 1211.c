#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100005
#define MAX_LEN 205

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int longest_common_prefix(const char *a, const char *b) {
    int count = 0;
    while (*a && *b && *a == *b) {
        count++;
        a++;
        b++;
    }
    return count;
}

int main() {
    int N;
    char *phones[MAX_N];
    char buffer[MAX_LEN];

    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++) {
            scanf("%s", buffer);
            phones[i] = strdup(buffer); 
        }

        qsort(phones, N, sizeof(char *), compare);

        int total_savings = 0;
        for (int i = 1; i < N; i++) {
            total_savings += longest_common_prefix(phones[i], phones[i-1]);
        }

        printf("%d\n", total_savings);

        
        for (int i = 0; i < N; i++) {
            free(phones[i]);
        }
    }

    return 0;
}
