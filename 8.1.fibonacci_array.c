#include <stddef.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[])
{
    int fabs[40] = { [0] = 0, [1] = 1, [2] = 1 };
    size_t len = sizeof(fabs) / sizeof(fabs[0]);

    for (int i = 3; i < len; i++) {
        fabs[i] = fabs[i - 1] + fabs[i - 2];
    }

    for (int i = 0, k = 0; i < len; i++, k++) {
        if (k == 5) {
            printf("\n");
            k = 0;
        }
        printf("%10d , ", fabs[i]);
    }

    return 0;
}
