#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* reverse(char* stx);

typedef struct String {
    int len;
    char chars[];
} String;

String* mk_chars(char* word)
{
    char* restrict w = word;
    int n = strlen(word);
    String* new_chars = malloc(sizeof(String) + n + 1);
    new_chars->len = n;
    int i = 0;
    while (*w != '\0') {
        new_chars->chars[i] = *w;
        w++;
        i++;
    }
    new_chars->chars[i] = '\0';
    return new_chars;
}

int main(int argc, char* argv[])
{

    String* myword = mk_chars("helloworld");

    puts(myword->chars);
    free(myword);
    return EXIT_SUCCESS;
}

char* reverse(char* restrict str)
{
    int len = strlen(str);
    char *h, *t;
    h = str;
    t = str + len - 1;

    while (h != t) {
        char temp;
        temp = *h;
        *h = *t;
        *t = temp;
        h++;
        t--;
    }

    return str;
}
