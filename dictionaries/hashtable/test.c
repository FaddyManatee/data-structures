#include <stdio.h>
#include "hashtable.h"

int main(int argc, char **argv) {
    HashTable *table = newHashTable();
    printf("%p\n\n", table);

    printf("%d\n", hash("hello", 211, table->size));
    printf("%d\n", hash("hello1", 211, table->size));
    printf("%d\n", hash("world!", 211, table->size));
    printf("%d\n\n", hash("t4verns", 211, table->size));

    printf("%d\n", hashfad("hello", 211, table->size));
    printf("%d\n", hashfad("hello1", 211, table->size));
    printf("%d\n", hashfad("world!", 211, table->size));
    printf("%d\n", hashfad("t4verns", 211, table->size));

    freeHashTable(table);

    return 0;
}