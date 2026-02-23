#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
char* addBinary(char* a, char* b)
{

    return NULL;
}

char* addBinary_LOONG_NUMBER_METHOD(char* a, char* b)
{
    // can not holder bigger than  64 bit
    size_t len_of_a = strlen(a);
    size_t len_of_b = strlen(b);
    size_t ret_len_result = (len_of_a >= len_of_b) ? len_of_a : len_of_b;

    unsigned long long a_to_number = strtoull(a, NULL, 2);
    unsigned long long b_to_number = strtoull(b, NULL, 2);
    if (a_to_number * 2 >= LLONG_MAX || b_to_number * 2 >= LLONG_MAX) {
        return NULL;
    }

    unsigned long long sum = a_to_number + b_to_number;
    char* result = calloc(sizeof(char), ret_len_result + 2);
    bool collect_result_status = false;
    char* ptr = result;
    if (sum == 0) {
        *result = '0';
        *(ptr + 1) = '\0';
        return result;
    }
    for (int i = 63; i >= 0; i--) {
        int tmp = ((sum >> i) & 1);
        if (tmp == 1 && (collect_result_status == false)) {
            collect_result_status = true;
        }
        if (collect_result_status == true) {
            *ptr = tmp + '0';
            ptr++;
        }
    }
    *ptr = '\0'; // terminate the string
    return result;
}

int main(int argc, char* argv[])
{
    char* a = "0";
    char* b = "0";
    char* x = addBinary(a, b);
    if (x != NULL) {
        puts(x);
        free(x);
    }
    return EXIT_SUCCESS;
}
char calculate_bit(char a, char b)
{
    if ((a == '0' && b == '0') || (b == '1' && a == '1')) {
        return '0';
    }
    return '1';
}
// char* addBinary_erroh(char* a, char* b)
// {
//     size_t len_a = strlen(a);
//     size_t len_b = strlen(b);
//     size_t answer_len = len_a >= len_b ? len_a : len_b;
//
//     int ja = len_a - 1;
//     int jb = len_b - 1;
//
//     char* answer = calloc(answer_len, sizeof(char));
//     char* answer_add_space = calloc(answer_len + 1, sizeof(char));
//     char carry = '0';
//
//     for (int i = answer_len; i >= 0; i--, ja--, jb--) {
//         char temp_a = ((ja < 0) || (a[ja] == '0')) ? '0' : '1';
//         char temp_b = ((jb < 0) || (b[jb] == '0')) ? '0' : '1';
//         char result = calculate_bit(temp_a, temp_b);
//         if (carry == '1') {
//             answer[i] = calculate_bit(result, carry);
//         } else {
//             answer[i] = result;
//         }
//         carry = (temp_a == '1' && temp_b == '1') ? '1' : '0';
//     }
//
//     printf("%c", carry);
//     // if (answer[0] == '0') {
//     //     memmove(answer_add_space, answer + 1, answer_len);
//     //     free(answer);
//     //     return answer_add_space;
//     // }
//     return answer;
// }
