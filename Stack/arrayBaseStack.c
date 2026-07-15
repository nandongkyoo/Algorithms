#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;    // 스택의 최상단 인덱스         
} ArrayStack;

// 스택 초기화
void stackInit(ArrayStack* s) {
    s->top = -1;
}

int isEmpty(ArrayStack* s) {
    return s->top == -1;
}

int isFull(ArrayStack* s) {
    return s->top == MAX_SIZE - 1;
}

void push(ArrayStack* s, int x) {
    if(isFull(s)) {
        printf("스택이 가득 찼습니다.\n");
        return;
    }
    s->top++;
    s->data[s->top] = x;
}

int pop(ArrayStack* s) {
    if(isEmpty(s)) {
        printf("스택이 비어있습니다.\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

int top(ArrayStack* s) {
    if(isEmpty(s)) {
        printf("스택이 비어있습니다.\n");
        exit(1);
    }
    return s->data[s->top];
}

int main() {
    ArrayStack s;
    stackInit(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);

    printf("%d\n", top(&s));

    pop(&s);
    printf("%d\n", top(&s));

    return 0;
}