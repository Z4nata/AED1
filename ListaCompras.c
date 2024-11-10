#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITEMS 1000
#define MAX_LENGTH 21

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int remove_duplicates(char *items[], int count) {
    int unique_count = 0;
    for (int i = 0; i < count; i++) {
        if (i == 0 || strcmp(items[i], items[i - 1]) != 0) {
            items[unique_count++] = items[i];
        }
    }
    return unique_count;
}

int main() {
    int n;
    scanf("%d\n", &n);  

    for (int i = 0; i < n; i++) {
        char line[20000];  
        fgets(line, sizeof(line), stdin);

        char *items[MAX_ITEMS];
        int item_count = 0;

        
        char *token = strtok(line, " \n");
        while (token != NULL) {
            items[item_count++] = token;
            token = strtok(NULL, " \n");
        }

   
        qsort(items, item_count, sizeof(char *), compare);

        
        item_count = remove_duplicates(items, item_count);

        
        for (int j = 0; j < item_count; j++) {
            printf("%s", items[j]);
            if (j < item_count - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
