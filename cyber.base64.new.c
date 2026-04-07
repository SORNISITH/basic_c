#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char cb64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char* get_bit_fchar(char c);

void merge_bit_(char* dst, size_t dst_size, const char* str)
{
    char* proc_bit = malloc(sizeof(char) * 8);
    for (int i = 0; i < strlen(str); i++) {
        char* temp = get_bit_fchar(str[i]);
        strcat(proc_bit, temp);
    }
    char* ptr_proc_bit = proc_bit;
    size_t index = 0;
    short limit = 2;
    *dst++ = '0';
    *dst++ = '0';
    while (*ptr_proc_bit && *ptr_proc_bit != '\0') {
        if (index < 6) {
            *dst = *ptr_proc_bit;
            ++ptr_proc_bit;
            ++index;
        } else {
            *dst++ = '0';
            *dst = '0';
            index = 0;
        }
        dst++;
    }
    free(proc_bit);
}

int byte_t_decimal(char* byte)
{
    size_t len = strlen(byte);
    char low_byte[8] = "00000000";
    char* ptr;
    if (len < 8) {
        for (int i = 7, k = len - 1; i >= 0; --i) {
            if (k >= 0) {
                low_byte[i] = byte[k];
                k--;
            } else {
            }
        }
        ptr = low_byte + 7;
    } else {
        ptr = byte + 7;
    }
    int sum = 0;
    int base_rev = 1;
    while (*ptr && *ptr != '\0') {
        if (*ptr == '1') {
            sum += base_rev;
        };
        base_rev <<= 1;
        --ptr;
    }
    return sum;
}

void read_base64_char(char* array_bit, char* dst)
{
    int index = 0;
    size_t len = strlen(array_bit);
    int char_count = len / 8;
    for (int i = 0; i < char_count; ++i) {
        char temp[8];
        for (int k = 0; k < 8; ++k) {
            if (*array_bit && *array_bit != '\0') {
                temp[k] = *array_bit;
                array_bit++;
            }
        }
        int dec = byte_t_decimal(temp);
        dst[i] = cb64[dec];
    }
}

char* encode_base64(const char* str)
{
    size_t len = strlen(str);
    size_t arr_len = len * 10;
    char* arr_bit = malloc(len * 10 + 1);
    char* encoded_string = malloc(arr_len / 8 + 1);
    merge_bit_(arr_bit, arr_len, str);
    read_base64_char(arr_bit, encoded_string);
    free(arr_bit);
    return encoded_string;
}

int main(int argc, char* argv[])
{
    char str[] = "ABC";
    char* encoded_str = encode_base64(str);

    puts(encoded_str);
    return 0;
}

char* get_bit_fchar(char c)
{
    // 000000xx00-1111xx1111xx000000xx00
    char* res = malloc(sizeof(char) * 8);
    char* ptr = res;
    for (int i = 7; i >= 0; --i, ptr++) {
        *ptr = ((c >> i) & 1) + '0'; // convert to char + '0'
    }
    *ptr = '\0'; // end of line
    return res;
}
