#include <stdio.h>
#include "stack.h"

int main(int argc, char **argv) {
    Stack *stack = newStack(7);

    // Using a stack to reverse a list of integers 1-7.
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    push(stack, 6);
    push(stack, 7);
    push(stack, 8);
    push(stack, 9);

    if (isFull(stack))
        printf("Stack is full.\n");
    else
        printf("Stack is empty.\n");

    // Should be 7.
    printf("Peeking: %d\n", peek(stack));
    printStack(stack);

    pop(stack);

    // Should be 6.
    printf("Peeking: %d\n", peek(stack));
    printStack(stack);

    while (!isEmpty(stack)) {
        printf("%d\n", pop(stack));
    }
    
    printStack(stack);
    freeStack(stack);
    return 0;
}