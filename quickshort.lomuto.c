#include <stdio.h>
#include <stdlib.h>
#define SIZE 26
void p_arr_number(int low, int high, int a[]);
int partition(int a[], int low, int high);
void swap(int* a, int* b);
void quick_short(int a[], int low, int high);

int main(int argc, char* argv[])
{
    //    int arr[SIZE] = { 8, 7, 10, 9, 1, 5 };
    int arr[SIZE] = {
        42, 7, 89, 13, 56, 91, 3, 78, 24, 65,
        17, 99, 34, 1, 58, 76, 12, 83, 27, 50,
        94, 6, 71, 39, 18, 85
    };

    printf("-init (pivot: %d)\t=  ", arr[SIZE - 1]);
    p_arr_number(0, SIZE - 1, arr);
    printf("\n");
    quick_short(arr, 0, SIZE - 1);

    printf("\n-Result \t\t=  ");
    p_arr_number(0, SIZE - 1, arr);
    return EXIT_SUCCESS;
}

int partition(int a[], int low, int high)
{
    // pick pivot   LOBUTO  algo for learn
    static int index = 0;
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (a[j] < pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);

    printf("  *ORIGINAL \t\t=> ");
    p_arr_number(0, SIZE - 1, a);
    printf("  %2d -STEP (pivot:%2d )\t=> ", index, a[i + 1]);
    p_arr_number(low, high, a);
    printf("\n");
    index++;
    return i + 1;
}

void quick_short(int a[], int low, int high)
{
    if (low < high) {
        int pivot = partition(a, low, high);
        // printf("-step\t(pivot: %d)\t=> ", a[pivot]);
        // printf("\n");
        quick_short(a, low, pivot - 1);
        quick_short(a, pivot + 1, high);
    }
}
void swap(int* a, int* b)
{
    int temp;
    temp = *a;
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
// void p_arr_number(int low, int high, int a[])
// {
//     for (int i = low; i <= high; i++) {
//         if (i == low) {
//             printf("%2d", a[i]);
//         } else {
//             printf(" , %2d", a[i]);
//         }
//     }
//     printf("\n");
// }
