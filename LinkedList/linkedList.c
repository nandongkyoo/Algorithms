#include "linkedList.h"
#include <stdlib.h>

int is_empty(linked_list_t *list)
{
    return list->size == 0;
}

void linked_list_create(linked_list_t *list)
{
    list->head = malloc(sizeof(node_t));
    list->head->next = NULL;
    list->tail = list->head;
    list->size = 0;
}

void linked_list_destroy(linked_list_t *list)
{
    node_t *cur = list->head;
    while(cur != NULL) {
        node_t *next = cur->next;
        free(cur);
        cur = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void linked_list_push_front(linked_list_t *list, int value)
{
    node_t *newNode = (node_t*)malloc(sizeof(node_t));
    if(newNode == NULL) {
        printf("메모리 할당 실패\n");
        return;
    }
    newNode->data = value;
    newNode->next = list->head->next;
    list->head->next = newNode;
    list->size++;
}

void linked_list_push_back(linked_list_t *list, int value)
{
    node_t *newNode = (node_t*)malloc(sizeof(node_t));
    if(newNode == NULL) {
        printf("메모리 할당 실패\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    list->tail->next = newNode;
    list->tail = newNode;
    list->size++;
}

int linked_list_pop_front(linked_list_t *list)
{
    if(list->head->next == NULL) {
        printf("리스트가 비어있습니다.\n");
        return -1;
    }

    node_t *target = list->head->next;
    int value = target->data;
    list->head->next = target->next;

    if(list->head->next == NULL) {
        list->tail = list->head;
    }    
    free(target);
    list->size--;
    return value;
}

int linked_list_pop_back(linked_list_t *list)
{
    if(list->head->next == NULL) {
        printf("리스트가 비어있습니다\n");
        return -1;
    }

    node_t *prev = list->head;

    while(prev->next != list->tail) {
        prev = prev->next;
    }
    int value = list->tail->data;
    free(list->tail);

    prev->next = NULL;
    list->tail = prev;

    list->size--;
    return value;
}

void linked_list_insert(linked_list_t *list, int index, int value)
{
    if(index < 0 || index > (int)list->size) {
        printf("삽입가능한 인덱스가 아닙니다.\n");
        return;
    }
    if(index == 0) {
        linked_list_push_front(list, value);
        return;
    }
    if(index == (int)list->size) {
        linked_list_push_back(list, value);
        return;
    }

    node_t *newNode = (node_t*)malloc(sizeof(node_t));
    node_t *prev = list->head;
    node_t *target = list->head->next;

    if(newNode == NULL) {
        printf("메모리 할당 실패\n");
        return;
    }
    newNode->data = value;

    for(int i = 0; i < index; i++) {
        prev = prev->next;
        target = target->next;
    }
    prev->next = newNode;
    newNode->next = target;
    list->size++;
}

int linked_list_erase(linked_list_t *list, int index)
{
    if(index < 0 || index >= (int)list->size) {
        printf("삭제 가능한 인덱스가 아닙니다.\n");
        return -1;
    }
    if(index == 0) {
        return linked_list_pop_front(list);
    }
    if(index == (int)list->size -1) {
        return linked_list_pop_back(list);
    }

    node_t *prev = list->head;
    node_t *target = list->head->next;

    for(int i = 0; i < index; i++) {
        prev = prev->next;
        target = target->next;
    }
    int value = target->data;
    prev->next = target->next;

    free(target);
    list->size--;

    return value;
}

node_t *linked_list_find(linked_list_t *list, int value)
{
    node_t *target = list->head->next;
    while(target != NULL) {
        if(target->data == value) {
            return target;
        }
        target = target->next;
    }
    return NULL;
}

void linked_list_clear(linked_list_t *list)
{
    node_t *target = list->head->next;
    node_t *nextNode;
    while(target != NULL) {
        nextNode = target->next;
        free(target);
        target = nextNode;
    }
    list->head->next = NULL;
    list->tail = list->head;
    list->size = 0;
}

int linked_list_size(linked_list_t *list)
{
    return (int)list->size;
}

void showAllData(linked_list_t *list)
{
    node_t *target = list->head->next;
    while(target != NULL) {
        printf("%d ", target->data);
        target = target->next;
    }
}
