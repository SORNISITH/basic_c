#include <stdio.h>
#include <threads.h>

int euclid_gcd(int u, int v)
{
    if (u < v) {
        u ^= v;
        v ^= u;
        u ^= v;
    } // swwwup make sure u > v
    int temp;
    while ((temp = u % v) > 0) {
        u = v;
        v = temp;
    }
    return v;
}
int gcdOfOddEvenSums(int n)
{
    if (n < 1) {
        return 0;
    }
    int sum_even = n * n;
    int sum_odd = n * (n + 1);

    return euclid_gcd(sum_even, sum_odd);
}

int main()
{
    int x = gcdOfOddEvenSums(5);
    printf("%d", x);
    return 0;
}
