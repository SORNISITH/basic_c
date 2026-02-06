#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

bool isPalindrome(int x)
{
    int ori = x;
    uint64_t reverse = 0;
    if (x < 0) {
        return false;
    }
    while (x > 0) {
        int digit = x % 10;
        reverse = reverse * 10 + digit;
        x /= 10;
    }

    if (ori != reverse) {
        return false;
    }
    return true;
}

int main(int argc, char* argv[])
{
    if (isPalindrome(-121)) {
        printf("palindrome");
    } else {
        printf(" notpalindrome");
    }
    return EXIT_SUCCESS;
}
