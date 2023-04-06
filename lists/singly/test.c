#include "linkedlist.h"

int main(int argc, char **argv) {
    LinkedList *list = newLinkedList();
    
    Node *node1 = newNode(5);
    insertEnd(list, node1);

    Node *node2 = newNode(7);
    insertEnd(list, node2);

    Node *node3 = newNode(6);
    insertAfter(list, node1, node3);

    //deleteNode(list, node1);
    deleteNode(list, node3);
    //deleteNode(list, node2);
    
    printList(list);
    freeLinkedList(list);
    return 0;
}
