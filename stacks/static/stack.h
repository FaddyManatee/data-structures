/**
 * Wrapper for stack data. 
 */
typedef struct Stack {
    int *data;
    int *top;  // Pointer to the next free element of the stack.
    int size;
    int max;   // Maximum stack size.
} Stack;

Stack* newStack(int maxSize);
int isEmpty(Stack *stack);
int isFull(Stack *stack);
int peek(Stack *stack);
int pop(Stack *stack);
void push(Stack *stack, int data);
void freeStack(Stack *stack);
void printStack(Stack *stack);
