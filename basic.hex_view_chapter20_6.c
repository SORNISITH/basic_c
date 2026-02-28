#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readFile(char* fileName);
int main(int argc, char* argv[])
{
    char* text = readFile("main.c");
    unsigned char* ptr = (unsigned char*)text;
    unsigned char* ptrc = (unsigned char*)text;
    printf("Adress \t\t\t Hex \t\t\t\t Char \n");
    printf("-----------------------------------------------------------------------------------\n");
    int len = strlen(text);
    int index = 0;
    int line = 20;
    while (index != len / line) {
        printf("- %p : ", ptr);
        for (int i = 0; i < line && *ptr != '\0'; i++) {
            printf("%2x ", *ptr);
            ptr++;
        }

        printf(" | ");
        for (int i = 0; i < line && *ptrc != '\0'; i++, ptrc++) {
            if (*ptrc == ' ') {
                printf(".");
            } else if (*ptrc == '\n') {
                printf("\\n");
            } else {
                printf("%c", *ptrc);
            }
        }
        index++;
        printf("\n");
    }
    free(text);
    return EXIT_SUCCESS;
}

char* readFile(char* fileName)
{
    FILE* fp = fopen(fileName, "rb");
    if (fp == NULL) {
        return NULL;
    }
    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    rewind(fp);
    char* fd = malloc(size + 1);
    fread(fd, 1, size, fp);
    fd[size] = '\0';
    return fd;
}
