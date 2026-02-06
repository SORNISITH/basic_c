#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char** argv)
{

    int i;
    int j;
    char s[72];
    scanf("%d%s%d", &i, s, &j);

    printf("%d-%d", i, j);
    puts(s);

    return EXIT_SUCCESS;
}
