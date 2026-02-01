#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int* find_largest(const int n, const int arr[n]);
void find_two_largest(const int n, const int arr[n], int* l, int* sl);
int main(int argc, char* argv[])
{
    const int arr[SIZE] = { 8, 2, 1, 3, 88 };
    int largest;
    int second_largest;
    find_two_largest(SIZE, arr, &largest, &second_largest);
    printf("largest : %d\n", largest);
    printf("second largest : %d", second_largest);
    int* ll = find_largest(SIZE, arr);

    printf("\n%d\n", *ll);
    return EXIT_SUCCESS;
}

int* find_largest(const int n, const int arr[n])
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

void find_two_largest(const int n, const int arr[n], int* l, int* sl)
{
    *l = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > *l) {
            *sl = *l;
            *l = arr[i];
        } else if (arr[i] < *l && arr[i] > *sl) {
            *sl = arr[i];
        }
        printf("-  %d\n", *sl);
    }
}
