#include <stdio.h>
#include <string.h>

#define SIZE 99

void move(int a[SIZE][SIZE], int count, int size);
void print_2d_arr(int a[SIZE][SIZE], int size);
int main(int argc, char *argv[]) {
  int square[SIZE][SIZE];
  memset(square, 0, sizeof(square));

  int n = 0;
  printf("Enter Size 1-99 (ODD) : ");
  scanf("%d", &n);
  int count = n * n;
  move(square, count, n);
  print_2d_arr(square, n);
  return 0;
}

void move(int a[SIZE][SIZE], int count, int size) {
  int current_position_row;
  int current_position_col;
  int number;
  current_position_row = 0;
  current_position_col = ((size - 1) / 2);
  number = 1;
  if (number > count) {
    return;
  }
  int len = size - 1;
  int last_row = len;
  int last_col = len;

  if (number == 1) {
    a[current_position_row][current_position_col] = number;
  }

  while (number <= count) {
    int temp_row = current_position_row;
    int temp_col = current_position_col;

    if (temp_row == 0) {
      temp_row = last_row;
    } else if (temp_row <= size) {
      temp_row -= 1;
    }

    if (temp_col == last_col) {
      temp_col = 0;
    } else {
      temp_col += 1;
    }

    if (a[temp_row][temp_col] == 0) {
      number++;
      current_position_row = temp_row;
      current_position_col = temp_col;
      a[current_position_row][current_position_col] = number;
    } else if (a[temp_row][temp_col] != 0) {
      number++;
      current_position_row += 1;
      a[current_position_row][current_position_col] = number;
    } // move if free space
  }
}

void print_2d_arr(int a[SIZE][SIZE], int size) {
  printf("\n");
  for (int i = 0; i < size; i++) {
    for (int k = 0; k < size; k++) {
      printf(" %2d ", a[i][k]);
    }
    printf("\n");
  }
  printf("\n");
}
