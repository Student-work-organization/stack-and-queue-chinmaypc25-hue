#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node *front, *rear;
} Queue;

void enqueue(Queue *q, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

int front(Queue *q) {
    if (q->front == NULL) return -1;
    return q->front->data;
}

int is_empty(Queue *q) {
    return q->front == NULL;
}

int main() {
    Queue q = {NULL, NULL};

    enqueue(&q, 10);
    enqueue(&q, 20);

    printf("Front: %d\n", front(&q));
    printf("Empty: %d\n", is_empty(&q));

    return 0;
}
