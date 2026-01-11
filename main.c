#include <stdio.h>

void swap(int *x, int *y);
int main(int argc, char *argv[]) {
  int a, b;
  a = 10;
  b = 20;
  swap(&a, &b);
  printf("A : %d B : %d", a, b);
  return 0;
}

void swap(int *x, int *y) {
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}
