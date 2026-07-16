#include <stdio.h>
#include <stdlib.h>
#include "circularQueue.h"

void queueInit(CircularQueue* cq) {
    cq->front = 0;
    cq->back = 0;
    cq->count = 0;
}

int isEmpty(CircularQueue* cq) {
    return cq->count == 0;
}

int isFull(CircularQueue* cq) {
    return cq->count == MAX_SIZE;
}

void enqueue(CircularQueue* cq, int value) {
    if(isFull(cq)) {
        printf("큐가 가득 찼습니다.\n");
        exit(1);
    }
    cq->data[cq->back] = value;
    cq->back = (cq->back + 1) % MAX_SIZE;   // 원형큐의 핵심
    cq->count++;
}

int dequeue(CircularQueue* cq) {
    if(isEmpty(cq)) {
        printf("큐가 비어있습니다.\n");
        exit(1);
    }
    int value = cq->data[cq->front];
    cq->front = (cq->front + 1) % MAX_SIZE;   // 원형큐의 핵심
    cq->count--;
    return value;
}