#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_ARR 250

char *reverse_sentence(char arr[]);
char *rm_white_space(char arr[], int arr_size);

int main(int argc, char *argv[]) {
  char sentence[SIZE_ARR];
  printf("Enter Sentence : ");
  fgets(sentence, sizeof(sentence), stdin);

  char *filter_arr = rm_white_space(sentence, SIZE_ARR);
  char *rv_sent = reverse_sentence(filter_arr);
  printf("%s", sentence);
  printf("%s", filter_arr);

  printf("%s", rv_sent);

  free(filter_arr);
  free(rv_sent);
  return 0;
}

char *reverse_sentence(char arr[]) {
  int len = strlen(arr);
  char *ptr = malloc(len + 1);
  if (!ptr)
    return NULL;
  int rv_index = len - 2;
  int position = 0;
  char last_q[32];
  memset(last_q, '.', strlen(last_q));
  while (rv_index >= 0) {
    while (arr[rv_index] == ' ' && arr[rv_index] == ' ') {
      rv_index--;
    }

    if (rv_index < 0) {
      break;
    }

    int end_q = rv_index;
    while ((arr[rv_index] == '?' || arr[rv_index] == '!') && rv_index >= 0) {
      rv_index--;
    }

    int start_q = rv_index + 1;
    for (int k = start_q, x = 0; k <= end_q; k++) {
      last_q[x] = arr[k];
    }

    int end_word = rv_index;
    while (rv_index >= 0 && arr[rv_index] != ' ') {
      rv_index--;
    }

    int start_word = rv_index + 1;
    for (int i = start_word; i <= end_word; i++) {
      ptr[position] = arr[i];
      position++;
    }

    if (rv_index >= 0) {
      ptr[position] = ' ';
      position++;
    }
  }

  for (int y = 0; y < strlen(last_q); y++) {

    if (last_q[y] == '.') {
      break;
    }
    ptr[position++] = last_q[y];
  }
  ptr[position] = '\0';

  return ptr;
}

char *reverse_array(char arr[], int arr_size) {
  int index = 0;
  char reverse_arr[arr_size];
  char *ptr = reverse_arr;
  ptr = malloc(SIZE_ARR);
  while (arr[index] != '\0') {
    index++;
  }

  for (int i = 0, k = index - 2; arr[i] != '\0'; i++, k--) {

    ptr[i] = arr[k];
  }

  return ptr;
}

char *rm_white_space(char arr[], int arr_size) {
  char rm_whitespace[arr_size];
  char *rm = rm_whitespace;
  rm = malloc(arr_size);
  short index = 0;
  short k = 0;
  while (arr[index] == ' ') {
    index++;
  }
  // remove first space    "    HELLO"
  // "HELLO      WORLD"
  while (arr[index] != '\0') {
    if (arr[index] == ' ' && arr[index + 1] == ' ') {
      index++;
      continue;
    }
    rm[k] = arr[index];
    k++;
    index++;
  }
  rm[k] = '\0';
  return rm;
}
