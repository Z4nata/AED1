#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHAR 256
#define MAX_LEN 1005

typedef struct {
    int ascii;
    int freq;
} CharFreq;

int compare(const void *a, const void *b) {
    CharFreq *cf1 = (CharFreq *)a;
    CharFreq *cf2 = (CharFreq *)b;

    if (cf1->freq != cf2->freq)
        return cf1->freq - cf2->freq;
    
    return cf2->ascii - cf1->ascii;
}

int main() {
    char line[MAX_LEN];
    int first_output = 1;

    while (fgets(line, sizeof(line), stdin)) {
        int freq[MAX_CHAR] = {0};
        int len = strlen(line);

        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }

        for (int i = 0; i < len; i++) {
            freq[(unsigned char)line[i]]++;
        }

        CharFreq chars[MAX_CHAR];
        int count = 0;
        for (int i = 0; i < MAX_CHAR; i++) {
            if (freq[i] > 0) {
                chars[count].ascii = i;
                chars[count].freq = freq[i];
                count++;
            }
        }

        qsort(chars, count, sizeof(CharFreq), compare);

        if (!first_output) {
            printf("\n");
        }
        first_output = 0;

        // Imprimir o resultado
        for (int i = 0; i < count; i++) {
            printf("%d %d\n", chars[i].ascii, chars[i].freq);
        }
    }

    return 0;
}
