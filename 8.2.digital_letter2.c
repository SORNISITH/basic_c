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
// #define H0 " ---- "
// #define H3 " ---- "
// #define H6 " ---- "
// #define V1 "    |"
// #define V2 "    |"
// #define V4 "|"
// #define V5 "|"
// ▰▰▰▰
// ≈≈≈≈
// ◆◆◆◆
//
// #define H0 " ━━━━ "
// #define H3 " ━━━━ "
// #define H6 " ━━━━ "

#define H0 " ▰▰▰▰ "
#define H3 " ▰▰▰▰ "
#define H6 " ▰▰▰▰ "
#define V1 "    ┃"
#define V2 "    ┃"
#define V4 "┃"
#define V5 "┃"

void print_arr(int a[], int size);
void number_to_digital(int number);
void convert_number_todigital(int len, int number_to_print[len]);
void print_V(const int num[7], int step);
void print_H(const int num[7], int step);
int main(int argc, char* argv[])
{
    while (1) {
        printf("Enter Number : ");
        int x;
        scanf("%d", &x);
        number_to_digital(x);
    }

    return 0;
}

void number_to_digital(int number)
{
    // process number
    char number_str_arr[32];
    sprintf(number_str_arr, "%d", number);
    int equal_index[32];
    int len_arr = strlen(number_str_arr);
    for (int i = 0; number_str_arr[i] != '\0'; i++) {
        if (number_str_arr[i] != '-' || number_str_arr[i] != '/') {

            equal_index[i] = number_str_arr[i] - '0';
        }
    }
    convert_number_todigital(len_arr, equal_index);
}

void convert_number_todigital(int len, int number_to_print[len])
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
    int l = 0;
    for (int k = 0; k < len; k++) {
        print_H(segment[number_to_print[k]], 0);
        printf("\t");
    }
    printf("\n");
    for (int k = 0; k < len; k++) {
        print_V(segment[number_to_print[k]], 5);
        print_V(segment[number_to_print[k]], 1);
        printf("\t");
    }
    printf("\n");
    for (int k = 0; k < len; k++) {
        print_H(segment[number_to_print[k]], 6);
        printf("\t");
    }
    printf("\n");
    for (int k = 0; k < len; k++) {
        print_V(segment[number_to_print[k]], 4);
        print_V(segment[number_to_print[k]], 2);
        printf("\t");
    }
    printf("\n");
    for (int k = 0; k < len; k++) {
        print_H(segment[number_to_print[k]], 3);
        printf("\t");
    }

    printf("\n");
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

void print_arr(int a[], int size)
{
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            printf(" %d ", a[i]);
        } else {
            printf(", %d ", a[i]);
        }
    }
    printf("\n");
}
