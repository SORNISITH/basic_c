#include "stdio.h"
void deleteMatch(char s1[], char s2[]);
int main() {
  char s1[] = "HELLOW";
  char s2[] = "EL";
  deleteMatch(s1, s2);

  return 0;
}
void deleteMatch(char s1[], char s2[]) {
  int i, j, k;
  int found;
  i = j = k = 0;

  for (i = 0; s1[i] != '\0'; i++) {
    found = 0;

    for (j = 0; s2[j] != '\0'; j++) {
      if (s1[i] == s2[j]) {
        found = 1;
        break;
      }
    }
    if (!found) {
      s1[k++] = s1[i];
    }
  }
  s1[k] = '\0';

  printf("%s", s1);
}
