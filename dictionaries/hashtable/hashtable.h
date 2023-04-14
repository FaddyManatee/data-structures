typedef struct Bucket {
    char *key;
    char *value;
} Bucket;


typedef struct HashTable {
    Bucket **buckets;  // Array of pointers to buckets.
    int      size;
    int      count;
} HashTable;


HashTable* newHashTable();
void freeHashTable(HashTable *table);
void insertPair(HashTable *table, char *key, char *value);
