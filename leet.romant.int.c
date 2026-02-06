#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int roman_letter[256] = {
    ['M'] = 1000,
    ['D'] = 500,
    ['C'] = 100,
    ['L'] = 50,
    ['X'] = 10,
    ['V'] = 5,
    ['I'] = 1,
    ['m'] = 1000,
    ['d'] = 500,
    ['c'] = 100,
    ['l'] = 50,
    ['x'] = 10,
    ['v'] = 5,
    ['i'] = 1,
};
int romanToInt(char* arr)
{
    int sum = 0;

    short len = strlen(arr) - 1;
    for (int i = 0; i <= len; i++) {

        if ((roman_letter[arr[i]]) < (roman_letter[arr[i + 1]])) {
            sum -= roman_letter[arr[i]];
        } else {
            sum += roman_letter[arr[i]];
        }
    }
    return sum;
}
int main(int argc, char* argv[])
{
    int x = romanToInt("MCMXCIV");

    printf("%d : ", x);
    return EXIT_SUCCESS;
}
