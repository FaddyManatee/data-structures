/**
 * Doubly linked list node.
 */
typedef struct Node {
    int data;           // Some data that this node should store.
    struct Node *prev;  // Pointer to previous node.
    struct Node *next;  // Pointer to next node.
} Node;

/**
 * Wrapper for doubly linked list nodes.
 */
typedef struct DLinkedList {
    Node *start; // Pointer to head of list.
    Node *end;   // Pointer to end of list.
    int   size;  // List size (number of nodes).
} DLinkedList;

DLinkedList* newDLinkedList();
Node* firstNode(DLinkedList *list);
Node* lastNode(DLinkedList *list);
Node* newNode(int data);
void freeDLinkedList(DLinkedList *list);
void insertEnd(DLinkedList *list, Node *new);
void insertAfter(DLinkedList *list, Node *node, Node *new);
void printList(DLinkedList *list);
