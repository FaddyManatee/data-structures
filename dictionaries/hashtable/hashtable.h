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
void freeHashTable();

// Remove these.
int hash(const char *s, int prime, int buckets);
int hashfad(char *s, int prime, int buckets);
