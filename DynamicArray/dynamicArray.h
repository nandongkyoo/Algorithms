#ifndef DYNAMIC_ARRAY_C
#define DYNAMIC_ARRAY_C
#define INITIAL_CAP 5
#include <stdio.h>

typedef struct dynamic_array_t {
    int *data;
    size_t size;
    size_t capacity;
} dynamic_array_t;

extern int initialSize;
int is_empty(dynamic_array_t* array);
void dynamic_array_create(dynamic_array_t* array, int initialSize);
void dynamic_array_destroy(dynamic_array_t* array);
void increase_size(dynamic_array_t* array);
void dynamic_array_push_back(dynamic_array_t* array, int value);
int dynamic_array_pop_back(dynamic_array_t* array);
void dynamic_array_insert(dynamic_array_t* array, int index, int value);
int dynamic_array_erase(dynamic_array_t* array, int index);
void dynamic_array_clear(dynamic_array_t* array);
int dynamic_array_size(dynamic_array_t* array);
int dynmaic_array_capacity(dynamic_array_t* array);
void showAllData(dynamic_array_t* array);


#endif