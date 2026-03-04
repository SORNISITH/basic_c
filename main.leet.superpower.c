#include <iso646.h>
#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

int ARR_2[2] = { 1, 0 };
int ARR_10[10] = { 9, 2, 1, 4, 5, 6, 7, 8, 1, 9 };
int ARR_128[128] = {
    8, 3, 7, 1, 5, 9, 2, 4, 6, 1, 7, 9, 2, 5, 3, 4, 8, 6, 1, 3, 2, 5, 7, 8, 6, 9, 4, 3, 1, 2, 6, 7, 8, 5, 1, 4, 9, 2, 3, 8, 5, 1, 7, 4, 2, 9, 6, 3, 8, 1, 2, 5, 4, 7, 3, 2, 6, 9, 8, 5, 3, 7, 1, 4, 9, 2, 6, 8, 5, 7, 4, 3, 1, 9, 6, 8, 2, 5, 1, 7, 8, 4, 2, 6, 3, 7, 9, 1, 5, 2, 8, 9, 3, 1, 4, 5, 6, 1, 2, 8, 4, 7, 9, 3, 5, 2, 1, 6, 7, 8, 9, 1, 4, 6, 3, 2, 5, 7, 8, 9
};

size_t ret_number_width_64(int* arr, int bSize)
{
    size_t cn = 0;
    if (bSize > 64) {
        printf("Maximun Size WIDTH 64");
        return 0;
    }
    for (int i = 0; i < bSize; ++i) {
        cn = cn * 10 + arr[i];
    }
    return cn;
}

int ppow(int m, int n)
{
    long long NN = n;
    if (NN == 0) {
        return 1;
    }
    int result = ppow(m, NN / 2);
    if (NN & 1) {
        return result * result * m;
    } else {
        return result * result;
    }
}

size_t extract_array_number(int* arr, int bSize)
{
    int len_should_be = 64 / bSize;
    size_t count = 0;

    if (bSize > 64) {
    } else {
        count = ret_number_width_64(arr, bSize);
    }
    return count;
}

int superPow(int a, int* b, int bSize)
{
    int exponent = extract_array_number(b, bSize);

    int ret = ppow(a, exponent);

    return ret;
}

int main(int argc, char* argv[])
{
    int x_10 = superPow(2, ARR_2, 2);
    printf("%d", x_10);

    return 0;
}
