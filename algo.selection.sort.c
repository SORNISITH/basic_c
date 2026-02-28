#include <stdio.h>
#include <stdlib.h>
#define SIZE 6
void p_arr_number(int low, int high, int a[]);

void selection_sort(int len, int arr[]);
void swap(int* a, int* b);
int main(int argc, char* argv[])
{
    int arr[SIZE] = { 8, 7, 10, 9, 1, 5 };
    // int arr[SIZE] = {
    //     42, 7, 89, 13, 56, 91, 3, 78, 24, 65,
    //     17, 99, 34, 1, 58, 76, 12, 83, 27, 50,
    //     94, 6, 71, 39, 18, 85
    // };

    printf("-init \t\t\t=  ");
    p_arr_number(0, SIZE - 1, arr);
    printf("\n");
    selection_sort(SIZE, arr);
    printf("\n-Result \t\t=  ");
    p_arr_number(0, SIZE - 1, arr);
    return EXIT_SUCCESS;
}

void selection_sort(int len, int arr[])
{
    if (len <= 0) {
        return;
    }
    int min = len - 1;
    for (int i = 0; i <= min; i++) {
        if (arr[i] > arr[min]) {
            swap(&arr[i], &arr[min]);
        }
    }
    selection_sort(len - 1, arr);
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void p_arr_number(int low, int high, int a[])
{
    for (int i = low; i <= high; i++) {
        if (i == low) {
            printf("%2d", a[i]);
        } else {
            printf(" , %2d", a[i]);
        }
    }
    printf("\n");
}
