#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

// Start of linked list methods.

/**
 * Creates a new list. Remember to free its resources when no longer needed.
 */
LinkedList* newLinkedList() {
    LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));
    list->start = NULL;
    list->end = NULL;
    list->size = 0;

    return list;
}


/**
 * Creates a new node. 
 */
Node* newNode(int data) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    return node;
}


void freeNode(Node *node) {
    // Free the node itself and any of its members allocated memory.
    free(node);
}


/**
 * Frees all memory dynamically allocated to the list, including its nodes. 
 */
void freeLinkedList(LinkedList *list) {
    Node *iterator = list->start;
    Node *next;

    while (1) {
        next = iterator->next;
        freeNode(iterator);

        if (next == NULL)
            break;
        iterator = next;
    }
    free(list);
}


/**
 * Adds the node to the end of the list.
 */
void insertEnd(LinkedList *list, Node *new) {
    if (list->start == NULL) {
        // Adding a node to the list if it is empty.
        list->start = new;
        list->end = new;
        new->next = NULL;
    }
    else {
        // Adding a node to the end of a non-empty list.
        Node *end = list->end;
        end->next = new;
        new->next = NULL;
        list->end = new;
    }

    // Increase list size, we have added a node.
    list->size++;
}


/**
 * Inserts the new node after the specified node in the list.
 */
void insertAfter(LinkedList *list, Node *node, Node *new) {
    if (list->size != 0) {
        if (list->size == 1 || node == list->end)
            insertEnd(list, new);  // Equivalent to adding the node to an empty list. This call will increase list size.
        
        else {
            new->next = node->next;
            node->next = new;

            // Increase list size, we have added a node.
            list->size++;
        }
    }
}


/**
 * Returns a pointer to the first node (head) of the list. 
 */
Node* firstNode(LinkedList *list) {
    return list->start;
}


/**
 * Returns a pointer to the last node (tail) of the list.
 */
Node* lastNode(LinkedList *list) {
    return list->end;
}


/**
 * Prints the list.
 */
void printList(LinkedList *list) {
    Node *iterator = list->start;
    while (1) {
        printf("----------------------\n");
        printf("address:  %p\n", iterator);
        printf("data:     %d\n", iterator->data);
        printf("next:     %p\n", iterator->next);
        printf("----------------------\n\n");

        if (iterator->next == NULL)
            break;
        iterator = iterator->next;
    }

    printf("Size of list: %d\n",   list->size);
    printf("Start:        %p\n",   list->start);
    printf("End:          %p\n\n", list->end);
}
// End of linked list methods.
