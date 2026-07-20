#include "dynamicArray.h"

int main(void)
{
    dynamic_array_t arr;
    dynamic_array_t* array = &arr;

    dynamic_array_create(array, 2);

    dynamic_array_push_back(array, 10);
    dynamic_array_push_back(array, 20);
    dynamic_array_push_back(array, 30);
    dynamic_array_push_back(array, 50);
    showAllData(array);
    printf("\n------------------\n");

    dynamic_array_pop_back(array);
    showAllData(array);
    printf("\n------------------\n");
    
    dynamic_array_insert(array, 1, 25);
    showAllData(array);
    printf("\n------------------\n");
    dynamic_array_erase(array,2);
    showAllData(array);
    printf("\n------------------\n");

    dynamic_array_destroy(array);
    
}