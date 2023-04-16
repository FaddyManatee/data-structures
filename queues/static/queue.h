/**
 * Wrapper for queue data. This type of queue can "drift".
 */
typedef struct Queue {
    int *data;
    int *front;  // Pointer to the element at the front of the queue.
    int *back;  // Pointer to the next free element at the back of the queue.
    int size;
    int max;  // Maximum queue size.
} Queue;

Queue* newQueue(int maxSize);
int isEmpty(Queue *queue);
int isFull(Queue *queue);
int peek(Queue *queue);
int dequeue(Queue *queue);
void enqueue(Queue *queue, int data);
void freeQueue(Queue *queue);
void printQueue(Queue *queue);
