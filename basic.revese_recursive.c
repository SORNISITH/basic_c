#include "stdio.h"
#include "stdlib.h"
#include "string.h"
char *result;
void reverse_string(char *s, int slen, int i);
void r_string(const char *src, char *dst);
int main(void) {
  char *word = "myworld";
  int slen = strlen(word) - 1;
  int init = 0;
  result = malloc(slen + 1);
  reverse_string(word, slen, init);
  char out[100];
  r_string("myworld", out);
  printf("%s\n", out);
  printf("%s", result);
  return 0;
}
void r_string(const char *src, char *dst) {
  int len = strlen(src);
  for (int i = 0; i < len; i++) dst[i] = src[len - 1 - i];
  dst[len] = '\0';
}

void reverse_string(char *s, int slen, int i) {
  if (slen < 0) {
    result[i] = '\0';
    return;
  }
  result[i] = s[slen];
  reverse_string(s, slen - 1, i + 1);
}
