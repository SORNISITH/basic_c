#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef union f {
    float value;
    struct fl {
        unsigned int frag : 23;
        unsigned int expo : 8;
        unsigned int sign : 1;
    } fl;
} f;
typedef struct bitptr {

    unsigned char p : 1;
} bitptr;

int main(int argc, char* argv[])
{
    FILE *s_dest, *s_ori;
    s_dest = fopen("./newcpy.c", "wb");
    s_ori = fopen("./main.c", "rb");

    if (s_dest == NULL || s_ori == NULL) {
        perror("error");
        return EXIT_FAILURE;
    }
    printf("%d", FILENAME_MAX);
    fseek(s_ori, 0, SEEK_END);
    int size = ftell(s_ori);
    rewind(s_ori);

    char* tmp = malloc(size + 1);
    tmp[size] = '\0';

    fread(tmp, 1L, size, s_ori);

    rewind(s_ori);
    int ch;
    while ((ch = fgetc(s_ori)) != '\0') {
        printf("%c-\n", ch);
    }

    printf("%s", tmp);
    fwrite(tmp, 1L, size - 1, s_dest);

    free(tmp);

    fclose(s_dest);
    fclose(s_ori);
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
