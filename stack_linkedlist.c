#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void push(Stack *s, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack *s) {
    if (s->top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    Node *temp = s->top;
    int val = temp->data;
    s->top = temp->next;
    free(temp);
    return val;
}

int peek(Stack *s) {
    if (s->top == NULL) return -1;
    return s->top->data;
}

int empty(Stack *s) {
    return s->top == NULL;
}

int main() {
    Stack s = {NULL};

    push(&s, 10);
    push(&s, 20);

    printf("Top: %d\n", peek(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Empty: %d\n", empty(&s));

    return 0;
}
