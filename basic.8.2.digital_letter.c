#include <setjmp.h>
#include <stdatomic.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define H0F "      "
#define H3F "      "
#define H6F "      "
#define V1F "     "
#define V2F "     "
#define V5F " "
#define V4F " "

#define H0 " ---- "
#define H3 " ---- "
#define H6 " ---- "
#define V1 "    |"
#define V2 "    |"
#define V4 "|"
#define V5 "|"

void print_V(const int num[7], int step);
void print_H(const int num[7], int step);
int main(int argc, char* argv[])
{
    const int segment[10][7] = {
        { 1, 1, 1, 1, 1, 1, 0 },
        { [1] = 1, [2] = 1 },
        { 1, 1, 0, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 0, 0, 1 },
        { 0, 1, 1, 0, 0, 1, 1 },
        { 1, 0, 1, 1, 0, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 0, 0, 0 },
        { 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 0, 1, 1 }
    };
    size_t row_len = sizeof(segment[0]) / sizeof(segment[0][0]);
    size_t col_len = 7;

    // ("   0 ");
    // ("  --- ");
    // ("5|   |1");
    // (" |-6-| ");
    // ("4|   |2");
    // ("  --- ");
    // ("   3 ");
    //
    //
    for (int k = 0; k < col_len; k++) {
        print_H(segment[k], 0);
        printf("\t");
    }
    printf("\n");
    for (int k = 0; k < col_len; k++) {
        print_V(segment[k], 5);
        print_V(segment[k], 1);
        printf("\t");
    }
    printf("\n");
    for (int k = 0; k < col_len; k++) {
        print_H(segment[k], 6);

        printf("\t");
    }
    printf("\n");
    for (int k = 0; k < col_len; k++) {
        print_V(segment[k], 4);
        print_V(segment[k], 2);
        printf("\t");
    }
    printf("\n");
    for (int k = 0; k < col_len; k++) {
        print_H(segment[k], 3);
        printf("\t");
    }

    // for (int i = 0; i < 5; i++) {
    //     printf("\n");
    //     print_H(segment[i], 0);
    //     printf("\n");
    //     print_V(segment[i], 5);
    //     print_V(segment[i], 1);
    //     printf("\n");
    //     print_H(segment[i], 6);
    //     printf("\n");
    //     print_V(segment[i], 4);
    //     print_V(segment[i], 2);
    //     printf("\n");
    //     print_H(segment[i], 3);
    // }

    return 0;
}

void print_H(const int num[7], int step)
{
    if (step == 0) {
        if (num[step] == 1) {
            printf("%s", H0);
        } else {
            printf("%s", H0F);
        }
    } else if (step == 6) {
        if (num[step] == 1) {
            printf("%s", H6);
        } else {
            printf("%s", H6F);
        }
    } else if (step == 3) {
        if (num[step] == 1) {
            printf("%s", H3);
        } else {
            printf("%s", H3F);
        }
    }
}

void print_V(const int num[7], int step)
{
    int cmp_step = num[step];
    if (step == 5) {
        if (cmp_step == 1) {
            printf("%s", V5);
        } else {
            printf("%s", V5F);
        }
    } else if (step == 1) {
        if (cmp_step == 1) {
            printf("%s", V1);
        } else {
            printf("%s", V1F);
        }
    } else if (step == 4) {
        if (cmp_step == 1) {
            printf("%s", V4);
        } else {
            printf("%s", V4F);
        }
    } else if (step == 2) {
        if (cmp_step == 1) {
            printf("%s", V2);
        } else {
            printf("%s", V2F);
        }
    }
}
