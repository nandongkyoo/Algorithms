#include "dynamicArray.h"
#include <stdlib.h>

int is_empty(dynamic_array_t *array)
{
    return array->size == 0;
}

void dynamic_array_create(dynamic_array_t *array, int initialSize)
{
    array->data = malloc(sizeof(int)*initialSize);
    array->size = 0;
    array->capacity = initialSize;
}

void dynamic_array_destroy(dynamic_array_t *array)
{
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
}

void increase_size(dynamic_array_t* array)
{
    size_t nCapacity = array->capacity * 2;
    int* nData = realloc(array->data, sizeof(int) * nCapacity);
    if(nData == NULL) {
        printf("메모리 재할당 실패\n");
        return;
    }
    array->data = nData;
    array->capacity = nCapacity;
       
    
}
void dynamic_array_push_back(dynamic_array_t *array, int value)
{
    if(array->size == array->capacity) {
       increase_size(array);
    }
    array->size++;
    array->data[array->size-1] = value;
}

int dynamic_array_pop_back(dynamic_array_t *array)
{
    int outValue;
    if(is_empty(array)) {
        printf("배열이 비어있습니다.\n");
        exit(1);
    }
    outValue = array->data[array->size-1];
    array->size--;
    return outValue;
}

void dynamic_array_insert(dynamic_array_t *array, int index, int value)
{
    if(index < 0 || index > (int)array->size) {
        printf("잘못된 입력입니다\n");
        return;
    }
    if(index == (int)array->size) {
        dynamic_array_push_back(array, value);
        return;
    }
    if(array->size == array->capacity) {
        increase_size(array);
    }
    for(int i = (int)array->size; i > index; i--) {
        array->data[i] = array->data[i-1];
    }
    array->data[index] = value;
    array->size++;

}

int dynamic_array_erase(dynamic_array_t *array, int index)
{
    if(index < 0 || index >= (int)array->size) {
        printf("잘못된 입력입니다\n");
        exit(1);
    }
    if(index == (int)array->size - 1) {
        return dynamic_array_pop_back(array);
    }
    int eNum = array->data[index];
    for(int i = index; i < (int)array->size-1; i++) {
        array->data[i] = array->data[i+1];
    }
    array->size--;

    return eNum;
}

void dynamic_array_clear(dynamic_array_t *array)
{
    if(array->data == NULL) {
        return;
    }
    array->size = 0;
}

int dynamic_array_size(dynamic_array_t *array)
{
    return array->size;
}

int dynmaic_array_capacity(dynamic_array_t *array)
{
    return array->capacity;
}

void showAllData(dynamic_array_t *array)
{
    if(array->data == NULL) {
        return;
    }
    for(int i = 0; i < (int)array->size; i++) {
        printf("%d ", array->data[i]);
    }
}
