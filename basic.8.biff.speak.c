#include <ctype.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
  char message[256];
  printf("Enter MSG : ");
  fgets(message, sizeof(message), stdin);
  int index = 0;
  while (message[index] != '\n') {
    message[index] = toupper(message[index]);
    message[index] = message[index] == 'A'   ? '4'
                     : message[index] == 'B' ? '8'
                     : message[index] == 'E' ? '3'
                     : message[index] == 'I' ? '1'
                     : message[index] == 'O' ? '0'
                     : message[index] == 'S' ? '5'
                                             : message[index];
    index++;
  }
  for (int i = 0; i < 5; i++) {
    message[index] = '!';
    index++;
  }
  printf("B1FF-Speak : %s", message);
  return 0;
}
