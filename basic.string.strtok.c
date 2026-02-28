#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[])
{
    char str[10] = "1,nz,99";

    char* token = strtok(str, ",");

    return EXIT_SUCCESS;
}
