#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void encrypt(char* word, char key);
inline char xor (char ch, char key);
void decrypt(char* word, char key);

void bruce_force(char* word);
int main(int argc, char* argv[])
{
    char word[] = "Trust not him with your secrets , who , when lect alone in your room , turn over you papers --jonhann kaspar lavater ";
    puts(word);
    encrypt(word, '/');
    puts(word);
    bruce_force(word);

    puts(word);
    return EXIT_SUCCESS;
}

void bruce_force(char* word)
{
    int total_char = 177;
    for (int i = 0; i <= 177; i++) {
        char* p = word;
        printf("Testing : %c : ", i);
        while (*p != '\0') {
            if (*p != ' ') {
                printf("%c", xor(*p, i));
            }
            p++;
        }
        printf("\n");
    }
}

void decrypt(char* word, char key)
{
    char* begin_ptr = word;
    while (*begin_ptr != '\0') {
        if (*begin_ptr != ' ') {
            *begin_ptr = xor(*begin_ptr, key);
        }
        begin_ptr++;
    }
}

void encrypt(char* word, char key)
{
    char* begin_ptr = word;
    while (*begin_ptr != '\0') {
        if (*begin_ptr != ' ') {
            *begin_ptr = xor(*begin_ptr, key);
        }
        begin_ptr++;
    }
}
inline char
    xor (char ch, char key) {
            return key ^ ch;
        }
