#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int capacity;
    int* queue;
    int front;
    int rear;
    int size;
};

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->queue = (int*)malloc(capacity * sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

int isEmpty(struct Queue* queue) {
    return queue->size == 0;
}

int isFull(struct Queue* queue) {
    return queue->size == queue->capacity;
}

void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->queue[queue->rear] = value;
    queue->size++;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1; // Assuming -1 represents an error or invalid value
    }
    int value = queue->queue[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return value;
}

int peek(struct Queue* queue) {
    if (isEmpty(queue)) {
        return -1; // Assuming -1 represents an error or invalid value
    }
    return queue->queue[queue->front];
}

int main() {
    struct Queue* queue = createQueue(MAX_SIZE);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printf("Front of queue: %d\n", peek(queue));

    printf("Dequeued item: %d\n", dequeue(queue));

    printf("Front of queue after dequeue: %d\n", peek(queue));

    free(queue->queue);
    free(queue);

    return 0;
}
