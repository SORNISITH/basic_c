#include "ctype.h"
#include "stdio.h"

#define ARRAY_SIZE 10
int ex1();
int ex2();

int main() {
  ex2();
  return 0;
}

int ex2() {
  int c, other, white, digitSequence, charSequence, histogram;
  int arrayDigit[ARRAY_SIZE];
  char arrayChar[ARRAY_SIZE];

  other = white = digitSequence = histogram = 0;
  printf("USER INPUT : ");
  for (int i = 0; i < ARRAY_SIZE; i++) {
    arrayDigit[i] = 0;
  }

  //
  while (c != EOF) {
    if ((digitSequence < ARRAY_SIZE) && (c >= '0') && (c <= '9')) {
      printf("%d", c);
      arrayDigit[digitSequence++] = c - '0';
    } else if ((charSequence < ARRAY_SIZE) && (c > '9')) {
      arrayChar[charSequence++] = (char)c;
      ++histogram;
    } else if (c == ' ') {
      ++white;
    } else {
      ++other;
    }
    if (c == '\n') {
      printf("\n");
      printf("\t WHITE SPACE %d", white);
      printf("\n");
      printf("\t TABS  %d", other);
      printf("\n");
      printf("\t DIGIT ARRAY = ");
      for (int i = 0; i < ARRAY_SIZE; i++) {
        if (i == ARRAY_SIZE - 1) {
          printf("%d\n", arrayDigit[i]);
        } else {
          printf("%d-", arrayDigit[i]);
        }
      }
      printf("\t CHAR ARRAY = ");
      for (int i = 0; i < ARRAY_SIZE; i++) {
        if (i == ARRAY_SIZE - 1) {
          printf("%c\n", arrayChar[i]);
        } else {
          printf("%c-", arrayChar[i]);
        }
      }
      printf("\n");
      printf("\t CHAR INPUT COUNT : ");
      for (int i = 0; i < histogram; i++) {
        printf("_ ");
      }
      printf("\n");
      for (int i = 0; i < ARRAY_SIZE; i++) {
        arrayDigit[i] = 0;
      }
      digitSequence = 0;
      charSequence = 0;
      other = 0;
      histogram = 0;
      printf("USER INPUT : ");
    }
    c = getchar();
  }
  return 0;
}

int ex1() {
  double c, tab, line, blank;
  int word;
  printf("PLEASE ENTER : ");
  c = getchar();
  word = 0;
  while (c != EOF) {
    if (c == '\t') {
      ++tab;
      printf("\t NEW TABS = %.0f\n", tab);
    } else if (c == '\n') {
      ++line;
      printf("\t TOTALWORD = %d  \n", word);
      word = 0;
      printf("\t NEW LINES = %.0f\n", line);
    } else if (c != ' ') {
      ++word;
      if (!isalpha(c)) {
        printf("NUMBER : ");
      } else {
        printf("CHAR : ");
      }
      putchar(c);
      printf("\n");
    }
    c = getchar();
  }
  return 0;
}
