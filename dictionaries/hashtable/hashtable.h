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

// Remove these later.
int hash(const char *s, int prime, int buckets);
int m_hashpjw(const char *s, int prime, int buckets);
