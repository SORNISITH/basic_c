#include <assert.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hex_parsing_number(char hex);
char* hex_to_bin(int hex);
char* convert_hex_to_bin(int hex)
{
    int max_hex_len = 8;
    char* shex = calloc(max_hex_len + 1, sizeof(char));
    char* str_hex = shex;
    sprintf(str_hex, "%x", hex);
    char* bit_output = calloc((max_hex_len * 4) + 1, sizeof(char));
    while (*str_hex != '\0') {
        int hp = hex_parsing_number(*str_hex);
        char* tmp_bit = hex_to_bin(hp);
        strcat(bit_output, tmp_bit);
        free(tmp_bit);
        str_hex++;
    }
    free(shex);
    return bit_output;
}

int main(int argc, char* argv[])
{
    char* x = convert_hex_to_bin(0xFF);
    puts(x);
    free(x);
    return 0;
}

char* hex_to_bin(int hex)
{
    assert(hex <= 16);
    char* output = calloc(5, sizeof(char));
    int bit_4 = 8;
    for (char* i = output; i < output + 4; ++i) {
        if (bit_4 <= 0) {
            break;
        }
        if (hex < bit_4) {
            *i = '0';
        } else if (hex >= bit_4) {
            *i = '1';
            hex -= bit_4;
        }
        bit_4 /= 2;
    }
    return output;
}

int hex_parsing_number(char hex)
{
    int ret = 0;
    switch (hex) {
    case 'a': {
        ret = 10;
        break;
    }
    case 'b': {
        ret = 11;
        break;
    }
    case 'c': {
        ret = 12;
        break;
    }
    case 'd': {
        ret = 13;
        break;
    }
    case 'e': {
        ret = 14;
        break;
    }
    case 'f': {
        ret = 15;
        break;
    }
    default:
        ret = hex - '0';
    }
    return ret;
}
