#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lengthOfLastWord(char* s)
{
    int len = strlen(s);
    if (len < 1)
        return len;
    char* p = s + len - 1;
    while (p >= s && *p == ' ') {
        p--;
    }
    int result = 0;
    while (p >= s && *p != ' ') {
        result++;
        p--;
    }

    return result;
}
int main(int argc, char* argv[])
{
    char myword[] = "   fly me   to   the moon  ";
    int x = lengthOfLastWord(myword);
    printf("%d", x);
    return EXIT_SUCCESS;
}
