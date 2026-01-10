#include "stdio.h"
#include "string.h"
#define MAXLINE 100

void reverseString(char s[], char new[]);
void copy(char to[], char from[]);
int getLine(char s[], int limit);
void removeBlank(char s[], char new[]);
int main() {
  int len, max, opt;
  char line[MAXLINE], reverseLine[MAXLINE], longest[MAXLINE],
      filterLine[MAXLINE];
  max = 0;
  printf("OPTIONS : (1)-getinput (2)-reverse \n _ ");
  opt = getchar();
  while ((len = getLine(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      removeBlank(line, filterLine);
      reverseString(filterLine, reverseLine);
      copy(longest, filterLine);
    }
    printf("Current INPUT : %s ", filterLine);
    printf("REVERSE INPUT : %s ", reverseLine);
    if (max > 0) printf("LONGEST INPUT : %s \n", longest);
  }

  return 0;
}
int getLine(char s[], int limit) {
  int c, i;
  printf("USER INPUTS : _ ");
  for (i = 0; i < limit - 1 && ((c = getchar()) != EOF) && c != '\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void reverseString(char s[], char new[]) {
  int i, k;
  i = 0;
  k = strlen(s) - 1;
  while (s[i] != '\0') {
    new[k] = s[i];
    i++;
    k--;
  }
  new[i + 1] = '\0';
}
void removeBlank(char s[], char new[]) {
  int i, j;
  i = 0;
  j = 0;
  for (i = 0; s[i] != '\0'; i++) {
    if ((s[i] != '\t') && (s[i] != ' ')) {
      new[j++] = s[i];
    }
  }
  new[j] = '\0';
}

void copy(char to[], char from[]) {
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
