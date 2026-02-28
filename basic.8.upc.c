#include <stdio.h>
void upc_func_test1();
void upc_func_test2();
unsigned int arr_string_to_number(int arr[]);
int main(int argc, char* argv[])
{
    upc_func_test2();
    return 0;
}

void upc_func_test2()
{
    char arr_upc_input[12] = { 0 };
    printf("Enter the UPC digit : ");
    scanf("%s", arr_upc_input);
    int first_digit[2] = { 0 };
    int second_group_digit[6] = { 0 };
    int third_group_digit[6] = { 0 };
    first_digit[1] = -1;
    second_group_digit[5] = -1;
    third_group_digit[5] = -1;
    int s, t = 0;
    s = 0;
    // 0 01234 01234
    for (int i = 0; i < 12; i++) {
        if (i == 0) {
            first_digit[0] = arr_upc_input[i] - '0';
        }
        if (i > 0 && i < 6) {
            second_group_digit[s] = arr_upc_input[i] - '0';
            s++;
        }
        if (i >= 6) {
            third_group_digit[t] = arr_upc_input[i] - '0';
            t++;
        }
    }
    first_digit[1] = -1;
    second_group_digit[5] = -1;
    third_group_digit[5] = -1;

    int first_sum = first_digit[0] + second_group_digit[1] + second_group_digit[3] + third_group_digit[0] + third_group_digit[2] + third_group_digit[4];
    int second_sum = second_group_digit[0] + second_group_digit[2] + second_group_digit[4] + third_group_digit[1] + third_group_digit[3];

    int total_sum = (3 * first_sum) + second_sum;
    int check_digit = 10 - ((total_sum % 10) % 10);
    int n1 = arr_string_to_number(first_digit);
    int n2 = arr_string_to_number(second_group_digit);
    int n3 = arr_string_to_number(third_group_digit);
    printf("%d-%d-%d-%d", n1, n2, n3, check_digit);
}
unsigned int arr_string_to_number(int arr[])
{
    unsigned int number = 0;
    int index = 0;
    while (arr[index] != -1) {
        int res = arr[index];
        number = (number * 10) + res;
        index++;
    }
    return number;
}
void upc_func_test1()
{
    int total_sum, d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, first_sum, second_sum, total;
    printf("Enter the first single digit : ");
    scanf("%1d", &d);
    printf("Enter the first group digit : ");
    scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);
    printf("Enter the second group digit : ");
    scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);
    // case 1
    first_sum = d + i2 + i4 + j1 + j3 + j5;
    second_sum = i1 + i3 + i5 + j2 + j4;
    // case 2
    total_sum = d + i1 + i2 + i3 + i4 + i5 + j1 + j2 + j3 + j4 + j5;

    total = (3 * first_sum) + second_sum; // case1  or case 2
    printf("checked digit : %d \n", 9 - ((total - 1) % 10));
    printf("checked digit : %d ", 10 - ((total % 10) % 10));
}
