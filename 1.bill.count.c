#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

void count_usd(const int total, int* tw, int* ten, int* five, int* one);
int main(int argc, char* argv[])
{
    int twen_usd, ten_usd, five_usd, one_usd;
    int total_usd = 11701;
    count_usd(total_usd, &total_usd, &ten_usd, &five_usd, &one_usd);
    return EXIT_SUCCESS;
}

void count_usd(const int total, int* tw, int* ten, int* five, int* one)
{
    *tw = 0;
    *ten = 0;
    *five = 0;
    *one = 0;
    int sub_total = total;
    const int bill[4] = { 20, 10, 5, 1 };
    int bill_count[4] = { 0 };
    for (int i = 0; i < 4; i++) {
        bill_count[i] = sub_total / bill[i];
        sub_total %= bill[i];
    }
    *tw = bill_count[0];
    *ten = bill_count[1];
    *five = bill_count[2];
    *one = bill_count[3];

    printf("20 $ : %d\n", *tw);
    printf("10 $ : %d\n", *ten);
    printf("5 $ : %d\n", *five);
    printf("1 $ : %d\n", *one);
}
