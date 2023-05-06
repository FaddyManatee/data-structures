#include <stdio.h>
#include "hashtable.h"

int main(int argc, char **argv) {
    HashTable *table = newHashTable(20);
    insertPair(table, "JustMatt", "Owner");
    insertPair(table, "jstoeckm2", "Administrator 1");
    insertPair(table, "Rubyo3000", "Administrator 2");
    insertPair(table, "Marijke2000", "Administrator 3");
    insertPair(table, "Protabular", "Administrator 4");
    insertPair(table, "Janice999", "Administrator 5");
    insertPair(table, "iamimemi", "Moderator 1");
    insertPair(table, "FaddyManatee", "Moderator 2");
    insertPair(table, "Weajen", "Moderator 3");
    insertPair(table, "LifeWithFantasy", "Moderator 4");
    insertPair(table, "InfectedSquirrel", "Moderator 5");
    insertPair(table, "SVTheBest", "Moderator 6");
    insertPair(table, "Alikenila", "Assistant 1");

    // Let's print the hash table.
    printHashTable(table);

    printf("\nLookup\n");
    
    // role = "Moderator 2?"
    char *role = lookup(table, "FaddyManatee");
    if (role == NULL)
        printf("Lookup found nothing for 'FaddyManatee'...\n");
    else
        printf("Value found for key 'FaddyManatee' -> %s\n", role);


    // role = NULL "Lookup found nothing..."
    role = lookup(table, "Protabular");
    if (role == NULL)
        printf("Lookup found nothing for 'Protabular'...\n");
    else
        printf("Value found for key 'Protabular' -> %s\n", role);

    
    // role = NULL "Lookup found nothing..."
    role = lookup(table, "Noobtabular");
    if (role == NULL)
        printf("Lookup found nothing for 'Noobtabular'...\n");
    else
        printf("Value found for key 'Noobtabular' -> %s\n", role);


    // role = NULL "Lookup found nothing..."
    role = lookup(table, "Daphsquid");
    if (role == NULL)
        printf("Lookup found nothing for 'Daphsquid'...\n");
    else
        printf("Value found for key 'Daphsquid' -> %s\n", role);


    // role = NULL "Lookup found nothing..."
    role = lookup(table, "sh2mrr5");
    if (role == NULL)
        printf("Lookup found nothing for 'sh2mrr5'...\n");
    else
        printf("Value found for key 'sh2mrr5' -> %s\n", role);


    // role = NULL "Lookup found nothing..."
    role = lookup(table, "Nistune");
    if (role == NULL)
        printf("Lookup found nothing for 'Nistune'...\n");
    else
        printf("Value found for key 'Nistune' -> %s\n", role);


    // Delete item with key "Alikenila".
    printf("\nDeletion\n");
    deletePair(table, "Alikenila");
    printHashTable(table);

    // Insert item with key "QStatic".
    printf("\nFollowed by insertion\n");
    insertPair(table, "QStatic", "Assistant 2");
    insertPair(table, "Nistune", "Assistant 3");
    printHashTable(table);

    // Promote Weajen to sixth Administrator 😮
    printf("\nUpdate\n");
    insertPair(table, "Weajen", "Administrator 6");
    printHashTable(table);


    // Add back a deleted item. Should take same bucket index if not taken.
    printf("\nReinstate deleted key-value pair\n");
    insertPair(table, "Alikenila", "Assistant 1");
    printHashTable(table);

    freeHashTable(table);
    return 0;
}
