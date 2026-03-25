#include <stddef.h>
#include <stdio.h>
#include <string.h>

void display_byte(const void* ptr, size_t size)
{
    unsigned char* x = (unsigned char*)ptr;
    int i = 0;
    while (x && i < size) {
        printf("%x ", *x);
        i++;
        x++;
    }
}
unsigned int replaceb(const unsigned int hex, unsigned short index, unsigned int rhex)
{
    unsigned char* x = (unsigned char*)&hex;
    *(x + index) = rhex;
    return hex;
}
int main(int argc, char* argv[])
{
    int x = 0x89ABCDEF;
    int y = 0x76543210;
    // x &= 0xFF;
    // y &= ~0xFF;
    // x += y;
    printf("%zu", sizeof(double) << 3);
    return 0;
}
