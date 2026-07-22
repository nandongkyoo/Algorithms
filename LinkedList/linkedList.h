#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdio.h>

typedef struct node_t {
    int data;
    struct node_t *next;
} node_t;

typedef struct linked_list_t {
    node_t *head;
    node_t *tail;
    size_t size;
} linked_list_t;

int is_empty(linked_list_t *list);
void linked_list_create(linked_list_t *list);
void linked_list_destroy(linked_list_t *list);
void linked_list_push_front(linked_list_t *list, int value);
void linked_list_push_back(linked_list_t *list, int value);
int linked_list_pop_front(linked_list_t *list);
int linked_list_pop_back(linked_list_t *list);
void linked_list_insert(linked_list_t *list, int index, int value);
int linked_list_erase(linked_list_t *list, int index);
node_t *linked_list_find(linked_list_t *list, int value);
void linked_list_clear(linked_list_t *list);
int linked_list_size(linked_list_t *list);
void showAllData(linked_list_t *list);

#endif
