#include "stdio.h"

void to_lower(char* s);
void to_upper(char* s);
int main()
{
    char x[] = "AAAAxXXyyyasddddddDDDD";
    to_lower(x);
    to_upper(x);
    return 0;
}
void to_lower(char* s)
{
    int i = 0;
    while (s[i] != '\0') {
        s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? (s[i] | 0x20) : s[i];
        i++;
    }
    printf("%s", s);
}
void to_upper(char* s)
{
    int i = 0;
    while (s[i] != '\0') {
        s[i] = (s[i] >= 'a' && s[i] <= 'z') ? (s[i] & ~0x20) : s[i];
        i++;
    }
    printf("%s", s);
}
