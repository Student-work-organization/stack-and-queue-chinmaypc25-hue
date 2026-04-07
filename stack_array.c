#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->capacity = capacity;
    s->top = -1;
    s->arr = (int*)malloc(capacity * sizeof(int));
    return s;
}

void push(Stack *s, int data) {
    if (s->top == s->capacity - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = data;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

int peek(Stack *s) {
    if (s->top == -1) return -1;
    return s->arr[s->top];
}

int empty(Stack *s) {
    return s->top == -1;
}

int main() {
    Stack *s = createStack(3);

    push(s, 10);
    push(s, 20);
    push(s, 30);

    printf("Top: %d\n", peek(s));
    printf("Popped: %d\n", pop(s));
    printf("Empty: %d\n", empty(s));

    return 0;
}
