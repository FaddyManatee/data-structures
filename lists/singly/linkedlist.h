/**
 * Singly linked list node.
 */
typedef struct Node {
    int data;           // Some data that this node should store.
    struct Node *next;  // Pointer to next node.
} Node;

/**
 * Wrapper for singly linked list nodes.
 */
typedef struct LinkedList {
    Node *start; // Pointer to head of list.
    Node *end;   // Pointer to end of list.
    int   size;  // List size (number of nodes).
} LinkedList;

LinkedList* newLinkedList();
Node* firstNode(LinkedList *list);
Node* lastNode(LinkedList *list);
Node* newNode(int data);
void freeLinkedList(LinkedList *list);
void insertEnd(LinkedList *list, Node *new);
void insertAfter(LinkedList *list, Node *node, Node *new);
void printList(LinkedList *list);
