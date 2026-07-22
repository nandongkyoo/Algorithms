#include "linkedList.h"

int main(void)
{
    linked_list_t l;
    linked_list_t *list = &l;

    linked_list_create(list);

    linked_list_push_back(list, 10);
    linked_list_push_back(list, 20);
    linked_list_push_back(list, 30);
    linked_list_push_front(list, 5);
    showAllData(list);
    printf("\n------------------\n");

    linked_list_pop_back(list);
    showAllData(list);
    printf("\n------------------\n");

    linked_list_insert(list, 1, 7);
    showAllData(list);
    printf("\n------------------\n");

    linked_list_erase(list, 2);
    showAllData(list);
    printf("\n------------------\n");

    node_t *found = linked_list_find(list, 20);
    printf("find(20): %s\n", found ? "found" : "not found");

    linked_list_destroy(list);
}
