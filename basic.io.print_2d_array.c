#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main(int argc, char* argv[])
{
    return EXIT_SUCCESS;
}

int* create_2d_array(int row, int col)
{
    srand(time(NULL));
    int (*arr)[col] = malloc(row * sizeof(int[col]));

    int* p = *arr;

    return *arr;
}

// int arr[10][10];
//   memset(arr, 0, sizeof(arr));
//   int* row;
//   int i = 0;
//   for (i = 0, row = *arr; row < *arr + 10; row++) {
//       *row = 1;
//   }
//
//   int (*col)[10];
//   for (col = arr; col < arr + 10; col++) {
//       (*col)[5] = 9;
//   }
