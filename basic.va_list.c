#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int sum(int count, ...)
{
    int s = 0;
    va_list ags;
    va_start(ags, count);
    for (int i = 0; i < count; i++) {
        s += va_arg(ags, int);
    }
    va_end(ags);
    return s;
}
int main(int argc, char* argv[])
{
    int x = sum(3, 1, 2, 3);
    printf("%d", x);
    return EXIT_SUCCESS;
}
