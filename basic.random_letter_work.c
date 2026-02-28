#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void move(int *row, int *col, char test_board_game[10][10], char *win_lose);
int main(int argc, char *argv[]) {
  // A 65  Z 90
  srand(time(NULL));
  int row = rand() % 9;
  int col = rand() % 9;
  // 1 = rigth 2 = left 3 = up  4 = down
  char win_lose = ' ';
  int az_charactor[26];
  char board_game[10][10];
  memset(board_game, '.', sizeof(board_game));
  for (int i = 65, k = 0; k < 26; i++, k++) {
    az_charactor[k] = i;
  }
  printf("\t-- GAME ON --\n");
  for (int i = 0; i < 26; i++) {
    if (i == 0) {
      board_game[row][col] = az_charactor[i];
    } else {
      move(&row, &col, board_game, &win_lose);
      if (win_lose != ' ') {
        break;
      }
      board_game[row][col] = az_charactor[i];
    }
  }
  printf("\t A start @ %d-%d\n", row, col);
  printf("-----------------------------\n");
  for (int i = 0; i < 10; i++) {
    if (i == 0) {
      printf("X");
    }
    printf(" %d ", i);
  }

  printf("\n");
  for (int i = 0; i < 10; i++) {
    printf("%d", i);
    for (int k = 0; k < 10; k++) {
      printf(" %c ", board_game[i][k]);
    }
    printf("\n");
  }
  printf("\n");

  if (win_lose != ' ') {
    printf("you lose at charactor can not move :  %c \n", win_lose);
  } else {
    printf("you win :  Z \n");
  }
  printf("\n");
  return 0;
}

void move(int *row, int *col, char test_board_game[10][10], char *win_lose) {
  int random_turn = rand() % 4 + 1;
  int temp_row = *row;
  int temp_col = *col;

  if (test_board_game[temp_row][temp_col + 1] != '.' &&
      test_board_game[temp_row][temp_col - 1] != '.' &&
      test_board_game[temp_row + 1][temp_col] != '.' &&
      test_board_game[temp_row - 1][temp_col] != '.') {
    *win_lose = test_board_game[temp_row][temp_col];
    return;
  }

  if (random_turn == 1) {
    temp_col += 1;
  } else if (random_turn == 2) {
    temp_col -= 1;
  } else if (random_turn == 3) {
    temp_row -= 1;
  } else if (random_turn == 4) {
    temp_row += 1;
  }

  if (temp_col >= 0 && temp_col < 10 && temp_row >= 0 && temp_row < 10) {
    if (test_board_game[temp_row][temp_col] == '.') {
      *row = temp_row;
      *col = temp_col;
      return; // Success - stop
    }
  }
  move(row, col, test_board_game, win_lose);
}
