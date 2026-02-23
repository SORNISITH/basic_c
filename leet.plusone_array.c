#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_arr(const int* arr, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d-", arr[i]);
    }
}

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int byte = sizeof(int) * (digitsSize + 1);
    int ori_byte = sizeof(int) * (digitsSize);

    int* answer = calloc(digitsSize + 1, sizeof(int));
    memset(answer, 0, byte);

    int* rev_digits = digits + digitsSize - 1;
    int* ptr_first = answer;
    int* ptr_last = answer + digitsSize;
    *ptr_last = 0;
    *returnSize = 0;

    if (*rev_digits < 9) {
        memcpy(answer, digits, ori_byte);
        *returnSize = digitsSize;
        *(ptr_last - 1) = *rev_digits + 1;
    } else {

        bool isfound = false;
        // pusto stack first
        //     // deal with  9 , 9 ,9 ,9 ,9 + 1
        for (; ptr_first < ptr_last; rev_digits--, ptr_first++) {
            *ptr_first = *rev_digits;
            if (!isfound) {
                if (*ptr_first == 9) {
                    *ptr_first = 0;
                    *returnSize += 1;
                } else if (*ptr_first != 9 && ptr_first < ptr_last) {
                    *ptr_first += 1;
                    *returnSize += 1;
                    isfound = true;
                }
            } else {
                *returnSize += 1;
            }
        }
        if (!isfound) {
            *ptr_last += 1;
            *returnSize += 1;
        }
        int* ptr_final_first = answer;
        int* ptr_final_last = answer + (*returnSize) - 1;
        while (ptr_final_first < ptr_final_last) {
            *ptr_final_first ^= *ptr_final_last;
            *ptr_final_last ^= *ptr_final_first;
            *ptr_final_first ^= *ptr_final_last;
            ptr_final_first++;
            ptr_final_last--;
        }
    }

    return answer;
}
int* plusOne_test_other(int* digits, int digitsSize, int* returnSize)
{
    int* res = (int*)calloc((digitsSize + 1), sizeof(int));
    for (int i = 0; i < digitsSize; i++)
        res[i] = digits[i];
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (res[i] != 9) {
            res[i] += 1;
            *returnSize = digitsSize;
            return res;
        } else
            res[i] = 0;
    }
    res[0] += 1;
    *returnSize = digitsSize + 1;
    return res;
}
int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
    int digit[] = { 9, 9, 9, 9 };
    // int digit[] = { 9, 1, 2, 3, 4 };
    //   int digit[] = { 9 };
    int size = sizeof(digit) / sizeof(digit[0]);
    int reSize = 0;
    int reSize_2 = 0;
    int* result = plusOne(digit, size, &reSize);
    int* result_2 = plusOne_test_other(digit, size, &reSize_2);
    display_arr(result, reSize);
    printf("\n");
    display_arr(result_2, reSize_2);
    free(result);
    return EXIT_SUCCESS;
}
