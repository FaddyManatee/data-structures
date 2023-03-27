/**
 * Doubly linked list node.
 */
typedef struct Node {
    int data;            // Some data that this node should store.
    struct Block *prev;  // Pointer to previous node.
    struct Block *next;  // Pointer to next node.
} Block;

/**
 * Wrapper for doubly linked list nodes.
 */
typedef struct DLinkedList {
    Node *start; // Pointer to head of list.
    Node *end;   // Pointer to end of list.
    int   size;  // List size (number of nodes).
} DLinkedList;

DLinkedList* DLinkedList();
Node* firstNode(DLinkedList *list);
Node* lastNode(DLinkedList *list)
void insertEnd(DLinkedList *list, Node *new);
void insertAfter(DLinkedList *list, Node *node, Node *new);
void printList(DLinkedList *list)
