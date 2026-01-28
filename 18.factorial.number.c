#include <stdio.h>
int main(int argc, char* argv[])

{
    short number_input;
    long long result = 1;
    printf("Enter a Positive Number : ");
    scanf("%hd", &number_input);
    if (number_input < 0)
        return -1;

    printf("\n===============================\n");
    printf("        Factorial Table\n");
    printf("===============================\n");
    printf("  n  |     n!  \n");
    printf("-----|-------------------------\n");
    for (int i = 1; i <= number_input; i++) {
        result *= i;
        printf("%3d  |%25lld\n", i, result);
    }

    return 0;
}
