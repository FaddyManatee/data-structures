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
 * Modified version of hashpjw() to account for number of buckets.
 * Original from Compilers - Principles, Techniques, and Tools:
 * Aho, A. Sethi, R. Ullman, J. 1986. Bell Telephone Laboratories.
 */
int hashfad(char *key, int prime, int buckets) {
    char *p;
    unsigned int h = 0, g;
    for (p = key; *p != '\0'; p++) {
        h = (h << 24) + (*p);
        if (g = h & 0xf0000000) {
            h = h ^ (g >> 24);
            h = h ^ g;
        }
    }
    //original: return h % prime;
    return ((h / prime) % buckets);
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
    table->size = 123;  // static for now.
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
