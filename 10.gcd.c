#include <stdio.h>

int gcd_cal(int m, int n);
int main(int argc, char* argv[])
{
    int m, n;
    char buf;
    printf("Enter fraction : ");
    scanf("%d%c%d", &m, &buf, &n);
    int gcd = gcd_cal(m, n);
    m = m / gcd;
    n = n / gcd;
    printf("gcd_cal %d\n", gcd);
    printf("lower term : %d%c%d", m, buf, n);
    return 0;
}

int gcd_cal(int m, int n)
{
    int temp;
    while (n > 0) {
        temp = n;
        n = m % n;
        m = temp;
    }
    return m;
}
