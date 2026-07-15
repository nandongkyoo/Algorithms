#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} linkedStack;

void stackInit(linkedStack* ls) {
    ls->top = NULL;
}

int isEmpty(linkedStack* ls) {
    return ls->top == NULL;
}

void push(linkedStack* ls, int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode) {
        printf("메모리 할당 실패\n");
        return;
    }
    newNode->data = x;
    newNode->next = ls->top;
    ls->top = newNode;
}

int pop(linkedStack* ls) {
    Node* popNode;
    int value;
    if(isEmpty(ls)) {
        printf("스택이 비어있습니다.\n");
        exit(1);
    }
    popNode = ls->top;
    value = popNode->data;
    ls->top = ls->top->next;
    free(popNode);
    return value;
}

int top(linkedStack* ls) {
    if(isEmpty(ls)) {
        printf("스택이 비어있습니다.\n");
        exit(1);
    }
    return ls->top->data;
}

int main() {
    linkedStack ls;
    stackInit(&ls);

    push(&ls, 10);
    push(&ls, 20);
    push(&ls, 30);
    push(&ls, 40);

    printf("%d\n", top(&ls));
    pop(&ls);

    printf("%d\n", top(&ls));

    return 0;

}