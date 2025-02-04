#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 5000
#define MAX_LENGTH 201

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int is_unique(char *word, char *dictionary[], int count) {
    for (int i = 0; i < count; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    char line[MAX_LENGTH];
    char word[MAX_LENGTH];
    char *dictionary[MAX_WORDS];
    int word_count = 0;

    while (fgets(line, sizeof(line), stdin)) {
        int len = strlen(line);
        int index = 0;

        for (int i = 0; i <= len; i++) {
            if (isalpha(line[i])) {
                word[index++] = tolower(line[i]);
            } else if (index > 0) {
                word[index] = '\0'; 

                if (is_unique(word, dictionary, word_count)) {
                    dictionary[word_count] = strdup(word);
                    word_count++;
                }
                index = 0; 
            }
        }
    }

    qsort(dictionary, word_count, sizeof(char *), compare);

    for (int i = 0; i < word_count; i++) {
        printf("%s\n", dictionary[i]);
        free(dictionary[i]); 
    }

    return 0;
}
