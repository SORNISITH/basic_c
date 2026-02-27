#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* decrypted_text(char* s, int key);
char* encrypted_text(char* s, int key);
int main(int argc, char* argv[])
{
    char buf[80];
    printf("Enter MSG to be encrypted : ");
    fgets(buf, sizeof(buf), stdin);
    char* encrypted_text_valueue = encrypted_text(buf, 3);

    char* x = "bDNhcm5fdGgzX3IwcDM1";

    for (int i = 0; i <= 26; i++) {

        char* decrypted_text_valueue = decrypted_text(x, i);
        printf("%s\n", decrypted_text_valueue);
    }
    printf("%s\n", encrypted_text_valueue);
    return 0;
}

char* encrypted_text(char* s, int key)
{
    int len = strlen(s);
    char* ptr = malloc(len + 1);

    for (int i = 0; s[i] != '\0'; i++) {
        if (isupper(s[i])) {
            ptr[i] = (s[i] - 'A' + key) % 26 + 'A';
        } else if (islower(s[i])) {
            ptr[i] = (s[i] - 'a' + key) % 26 + 'a';
        } else {
            ptr[i] = s[i];
        }
    }
    ptr[len] = '\0'; // NULL TERMINATOR

    return ptr;
}

char* decrypted_text(char* s, int key)
{
    int len = strlen(s);
    char* ptr = malloc(len + 1);

    for (int i = 0; s[i] != '\0'; i++) {
        if (isupper(s[i])) {
            ptr[i] = (s[i] - 'A' - key + 26) % 26 + 'A';
        } else if (islower(s[i])) {
            ptr[i] = (s[i] - 'a' - key + 26) % 26 + 'a';
        } else {
            ptr[i] = s[i];
        }
    }
    ptr[len] = '\0'; // NULL TERMINATOR

    return ptr;
}
