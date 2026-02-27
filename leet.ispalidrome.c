#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool valueidchar(char tmp)
{
    return ((tmp < 48 || tmp > 57) && (tmp < 97 || tmp > 122) && (tmp > 90 || tmp < 65));
}

bool isPalindrome(char* s)
{

    int len_of_s = strlen(s);
    char *ptr_s = s, *ptr_e = s + len_of_s - 1;

    if (len_of_s < 2 && *s == ' ') {
        return true;
    }

    while (ptr_s <= ptr_e) {
        while (ptr_s <= ptr_e) {
            int tmp = *ptr_s;
            if (valueidchar(tmp)) {
                ptr_s++;
            } else {
                break;
            }
        }
        while (ptr_s <= ptr_e) {
            int tmp = *ptr_e;
            if (valueidchar(tmp)) {
                ptr_e--;
            } else {
                break;
            }
        }

        if (ptr_s <= ptr_e) {
            int tmp_x = tolower(*ptr_s);
            int tmp_y = tolower(*ptr_e);
            if (!valueidchar(tmp_x) && !valueidchar(tmp_y)) {
                if (tmp_x != tmp_y) {
                    return false;
                }
            }
        }
        ptr_s++;
        ptr_e--;
    }

    return true;
}
int main(int argc, char* argv[])
{

    //  printf("\n%d", isPalindrome("0A man, a plan, a canal: Panama"));
    printf("\n%d", isPalindrome(".;"));

    return EXIT_SUCCESS;
}
