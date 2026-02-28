#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
  // ydk  ==  kyd;
  char first_word[32];
  char second_word[32];
  printf("Enter an WORD : ");
  fgets(first_word, sizeof(first_word), stdin);
  printf("Enter an WORD : ");
  fgets(second_word, sizeof(second_word), stdin);

  int len = strlen(first_word);
  int len_2 = strlen(second_word);

  int check_anagram[len];
  int check_anagram_2[len];

  memset(check_anagram, 0, sizeof(check_anagram));
  memset(check_anagram_2, 0, sizeof(check_anagram_2));

  if (len != len_2) {
    printf("The words are not anagrams --- len not eq");
    printf("Len 1 %d ", len);
    printf("Len 2 %d ", len_2);
    return 1;
  }

  for (int i = 0; i < len; i++) {
    for (int k = 0; k < len_2; k++) {
      if (tolower(first_word[i]) == tolower(second_word[k]) &&
          check_anagram_2[k] != 1) {
        check_anagram[i] = 1;
        check_anagram_2[k] = 1;
        break;
      }
    }
  }

  for (int i = 0; i < len; i++) {
    if (check_anagram[i] == 0 || check_anagram_2[i] == 0) {
      printf("The words are not anagrams");
      return 1;
    }
  }
  printf("THE WORDS are ANAGRAMS : U WIN !!!");

  return 0;
}
