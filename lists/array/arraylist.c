#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"


/**
 * Creates a new list. Remember to free its resources when no longer needed.
 */
ArrayList* newArrayList(int maxSize) {
    ArrayList *list = (ArrayList *) malloc(sizeof(ArrayList));
    list->data = (int *) calloc(maxSize, sizeof(int));
    list->max = maxSize;
    list->size = 0;

    return list;
}


int newSize(int oldSize) {
    // Increase list size by x1.5 approx.
    return (oldSize * 3) / 2 - 1;
}


void shift(ArrayList *list, int start) {
    int x;
    for (x = list->size - 1; x >= start; x--) {
        if (x - 1 < 0)
            break;
        list->data[x] = list->data[x - 1];
    }
    list->data[start] = 0;
}


void copyInto(int *src, int *dest, int size) {
    int x;
    for (x = 0; x < size; x++)
        dest[x] = src[x];
}


ArrayList* grow(ArrayList *list) {
    ArrayList *new = (ArrayList *) malloc(sizeof(ArrayList));
    
    int size = newSize(list->max);
    new->data = (int *) calloc(size, sizeof(list->data[0]));
    copyInto(list->data, new->data, list->size);
    new->max = size;
    new->size = list->size;

    freeArrayList(list);
    return new;
}


/**
 * Frees all memory dynamically allocated to the list. 
 */
void freeArrayList(ArrayList *list) {
    free(list->data);
    free(list);
}


/**
 * Inserts a new element at the start of the list with value equal to 'data'.
 */
void insertStart(ArrayList *list, int data) {
    if (isEmpty(list)) {
        list->data[0] = data;
        return;
    }

    if (isFull(list))
        list = grow(list);

    // Shift all elements up the list by one.
    shift(list, 0);
    list->data[0] = data;
}


/**
 * Returns the data found at the list index.
 * Returns 0 if 'index' is out of bounds.  
 */
int getAt(ArrayList *list, int index) {
    if (index > list->size - 1 || index < 0)
        return 0;

    return list->data[index];
}


/**
 * Returns true (1) if the list is empty, false (0) otherwise. 
 */
int isEmpty(ArrayList *list) {
    if (list->size == 0)
        return 1;
    return 0;
}


/**
 * Returns true (1) if the list is full, false (0) otherwise. 
 */
int isFull(ArrayList *list) {
    if (list->size == list->max)
        return 1;
    return 0;
}
