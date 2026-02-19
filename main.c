#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value_;
    struct Node* next_;
};

union myu {
    int input;
    struct {
        unsigned char b1;
        unsigned char b2;
        unsigned char b3;
        unsigned char b4;
    } br;
};

// struct Node* ret_new_node(int value);
//
// void push_node(struct Node* (*make_node)(int), int value, struct Node* Head)
// {
//     struct Node* new_node = make_node(value);
// }

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
    union myu* thisis = malloc(sizeof(*thisis));
    thisis->input = 0xAABBCCDD;
    printf("%#x\n", thisis->input);
    printf("%#x\n", thisis->br.b1);
    printf("%#x\n", thisis->br.b2);
    printf("%#x\n", thisis->br.b3);
    printf("%#x\n", thisis->br.b4);
    return EXIT_SUCCESS;
}
