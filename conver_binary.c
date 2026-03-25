#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum {
    A = 10,
    B,
    C,
    D,
    E,
    F
};

int base2[INT_WIDTH + 1] = { 0 };
char* digit_to_bin(int dugit);
void init_base2();

int main(int argc, char* argv[])
{
    init_base2();

    char* x = digit_to_bin(9);
    while (*x != '\0') {
        printf("%c", *x);
        x++;
    }
    return 0;
}

char* digit_to_bin(int digit)
{
    assert(digit > 0);
    char* result = malloc(sizeof(char) * 32 + 1);
    memset(result, '0', sizeof((*result)));
    assert(result != NULL);
    for (int i = 32, tmp_d = digit, index = 0; i >= 1; --i) {
        if (tmp_d <= 0) {
            break;
        }
        if (tmp_d >= base2[i]) {
            result[index++] = '1';
            tmp_d -= base2[i];
        } else {
            result[index++] = '0';
        }
    }
    int index_ptr = -1;

    for (int i = 0; i < 32; i += 4) {
        if (index_ptr > 0) {
            break;
        } else {
            for (int k = i; k < (i + 4); ++k) {
                if (result[k] == '1') {
                    index_ptr = i;
                    break;
                }
            }
        }
    }

    assert(index_ptr > 0);

    char* ret_final = result + index_ptr;
    free(result);
    return ret_final;
}

void init_base2()
{
    for (int i = 1; i <= 32; ++i) {
        base2[i] = 1;
        if (i == 1) {
        } else if (i == 32) {
            base2[i] = base2[i - 1] + (base2[i - 1] - 1);
        } else {
            base2[i] = base2[i - 1] + base2[i - 1];
        }
    }
    assert(base2[32] == INT_MAX);
}
