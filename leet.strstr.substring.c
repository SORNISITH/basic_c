#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// int calculate(char* str, int start, int end)
// {
//     int temp_sum = 0;
//     for (char *s = str + start, *e = str + start + end; s <= e; s++, e--) {
//         if (s == e) {
//             temp_sum += (int)(*s);
//             break;
//         }
//         temp_sum += (int)(*s + *e);
//     }
//     return temp_sum;
// }
//
// int strStr(char* haystack, char* needle)
// {
//     int len_of_haystack = strlen(haystack);
//     int len_of_needle = strlen(needle);
//     if (len_of_needle > len_of_haystack || len_of_haystack < 1 || len_of_needle < 1) {
//         return -99;
//     }
//     int sum_of_needle = calculate(needle, 0, len_of_needle - 1);
//     char* ptr_haystack = haystack;
//     int start_index = 0; // find
//     int end_index = len_of_haystack - 1; // find
//     short find_status = -1;
//     for (; start_index <= len_of_haystack - len_of_needle; start_index++, end_index--) {
//         int tmp_sum = calculate(haystack, start_index, len_of_needle - 1);
//         int tmp_sum_2 = calculate(haystack, end_index - len_of_needle - 1, len_of_needle - 1);
//         if (tmp_sum == sum_of_needle) {
//             find_status = start_index;
//             break;
//         } else if (tmp_sum_2 == sum_of_needle) {
//             find_status = end_index;
//             break;
//         }
//     }
//
//     return find_status;
// }

int strStr(char* haystack, char* needle)
{
    int len_of_needle = strlen(needle);
    int len_of_haystack = strlen(haystack);
    if (len_of_needle > len_of_haystack || len_of_haystack < 1 || len_of_needle < 1) {
        return -1;
    }

    int start_index_haystack = 0;
    int end_index_haystack = len_of_haystack - len_of_needle;

    // 2 pointer find first word
    //
    int found_index = -1;
    for (char *start = haystack + start_index_haystack, *end = haystack + end_index_haystack; start <= end; start++) {
        if (found_index != -1) {
            break;
        };
        if (*start == *needle) {
            char* tmp_start = start;
            char* tmp_needle_start = needle;
            int check_match = 0;
            for (; tmp_needle_start < needle + len_of_needle; tmp_needle_start++, tmp_start++) {
                if (*tmp_start != *tmp_needle_start) {
                    break;
                } else {
                    check_match++;
                    if (check_match == len_of_needle) {
                        return (found_index = start - haystack);
                    }
                }
            }
        }
    }
    return found_index;
}

int main(void)
{
    int x = strStr("hellwomyworld", "hll");

    printf("\n%d", x);
    return EXIT_SUCCESS;
}
