// implement a stack in C language

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct stack {
    int top;
    int data[MAX];
} stack;

void init(stack *s) {
    s->top = -1;
}

int empty(stack *s) {
    return s->top == -1;
}

int full(stack *s) {
    return s->top == MAX - 1;
}

void push(stack *s, int x) {
    if (full(s)) {
        printf("stack overflow");
        exit(1);
}
    s->data[++s->top] = x;
}

int pop(stack *s) {
    if (empty(s)) {
        printf("stack underflow");
        exit(1);
    }
    return s->data[s->top--];
}

int main() {
    stack s;
    init(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("%d ", pop(&s));
}
