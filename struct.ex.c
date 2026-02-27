#include <limits.h>
#include <stdalign.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    enum { INT_TYPE,
        DOUBLE_TYPE } type;
    union {
        int i;
        double d;
    } u;
} Number;

typedef struct {
    int red;
    int green;
    int blue;
} Color;

Color* mix_color(int red, int green, int blue)
{
    Color* mixed_c = malloc(sizeof(Color));
    if (!mixed_c)
        return NULL;
    mixed_c->red = red;
    mixed_c->green = green;
    mixed_c->blue = blue;

    return mixed_c;
}

bool cmp_color(Color* a, Color* b)
{
    if (!a || !b)
        return false;
    if (a->blue != b->blue || a->green != b->green || a->red != b->red) {
        return false;
    }
    return true;
}

void print_color(const Color* color)
{
    if (color == NULL) {
        return;
    }
    printf("[ %d,", color->red);
    printf("%d,", color->green);
    printf("%d ]", color->blue);
}

int main(int argc, char* argv[])
{
    Color* GREEN = mix_color(255, 255, 255);
    Color* RED = mix_color(255, 255, 255);

    print_color(GREEN);
    print_color(RED);

    if (cmp_color(GREEN, RED)) {
        printf("hi");
    };

    free(GREEN);
    free(RED);

    return EXIT_SUCCESS;
}

void add_number(Number* num)
{

    printf("%zu-\n", sizeof(*num));
    num->type = DOUBLE_TYPE;
    num->u.d = 3.16;
    printf("type-%d- valueue-%f", num->type, num->u.d);
}
