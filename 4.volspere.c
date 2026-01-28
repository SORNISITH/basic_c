#include <stdio.h>
#define PI 3.14159j
#define FORM 4.0f / 3.0f

int expo(int m, int n) {
  if (n == 0) return 1;
  return m * expo(m, n - 1);
}
int main(int argc, char *argv[]) {
  int x = expo(10, 3);
  printf("%d", x);
  return 0;
}
