#include <assert.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
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

char* digit_to_bin(int digit)
{
    assert(digit > 0);
    char result[32 + 1] = { 0 };
    char ret_bit = 0;
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
    unsigned char* dptr = (unsigned char*)&result;

    //    char* output = malloc(sizeof(*output) * ret_size);
    //    unsigned char* ptr = (unsigned char*)output + 3;
    return NULL;
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

#include <stdio.h>
int main(int argc, char* argv[])
{
    printf("%s", "hellow");
    init_base2();
    char* ind[10] = { 0 };
    digit_to_bin(999999);
    return 0;
}
