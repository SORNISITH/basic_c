#include <stdio.h>
#include <stdlib.h>

void func(int key) {
  char overflowme[32];
  printf("overflow me : ");
  gets(overflowme); // smash me!

  printf("%x", key);

  if (key == 0xcafebabe) {
    system("/bin/sh");
  } else {
    printf("\nNah..\n");
  }
}
int main(int argc, char *argv[]) {
  func(0xdeadbeef);
  return 0;
}
