#include <stdio.h>

double myPow(double x, int n)
{
    long long N = n;
    if (N < 0) {
        x = 1 / x;
        N = -N;
    }
    if (N == 0) {
        return 1;
    }
    double h = myPow(x, N / 2);
    if (N % 2 == 0) {
        return h * h;
    } else {
        return h * h * x;
    }
}

int main(int argc, char* argv[])
{
  double x = myPow(2.0000, 10);
  printf("%f", x);
  int y =20000;
  int z = 10;
  printf("%d", z & 1);
  return 0;
}
