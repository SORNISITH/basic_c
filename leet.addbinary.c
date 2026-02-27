#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* addBinary(char* a, char* b)
{
    int a_len = strlen(a);
    int b_len = strlen(b);
    int result_len = a_len >= b_len ? a_len : b_len;
    result_len += 1;
    char* result_bit = calloc(result_len, sizeof(char));

    if (result_len == 0) {
        *result_bit = '0';
        return result_bit;
    }
    char* ptr_end_of_a = a + a_len - 1;
    char* ptr_end_of_b = b + b_len - 1;
    char* ptr_end_of_result = result_bit + result_len - 2;

    short carry = 0;
    int i = 0;
    while (ptr_end_of_result >= result_bit) {
        short temp_a = 0;
        short temp_b = 0;
        if (ptr_end_of_a >= a) {
            temp_a = *ptr_end_of_a - '0';
            ptr_end_of_a--;
        } //----------------------------------------------//
        if (ptr_end_of_b >= b) {
            temp_b = *ptr_end_of_b - '0';
            ptr_end_of_b--;
        } //------------------Calculate-------------------//
        short res_in_current_place = temp_a ^ temp_b ^ carry;
        *ptr_end_of_result = res_in_current_place + '0';
        carry = (temp_a & temp_b) | (carry & (temp_a ^ temp_b));
        ptr_end_of_result--; //---------------------------//
    }

    // return must start with  '1' so we move mem
    bool what_to_return = (*result_bit == '0') ? true : false;
    if (what_to_return) {
        char* final_bit = calloc(result_len, sizeof(char));
        memmove(final_bit, result_bit + 1, result_len - 1);
        free(result_bit);
        return final_bit;
    }
    return result_bit;
}
[[maybe_unused]] char* addBinary_LOONG_NUMBER_METHOD(char* a, char* b)
{
    // can not holder bigger than  64 bit
    size_t len_of_a = strlen(a);
    size_t len_of_b = strlen(b);
    size_t ret_len_result = (len_of_a >= len_of_b) ? len_of_a : len_of_b;
    char* ptr_last_of_a = a + len_of_a - 1;
    char* ptr_last_of_b = a + len_of_b - 1;

    unsigned long long a_to_number = strtoull(a, NULL, 2);
    unsigned long long b_to_number = strtoull(b, NULL, 2);
    if (a_to_number * 2 >= LLONG_MAX || b_to_number * 2 >= LLONG_MAX) {
        return NULL;
    }

    unsigned long long sum = a_to_number + b_to_number;
    char* result = calloc(1, ret_len_result + 2);
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

int main(int argc [[maybe_unused]], [[maybe_unused]] char* argv[])
{
    char* al = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101";
    char* bl = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";
    char* a = "11";
    char* b = "11";
    char* x = addBinary(al, bl);
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
