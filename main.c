#include <stdio.h>
#include <stdlib.h>
#define SIZE 7
void quick_short(int a[], int size);
int main(int argc, char* argv[])
{
    int arr[SIZE] = { 12, 3, 6, 18, 7, 15, 10 };

    quick_short(arr, 6);
    exit(EXIT_SUCCESS);
}

void quick_short(int a[], int size)

{
    static int pivot;
    int low, hight;
    int middle;
    if (size % 2 == 0) {
        middle = ((size) / 2);
    } else {
        middle = ((size - 1) / 2);
    }

    low = a[0];
    hight = a[size - 1];
    pivot = a[middle];
}
