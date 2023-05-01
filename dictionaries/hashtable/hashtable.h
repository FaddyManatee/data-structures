typedef struct Bucket {
    char *key;
    char *value;
} Bucket;


typedef struct HashTable {
    Bucket **buckets;  // Array of pointers to buckets.
    int      size;     // Total buckets/capacity of hash table.
    int      used;    // Number of buckets filled.
} HashTable;


HashTable* newHashTable();
void freeHashTable(HashTable *table);
void deletePair(HashTable *table, char *key);
void insertPair(HashTable *table, char *key, char *value);
char* lookup(HashTable *table, char *key);
