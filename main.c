#include <stdio.h>
#include <stdlib.h>
int sum_arr(int n, int* const arr)
{

    int* p = arr;
    int temp = 0;
    while (p < arr + n) {
        temp += *p++;
    }

    return temp;
}
int main(int argc, char* argv[])
{
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int* p = a;
    int* q = a + (10 - 1);
    int* r = a;
    // for (; r < a + 10 1; r++) {
    //     printf("%d ", *r);
    // }
    int x = sum_arr(10, a);

    printf("%d", x);

    // while (p < q) {
    //     temp = *p;
    //     *p++ = *q;
    //     *q-- = temp;
    // }
    // printf("\n");
    //
    // for (; r < a + 10; r++) {
    //     printf("%d ", *r);
    // }

    return EXIT_SUCCESS;
}
