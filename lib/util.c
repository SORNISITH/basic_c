#include "utils.h"
#include <stddef.h>
#include <stdio.h>
void p_vector_int(int* arr, size_t size)
{
    int* p = arr;
    for (int i = 0; i < size; i++, p++) {
        if (i == 0) {
            printf("[ ");
        }
        if (i > 0 && i < size - 2) {
            printf("%2d , ", *p);
        }
        if (i == size - 1) {
            printf("%2d ]", *p);
        }
    }
}

void p_matrix_int(int (*arr)[20], size_t row, size_t col)
{
    printf("\n");
    for (int r = 0; r < row; r++) {
        p_vector_int(arr[r], col);
        printf("\n");
    }
}
