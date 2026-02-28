#include <stdio.h>
#include <stdlib.h>
int return_digit_position(int digit, int k)
{
    char str_digit[32];
    char rev_str_digit[32];
    sprintf(str_digit, "%d", digit);
    int len = 0;
    for (int i = 0; str_digit[i] != '\0'; i++) {
        len++;
    }

    for (int z = len - 1, j = 0; z >= 0; z--, j++) {
        rev_str_digit[j] = str_digit[z];
    }
    return (k > 0 && k <= len) ? rev_str_digit[k - 1] - '0' : -1;
}
int main(int argc, char* argv[])
{
    int x = return_digit_position(897, 3);
    printf("%d", x);
    return EXIT_SUCCESS;
}
