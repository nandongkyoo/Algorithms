#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#define MAX_SIZE 7

typedef struct {
    int data[MAX_SIZE];
    int front;
    int back;
    int count;
} CircularQueue;

void queueInit(CircularQueue* cq);
int isEmpty(CircularQueue* cq);
int isFull(CircularQueue* cq);
void enqueue(CircularQueue* cq, int value);
int dequeue(CircularQueue* cq);

#endif
