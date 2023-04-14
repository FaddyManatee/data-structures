#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "hashtable.h"


/**
 * Hashing function from:
 * URL: https://github.com/jamesroutley/write-a-hash-table/tree/master/03-hashing 
 */
int hash(const char *key, int prime, int buckets) {
    long hash = 0;
    const int length = strlen(key);
    for (int i = 0; i < length; i++) {
        hash += (long) pow(prime, length - (i + 1)) * key[i];
        hash = hash % buckets;
    }
    return (int) hash;
}


/**
 * Modified version of the PJW Hash (aka ELF Hash) to account
 * for number of buckets.
 * URL: https://en.wikipedia.org/wiki/PJW_hash_function
 */
int m_hashpjw(const char *key, int prime, int buckets) {
    unsigned long h = 0, high;
    while (*key)
    {
        h = (h << 4) + *key++;
        if (high = h & 0xF0000000)
            h ^= high >> 24;
        h &= ~high;
    }
    return h / buckets;
}


char* dupstr(const char *src) {
    int len = strlen(src) + 1;
    char *s = (char *) malloc(sizeof(char) * len);

    if (s == NULL)
        return NULL;
    return (char *) memcpy(s, src, len);
}


Bucket* newKeyValue(const char *key, const char *value) {
    Bucket *b = (Bucket *) malloc(sizeof(Bucket));
    // Store copies of key and value rather than references.
    b->key = dupstr(key);
    b->value = dupstr(value);
}


HashTable* newHashTable() {
    HashTable *table = (HashTable *) malloc(sizeof(HashTable));
    table->size = 6000;  // static for now.
    table->count = 0;
    // Null entries in the array indicate that the bucket is empty.
    table->buckets = (Bucket **) calloc(table->size, sizeof(Bucket *));
}


void freeHashTable(HashTable *table) {
    int x;
    for (x = 0; x < table->size; x++) {
        Bucket *b = table->buckets[x];
        if (b != NULL) {
            free(b->key);
            free(b->value);
            free(b);
        }
    }
    free(table->buckets);
    free(table);
}
