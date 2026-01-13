#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void scmp(char *o, char *n);
int main(int argc, char *argv[]) {
  char *originalText = "Helllo owrld";
  char *new;
  new = malloc(strlen(originalText));
  scmp(originalText, new);
  printf("%s", new);

  free(new);
  return 0;
}

void scmp(char *o, char *n) {
  while ((*n++ = *o++) != '\0') {
    ;
  }
}
