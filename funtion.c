#include "stdio.h"

int power(int m, int n);
int main() {
  printf("%d", power(2, 3));
  printf("%d", power(2, 10));
  return 0;
}

int power(int m, int n) {
  if (n == 0) return 1;
  return m * power(m, n - 1);
}
