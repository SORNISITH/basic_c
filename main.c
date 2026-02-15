#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef union f {
    float value;
    struct fl {
        unsigned int frag : 23;
        unsigned int expo : 8;
        unsigned int sign : 1;
    } fl;
} f;

int main(int argc, char* argv[])
{

    FILE* myfile;
    printf("%zu", sizeof(f));
    f newf;
    newf.fl.expo
        = 128;
    newf.fl.sign = 1;
    newf.fl.frag = 0;
    printf("%f\n", newf.value);
    newf.value = -99.2222;
    printf("%d \n", newf.fl.frag);
    printf("%d \n", newf.fl.expo);
    printf("%d \n", newf.fl.sign);
    return EXIT_SUCCESS;
}

// char x[] = "";
//
//   BYTE* p = (BYTE*)x;
//   char* ymmm = malloc(sizeof(char) * 100);
//   BYTE* ptr = (BYTE*)ymmm;
//   int index = 0;
//   while (*ptr != '\0' || index <= 100) {
//       *ptr = 'X';
//       ptr++;
//       index++;
//   }
//
//   for (size_t i = 0; i < 699999; i++) {
//       printf("%p ", p);
//       for (int k = 0; k <= 10; k++) {
//           printf(" %.2x ", *p++);
//       }
//       printf("|  ");
//       for (int k = 0; k <= 10; k++) {
//           printf(" %c ", *p++);
//       }
//       printf("\n");
//   }
//
//   printf("\n");
