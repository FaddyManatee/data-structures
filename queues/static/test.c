#include <stdio.h>
#include "queue.h"

int main(int argc, char **argv) {
    Queue *queue = newQueue(7);

    // Using a stack to reverse a list of integers 1-7.
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6);
    enqueue(queue, 7);
    enqueue(queue, 8);
    enqueue(queue, 9);

    if (isFull(queue))
        printf("Queue is full.\n");
    else
        printf("Queue is empty.\n");

    // Should be 1.
    printf("Peeking: %d\n", peek(queue));
    printQueue(queue);

    dequeue(queue);

    // Should be 2.
    printf("Peeking: %d\n", peek(queue));
    printQueue(queue);

    while (!isEmpty(queue)) {
        printf("%d\n", dequeue(queue));
    }
    
    printQueue(queue);
    freeQueue(queue);
    return 0;
}
