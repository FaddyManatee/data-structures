#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


/**
 * Creates a new queue. Remember to free its resources when no longer needed.
 */
Queue* newQueue(int maxSize) {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->data = (int *) calloc(maxSize, sizeof(int));
    queue->front = queue->data;
    queue->back = queue->data;
    queue->max = maxSize;
    queue->size = 0;

    return queue;
}


/**
 * Frees all memory dynamically allocated to the queue. 
 */
void freeQueue(Queue *queue) {
    free(queue->data);
    free(queue);
}


/**
 * Enque (add) 'data' onto the back of the queue.
 * Returns if the operation would cause a queue overflow.
 */
void enqueue(Queue *queue, int data) {
    if (isFull(queue))
        return;

    *(queue->back++) = data;
    queue->size++;
}


/**
 * Deque (remove) an element from the front of the queue.
 * Returns 0 if the operation would cause a queue underflow.
 */
int dequeue(Queue *queue) {
    if (isEmpty(queue))
        return 0;

    int element = *(queue->front++);
    queue->size--;

    return element;
}


/**
 * Peek (inspect) the front element of the queue. 
 */
int peek(Queue *queue) {
    return *(queue->front);
}


/**
 * Returns true (1) if the queue is full, false (0) otherwise. 
 */
int isFull(Queue *queue) {
    if (queue->back - 1 == queue->data + queue->max - 1)
        return 1;
    return 0;
}


/**
 * Returns true (1) if the queue is empty, false (0) otherwise. 
 */
int isEmpty(Queue *queue) {
    if (queue->front == queue->back)
        return 1;
    return 0;
}


/**
 * Prints the queue. 
 */
void printQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("----------------------\n");
        printf("The queue is empty\n");
        printf("----------------------\n\n");
        return;
    }

    int x;
    if (queue->front > &queue->data[x])
        printf("start: -");
    else
        printf("start: %d", queue->data[0]);

    for (x = 1; x < queue->max; x++) {
        if (queue->front > &queue->data[x])
            printf(", -");
        else
            printf(", %d", queue->data[x]);
    }
    printf(" :end\n");
}
