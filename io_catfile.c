#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

char* catfile(char* fileName);

void count_symbol(char* ch, char symbolic);
int main(int argc, char* argv[])
{
    if (argc < 2) {
        perror("File Not Found!");
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        char* text = catfile(*(argv + i));
        count_symbol(text, 'x');
        puts(text);
        free(text);
    }

    return EXIT_SUCCESS;
}

void count_symbol(char* ch, char symbolic)
{
    int sym_count = 0;
    char* ptr = ch;
    while (*ptr != '\0') {
        if (*ptr == symbolic) {
            sym_count++;
        }
        ptr++;
    }
    printf("%c : %d \n", symbolic, sym_count);
}

char* catfile(char* fileName)
{
    FILE* fp = fopen(fileName, "r");
    if (fp == NULL) {
        return NULL;
    }
    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    rewind(fp);

    char* buffer = malloc(size + 1);
    fread(buffer, 1L, size, fp);
    buffer[size] = '\0';
    fclose(fp);
    return buffer;
}
