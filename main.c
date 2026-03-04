#include <stdio.h>
int main()
{
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            int index = (3 - row - 1) * 3 + col + 1;
            printf("%d", index);
        }
        printf("\n");
    }
    return 0;
}
