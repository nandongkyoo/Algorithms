#include "dynamicArray.h"
#include <stdlib.h>

/*
 * CHECK: 조건이 거짓이면 어떤 테스트 함수의 몇 번째 줄에서
 *        어떤 조건이 실패했는지 출력한 뒤 프로그램을 중단한다.
 *        (표준 assert 와 달리 실패한 테스트 함수 이름까지 알려준다)
 */
#define CHECK(cond)                                                        \
    do {                                                                   \
        if (!(cond)) {                                                     \
            printf("[FAIL] %s - condition '%s' failed (line %d)\n",        \
                   __func__, #cond, __LINE__);                             \
            fflush(stdout);                                                \
            abort();                                                       \
        }                                                                  \
    } while (0)

/* 각 테스트는 통과 시 [PASS] 를 출력한다. CHECK 실패 시 프로그램이 중단된다. */
void test_create_and_empty(void)
{
    dynamic_array_t arr;
    dynamic_array_create(&arr, 4);

    CHECK(arr.data != NULL);
    CHECK(dynamic_array_size(&arr) == 0);
    CHECK(dynmaic_array_capacity(&arr) == 4);
    CHECK(is_empty(&arr) == 1);

    dynamic_array_destroy(&arr);
    printf("[PASS] test_create_and_empty\n");
}

void test_push_back(void)
{
    dynamic_array_t arr;
    dynamic_array_create(&arr, 2);

    dynamic_array_push_back(&arr, 10);
    dynamic_array_push_back(&arr, 20);
    CHECK(dynamic_array_size(&arr) == 2);
    CHECK(dynmaic_array_capacity(&arr) == 2);
    CHECK(is_empty(&arr) == 0);
    CHECK(arr.data[0] == 10);
    CHECK(arr.data[1] == 20);

    dynamic_array_destroy(&arr);
    printf("[PASS] test_push_back\n");
}

void test_grow_capacity(void)
{
    dynamic_array_t arr;
    dynamic_array_create(&arr, 2);

    /* 용량 2 초과 시 2배(2 -> 4)로 증가해야 한다 */
    dynamic_array_push_back(&arr, 1);
    dynamic_array_push_back(&arr, 2);
    dynamic_array_push_back(&arr, 3);
    CHECK(dynamic_array_size(&arr) == 3);
    CHECK(dynmaic_array_capacity(&arr) == 4);

    /* 4 -> 8 로 재증가 */
    dynamic_array_push_back(&arr, 4);
    dynamic_array_push_back(&arr, 5);
    CHECK(dynamic_array_size(&arr) == 5);
    CHECK(dynmaic_array_capacity(&arr) == 8);

    for (int i = 0; i < 5; i++) {
        CHECK(arr.data[i] == i + 1);
    }

    dynamic_array_destroy(&arr);
    printf("[PASS] test_grow_capacity\n");
}

void test_pop_back(void)
{
    dynamic_array_t arr;
    dynamic_array_create(&arr, 4);

    dynamic_array_push_back(&arr, 100);
    dynamic_array_push_back(&arr, 200);
    dynamic_array_push_back(&arr, 300);

    CHECK(dynamic_array_pop_back(&arr) == 300);
    CHECK(dynamic_array_size(&arr) == 2);
    CHECK(dynamic_array_pop_back(&arr) == 200);
    CHECK(dynamic_array_pop_back(&arr) == 100);
    CHECK(is_empty(&arr) == 1);

    dynamic_array_destroy(&arr);
    printf("[PASS] test_pop_back\n");
}

void test_insert(void)
{
    dynamic_array_t arr;
    dynamic_array_create(&arr, 4);

    dynamic_array_push_back(&arr, 10);
    dynamic_array_push_back(&arr, 20);
    dynamic_array_push_back(&arr, 30);

    /* 중간 삽입: [10, 20, 30] -> index 1 에 25 -> [10, 25, 20, 30] */
    dynamic_array_insert(&arr, 1, 25);
    CHECK(dynamic_array_size(&arr) == 4);
    CHECK(arr.data[0] == 10);
    CHECK(arr.data[1] == 25);
    CHECK(arr.data[2] == 20);
    CHECK(arr.data[3] == 30);

    /* 맨 앞 삽입 */
    dynamic_array_insert(&arr, 0, 5);
    CHECK(arr.data[0] == 5);
    CHECK(dynamic_array_size(&arr) == 5);

    /* 맨 뒤(size 위치) 삽입 = push_back 과 동일 */
    dynamic_array_insert(&arr, dynamic_array_size(&arr), 99);
    CHECK(arr.data[dynamic_array_size(&arr) - 1] == 99);

    dynamic_array_destroy(&arr);
    printf("[PASS] test_insert\n");
}

void test_insert_invalid(void)
{
    dynamic_array_t arr;
    dynamic_array_create(&arr, 4);
    dynamic_array_push_back(&arr, 1);

    /* 잘못된 인덱스는 무시되어 size 가 변하지 않아야 한다 (에러 메시지는 예상된 출력) */
    dynamic_array_insert(&arr, -1, 999);
    dynamic_array_insert(&arr, 5, 999);
    CHECK(dynamic_array_size(&arr) == 1);
    CHECK(arr.data[0] == 1);

    dynamic_array_destroy(&arr);
    printf("[PASS] test_insert_invalid\n");
}

void test_erase(void)
{
    dynamic_array_t arr;
    dynamic_array_create(&arr, 8);

    for (int i = 0; i < 5; i++) {
        dynamic_array_push_back(&arr, (i + 1) * 10); /* [10,20,30,40,50] */
    }

    /* 중간 삭제: index 1(=20) 제거 -> [10,30,40,50] */
    CHECK(dynamic_array_erase(&arr, 1) == 20);
    CHECK(dynamic_array_size(&arr) == 4);
    CHECK(arr.data[0] == 10);
    CHECK(arr.data[1] == 30);
    CHECK(arr.data[2] == 40);
    CHECK(arr.data[3] == 50);

    /* 마지막 삭제(pop_back 경로): index 3(=50) 제거 */
    CHECK(dynamic_array_erase(&arr, 3) == 50);
    CHECK(dynamic_array_size(&arr) == 3);

    /* 맨 앞 삭제 */
    CHECK(dynamic_array_erase(&arr, 0) == 10);
    CHECK(arr.data[0] == 30);
    CHECK(dynamic_array_size(&arr) == 2);

    dynamic_array_destroy(&arr);
    printf("[PASS] test_erase\n");
}

void test_clear(void)
{
    dynamic_array_t arr;
    dynamic_array_create(&arr, 4);

    dynamic_array_push_back(&arr, 1);
    dynamic_array_push_back(&arr, 2);
    size_t cap_before = dynmaic_array_capacity(&arr);

    dynamic_array_clear(&arr);
    CHECK(dynamic_array_size(&arr) == 0);
    CHECK(is_empty(&arr) == 1);
    /* clear 는 size 만 0 으로, 용량은 유지 */
    CHECK(dynmaic_array_capacity(&arr) == (int)cap_before);

    /* clear 후 재사용 가능해야 한다 */
    dynamic_array_push_back(&arr, 42);
    CHECK(dynamic_array_size(&arr) == 1);
    CHECK(arr.data[0] == 42);

    dynamic_array_destroy(&arr);
    printf("[PASS] test_clear\n");
}

void test_destroy(void)
{
    dynamic_array_t arr;
    dynamic_array_create(&arr, 4);
    dynamic_array_push_back(&arr, 7);

    dynamic_array_destroy(&arr);
    CHECK(arr.data == NULL);
    CHECK(arr.size == 0);
    CHECK(arr.capacity == 0);

    printf("[PASS] test_destroy\n");
}

int main(void)
{
    test_create_and_empty();
    test_push_back();
    test_grow_capacity();
    test_pop_back();
    test_insert();
    test_insert_invalid();
    test_erase();
    test_clear();
    test_destroy();

    printf("\nAll tests passed!\n");

    return (0);
}
