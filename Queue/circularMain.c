#include <stdio.h>
#include <stdlib.h>
#include "circularQueue.h"

int main(void) {
    CircularQueue cq;
    queueInit(&cq);

    enqueue(&cq, 10);
    enqueue(&cq, 20);
    enqueue(&cq, 30);
    enqueue(&cq, 40);

    printf("dequeue: %d\n", dequeue(&cq));
    printf("dequeue: %d\n", dequeue(&cq));

    return 0;
}
