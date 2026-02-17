#include <stdio.h>
#include <stdlib.h>

#define YES 1
#define NO 0

int main(int argc, char* argv[])
{
    int c, nl = 0, nw = 0, nc = 0, inword;

    while ((c = getchar()) != EOF) {
        ++nc;
        if (c >= 33 && c <= 127) {
            ++nw;
            inword = YES;
        }
        if (c == '\n') {
            ++nl;
            inword = NO;
        }
    }
    printf("%d - %d - %d \n", nl, nw, nc);

    return EXIT_SUCCESS;
}
