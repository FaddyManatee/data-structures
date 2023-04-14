#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

#define ARRAYSIZEM(b) (sizeof(b)/sizeof(b[0]))
#define PRIME 13
#define MAX_LINES 6000
#define MAX_LINE_LENGTH 50


int contains(int *list, int item, int size) {
    int x;
    for (x = 0; x < size; x++) {
        if (list[x] == item) {
            return 1;
        }
    }
    return 0;
}


void printHashes(int *list, int size) {
    printf("%d", list[0]);

    int x;
    for (x = 1; x < size; x++) {
        printf(", %d", list[x]);
    }
    printf("\n\n");
}


int main(int argc, char **argv) {
    // Read keys to hash from file.
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char str[MAX_LINES][MAX_LINE_LENGTH];
    int count = 0;

    fp = fopen("keys.txt", "r");
    if (fp == NULL)
        exit(-1);

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        strncpy(str[count], line, MAX_LINE_LENGTH);
        count++;

        if (count == MAX_LINES)
            break;
    }
    fclose(fp);


    HashTable *table = newHashTable();

    int (*func[])(const char*, int, int) = {hash, m_hashpjw};
    int x, y, col = 0;
    int *hashes;
    for (x = 0; x < ARRAYSIZEM(func); x++) {
        hashes = (int *) calloc(count, sizeof(int));

        for (y = 0; y < count; y++) {
            hashes[y] = (*func[x])(str[y], PRIME, table->size);

            if (contains(hashes, hashes[y], y - 1))
                col++;
        }
        printf("Number of collisions: %d\n", col);
        //printHashes(hashes, y);
        free(hashes);
        col = 0;
    }
    freeHashTable(table);

    return 0;
}
