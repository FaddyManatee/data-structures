#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "hashtable.h"

#define PRIME_1 211
#define PRIME_2 163

// Sentinel value.
Bucket DELETED = {.key = NULL, .value = NULL};


/**
 * Hashing function from:
 * URL: https://github.com/jamesroutley/write-a-hash-table/tree/master/03-hashing 
 */
int hash(const char *key, int prime, int buckets) {
    long hash = 0;
    int length = strlen(key);

    int i;
    for (i = 0; i < length; i++) {
        hash += (long) pow(prime, length - (i + 1)) * key[i];
        hash %= buckets;
    }
    return (int) hash;
}


// Handle collisions using open addressing with double hashing.
int dubHash(const char* s, int buckets, int attempt) {
    int a = hash(s, PRIME_1, buckets);
    int b = hash(s, PRIME_2, buckets);
    return (a + (attempt * (b + 1))) % buckets;
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
    table->used = 0;
    // Null entries in the array indicate that the bucket is empty.
    table->buckets = (Bucket **) calloc(table->size, sizeof(Bucket *));
}


void freeBucket(Bucket *bucket) {
    free(bucket->key);
    free(bucket->value);
    free(bucket);
}


void freeHashTable(HashTable *table) {
    int x;
    for (x = 0; x < table->size; x++) {
        Bucket *b = table->buckets[x];
        if (b != NULL) {
            freeBucket(b);
        }
    }
    free(table->buckets);
    free(table);
}


void deletePair(HashTable *table, char *key) {
    int attempt = 0;
    int index = dubHash(key, table->size, attempt++);
    Bucket *cur = table->buckets[index];
    
    while (cur != NULL) {
        if (cur != &DELETED) {
            if (strcmp(cur->key, key) == 0) {
                freeBucket(cur);
                table->buckets[index] = &DELETED;
            }
        }
        index = dubHash(key, table->size, attempt++);
        cur = table->buckets[index];
    } 
    table->used--;
}


void insertPair(HashTable *table, char *key, char *value) {
    int attempt = 0;
    int index = dubHash(new->key, table->size, attempt++);
    Bucket *cur = table->buckets[index];
    Bucket *new = newKeyValue(key, value);

    // Resolve hash collisions (iterate until empty bucket found).
    while (cur != NULL) {
        if (cur != &DELETED) {
            if (strcmp(cur->key, key) == 0) {
                deletePair(table, cur);
                table->buckets[index] = new;
                return;
            }
        }
        index = dubHash(new->key, table->size, attempt++);
        cur = table->buckets[index];
    }
    table->buckets[index] = new;
    table->used++;
}


char* lookup(HashTable *table, char *key) {
    int attempt = 0;
    int index = dubHash(key, table->size, attempt++);
    Bucket *cur = table->buckets[index];
    
    while (cur != NULL) {
        if (cur != &DELETED) {
            if (strcmp(cur->key, key) == 0)
                return cur->value;
        }

        index = dubHash(key, table->size, attempt++);
        cur = table->buckets[index];
    } 
    return NULL;
}
