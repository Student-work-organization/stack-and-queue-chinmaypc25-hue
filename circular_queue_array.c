#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int front, rear;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = q->rear = -1;
    q->arr = (int*)malloc(capacity * sizeof(int));
    return q;
}

int is_full(Queue *q) {
    return (q->front == (q->rear + 1) % q->capacity);
}

int is_empty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int data) {
    if (is_full(q)) {
        printf("Queue Overflow\n");
        return;
    }

    if (q->front == -1) q->front = 0;

    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = data;
}

int dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }

    int data = q->arr[q->front];

    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->capacity;
    }

    return data;
}

int frontElement(Queue *q) {
    if (is_empty(q)) return -1;
    return q->arr[q->front];
}

int main() {
    Queue *q = createQueue(3);

    enqueue(q, 10);
    enqueue(q, 20);

    printf("Front: %d\n", frontElement(q));
    printf("Dequeued: %d\n", dequeue(q));

    return 0;
}
