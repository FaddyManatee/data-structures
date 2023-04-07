/**
 * Wrapper for arraylist data. 
 */
typedef struct ArrayList {
    int *data;
    int size;
    int max;
} ArrayList;

ArrayList* newArrayList(int size);
int getAt(ArrayList *list, int index);
int isEmpty(ArrayList *list);
int isFull(ArrayList *list);
void freeArrayList(ArrayList *list);
void insertStart(ArrayList *list, int data);
void insertEnd(ArrayList *list, int data);
void insertAfter(ArrayList *list, int index, int data);
void printList(ArrayList *list);
