#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int capacity;
    int* stack;
    int top;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->stack = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->top++;
    stack->stack[stack->top] = value;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1; // Assuming -1 represents an error or invalid value
    }
    int value = stack->stack[stack->top];
    stack->top--;
    return value;
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1; // Assuming -1 represents an error or invalid value
    }
    return stack->stack[stack->top];
}

int main() {
    struct Stack* stack = createStack(MAX_SIZE);

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("Top of stack: %d\n", peek(stack));

    printf("Popped item: %d\n", pop(stack));
    printf("Top of stack after pop: %d\n", peek(stack));

    free(stack->stack);
    free(stack);

    return 0;
}
