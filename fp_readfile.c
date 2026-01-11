#include "stdio.h"
#define SIZE_ARR 1000
#define SIZE 1024
int readFileText();
// remove all comments from a C programing
int main() {
  readFileText();
  return 0;
}

int readFileText() {
  FILE *fp;
  char buffer[SIZE];
  fp = fopen("test.c", "r");
  if (fp == NULL) {
    perror("file open failed");
    return 1;
  }

  printf("%s", buffer);
  fgets(buffer, SIZE, fp);
  // while (fgets(buffer, SIZE, fp) != NULL) {
  //   printf("%s", buffer);
  // }
  for (int i = 0; i < 10; i++) {
    printf("%c", buffer[i]);
  }
  fclose(fp);
  return 0;
}
