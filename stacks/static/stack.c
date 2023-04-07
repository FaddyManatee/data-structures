#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


/**
 * Creates a new stack. Remember to free its resources when no longer needed.
 */
Stack* newStack(int maxSize) {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->data = (int *) calloc(maxSize, sizeof(int));
    stack->top = stack->data;
    stack->max = maxSize;
    stack->size = 0;

    return stack;
}


/**
 * Frees all memory dynamically allocated to the stack. 
 */
void freeStack(Stack *stack) {
    free(stack->data);
    free(stack);
}


/**
 * Push (add) 'data' onto the top of the stack.
 * Returns if the operation would cause a stack overflow.
 */
void push(Stack *stack, int data) {
    if (isFull(stack))
        return;

    *(stack->top++) = data;
    stack->size++;
}


/**
 * Pop (remove) an element from the top of the stack.
 * Returns 0 if the operation would cause a stack underflow.
 */
int pop(Stack *stack) {
    if (isEmpty(stack))
        return 0;

    int element = *(--stack->top);
    stack->size--;

    return element;
}


/**
 * Peek (inspect) the top element of the stack. 
 */
int peek(Stack *stack) {
    return *(stack->top - 1);
}


/**
 * Returns true (1) if the stack is full, false (0) otherwise. 
 */
int isFull(Stack *stack) {
    if (stack->top - 1 == stack->data + stack->max - 1)
        return 1;
    return 0;
}


/**
 * Returns true (1) if the stack is empty, false (0) otherwise. 
 */
int isEmpty(Stack *stack) {
    if (stack->top == stack->data)
        return 1;
    return 0;
}


/**
 * Prints the stack. 
 */
void printStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("----------------------\n");
        printf("The stack is empty\n");
        printf("----------------------\n\n");
        return;
    }

    int x;
    printf("------Stack Top------\n");
    for (x = stack->size - 1; x >= 0; x--) {
        printf("%d\n", stack->data[x]);
    }
    printf("-----Stack Bottom-----\n\n");
}
