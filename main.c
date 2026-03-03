#include <stdio.h>
int gcd(int m, int n)
{
    while (n != 0) {
        int temp = n;
        n = m % n;
        m = temp;
    }
    return m;
}
int main(int argc, char* argv[])
{
    printf("\n%d", gcd(35, 10));
    return 0;
}
