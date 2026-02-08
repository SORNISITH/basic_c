#include <stdlib.h>
#include <string.h>

int partition(int a[], int low, int high);
void swap(int* a, int* b);
void quick_sort(int a[], int low, int high);

int* q_sort(int* arr, int size)
{
    if (arr == NULL || size <= 0) {
        return NULL;
    }
    int* q = malloc(size * sizeof(arr[0]));
    memcpy(q, arr, size * sizeof(arr[0]));

    quick_sort(q, 0, size - 1);

    return q;
}

// int main(int argc, char *argv[]) {
//   //    int arr[SIZE] = { 8, 7, 10, 9, 1, 5 };
//   int arr[SIZE] = {42, 7,  89, 13, 56, 91, 3,  78, 24, 65, 17, 99, 34,
//                    1,  58, 76, 12, 83, 27, 50, 94, 6,  71, 39, 18, 85};
//
//   printf("-init (pivot: %d)\t=  ", arr[SIZE - 1]);
//   p_arr_number(0, SIZE - 1, arr);
//   printf("\n");
//   quick_short(arr, 0, SIZE - 1);
//
//   printf("\n-Result \t\t=  ");
//   p_arr_number(0, SIZE - 1, arr);
//   return EXIT_SUCCESS;
// }

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
    index++;

    return i + 1;
}

void quick_sort(int a[], int low, int high)
{
    if (low < high) {
        int pivot = partition(a, low, high);
        // printf("-step\t(pivot: %d)\t=> ", a[pivot]);
        // printf("\n");
        quick_sort(a, low, pivot - 1);
        quick_sort(a, pivot + 1, high);
    }
}

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// void p_arr_number(int low, int high, int a[]) {
//   for (int i = low; i <= high; i++) {
//     if (i == low) {
//       printf("%2d", a[i]);
//     } else {
//       printf(" , %2d", a[i]);
//     }
//   }
//   printf("\n");
// }
