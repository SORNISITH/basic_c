#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *rm_white_space(char arr[]);
int main(int argc, char *argv[]) {
  char buf[250] = {0};
  printf("Enter FirstName & LastName : ");
  fgets(buf, sizeof(buf), stdin);

  char *clean_word = rm_white_space(buf);
  char first_name[128] = {0};
  char last_name[128] = {0};

  int index = 0;
  while (clean_word[index] != ' ') {
    if (index == 0) {
      first_name[index] = toupper(clean_word[index]);
    } else {
      first_name[index] = clean_word[index];
    }
    index++;
  }

  int k = 0;
  while ((clean_word[index]) != '\n') {
    if (clean_word[index] == ' ') {
      index++;
      continue;
    }
    if (k == 0) {
      last_name[k] = toupper(clean_word[index]);
    } else {
      last_name[k] = clean_word[index];
    }
    index++;
    k++;
  }

  printf("%s", last_name);
  printf(", %c.\n", first_name[0]);
  return 0;
}

char *rm_white_space(char arr[]) {
  static char rm_whitespace[250];
  short index = 0;
  short k = 0;
  while (arr[index] == ' ') {
    index++;
  } // remove first space    "    HELLO"
  //
  // "HELLO      WORLD"
  while (arr[index] != '\0') {
    if (arr[index] == ' ' && arr[index + 1] == ' ') {
      index++;
      continue;
    }
    rm_whitespace[k] = arr[index];
    k++;
    index++;
  }
  rm_whitespace[k] = '\0';
  return rm_whitespace;
}
