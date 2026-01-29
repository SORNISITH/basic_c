#include <stdio.h>
int isPrime(int n)
{
    if (n == 2)
        return 1;
    if (n <= 1 || n % 2 == 0)
        return 0;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char* argv[])
{
    int n;

    while (1) {
        printf("Enter Numbeer : ");
        scanf(" %d", &n);

        if (isPrime(n)) {
            printf("%d : Prime !!!! \n", n);
        } else {
            printf("%d : not Prime \n", n);
        }
    }
    return 0;
}
