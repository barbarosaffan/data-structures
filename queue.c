// implement a queue in c language

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Queue structure
typedef struct queue {
    int front;
    int rear;
    int data[MAX];
} queue;

void init(queue *q) {
    q->front = 0;
    q->rear = -1;
}

int empty(queue *q) {
    return q->front > q->rear;
}

int full(queue *q) {
    return q->rear == MAX - 1;
}

void enqueue(queue *q, int x) {
    if (full(q)) {
        printf("queue overflow");
        exit(1);
    }
    q->data[++q->rear] = x;
}

int dequeue(queue *q) {
    if (empty(q)) {
        printf("queue underflow");
        exit(1);
    }
    return q->data[q->front++];
}

int main() {
    queue q;
    init(&q);
    // Enqueue stuff onto the queue
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    // Dequeue stuff off the queue & print it
    printf("%d ", dequeue(&q));
}
