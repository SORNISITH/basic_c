#include <stdio.h>
int main(int argc, char* argv[])
{
    short x = 0;
    int n;
    double e = 1.0;
    double factorial = 1.0;

    printf("Enter the of N : ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        factorial *= i;
        e += 1.0f / factorial;
    }
    printf("Approximation of e %.10f\n", e);
    printf("Actual valueue of e:  %.10f\n", 2.7182818285);
    return 0;
}
