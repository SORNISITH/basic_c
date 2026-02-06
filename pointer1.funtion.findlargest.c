#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void find_two_largest(int n, int* const arr, int* first_large, int* second_large);
int* find_largest(const int n, const int arr[n]);
int main(int argc, char* argv[])
{
    int arr[SIZE] = { 8, 2, 1, 3, 88 };
    int largest;
    int second_largest;
    find_two_largest(SIZE, arr, &largest, &second_largest);
    printf("largest : %d\n", largest);
    printf("second largest : %d", second_largest);
    int* ll = find_largest(SIZE, arr);

    printf("\n%d\n", *ll);
    return EXIT_SUCCESS;
}

int* find_largest(const int n, int const arr[n])
{
    static int largest;
    largest = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return &largest;
}

void find_two_largest(int n, int* const arr, int* first_large, int* second_large)
{
    int* p = arr;
    *first_large = arr[0];
    *second_large = 0;

    while (++p < arr + n) {
        if (*p > *first_large) {
            *first_large = *p;
        } else if (*p > *second_large) {
            *second_large = *p;
        }
    }
}
