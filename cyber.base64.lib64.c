#include <b64/cencode.h>
#include <stdio.h>
#include <string.h>
// gcc  -lb64  .c
int main()
{
    const char* input = "ABC";

    char output[100];

    base64_encodestate state;
    base64_init_encodestate(&state);

    int len = base64_encode_block(input, strlen(input), output, &state);
    len += base64_encode_blockend(output + len, &state);

    output[len] = '\0';

    printf("Encoded: %s\n", output);
    return 0;
}
