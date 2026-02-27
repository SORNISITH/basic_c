#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define INIT_CAPACITY 1
typedef struct {
    size_t count;
    size_t capacity;
} Header;

#define arr_len(arr) (((Header*)(arr) - 1)->count)
#define arr_push(arr, x)                                                                \
    do {                                                                                \
        if (arr == NULL) {                                                              \
            Header* header = malloc(sizeof(*arr) * INIT_CAPACITY + sizeof(Header));     \
            header->count = 0;                                                          \
            header->capacity = INIT_CAPACITY;                                           \
            arr = (void*)(header + 1);                                                  \
        }                                                                               \
        Header* header = (Header*)(arr) - 1;                                            \
        if (header->count >= header->capacity) {                                        \
            header->capacity *= 2;                                                      \
            header = realloc(header, sizeof(*arr) * header->capacity + sizeof(Header)); \
            arr = (void*)(header + 1);                                                  \
        }                                                                               \
        (arr)[header->count++] = (x);                                                   \
    } while (0)

// void* arr_push(int* arr, int x)
// {
//     if (arr == NULL) {
//         Header* header = malloc(sizeof(Header) + INIT_CAPACITY * sizeof(**arr));
//         header->count = 0;
//         header->capacity = INIT_CAPACITY;
//         arr = (int*)(header + 1);
//         return arr;
//     }
//     Header* header = (Header*)(arr - 1);
//     if (header->count >= header->capacity) {
//         header->capacity *= 2;
//         header = realloc(header, sizeof(Header) + header->capacity * sizeof(*arr));
//         arr = (void*)(header + 1);
//     }
//     arr[header->count++] = x;
//     return arr;
// }

void arr_free(int* arr)
{
    Header* a = (Header*)arr - 1;
    if (a == NULL) {
        printf("Error No array found!");
        return;
    }
    printf("-> attept : Clear array @ %p ... done!", a);
    free(a);
}

void arr_print(int* arr)
{
    Header* index = (Header*)(arr - 1);
    for (int i = 0; i < arr_len(arr); i++) {
        printf("%d \n", arr[i]);
    }
}

int main()
{
    int* numbers = NULL;
    arr_push(numbers, 100);
    arr_push(numbers, 200);
    arr_push(numbers, 200);
    arr_push(numbers, 200);

    arr_print(numbers);
    return EXIT_SUCCESS;
}
