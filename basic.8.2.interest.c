#include <inttypes.h>
#include <stdio.h>

#define INITAIL_BALANCE 100.00f;

int main(int argc, char* argv[])
{
    int year = 0;
    float rate = 0.0f;
    printf("Enter Interest Plan : ");
    scanf("%f", &rate);
    printf("Enter Year Plan : ");
    scanf("%d", &year);

    float init_balance = INITAIL_BALANCE;
    float rate_percent[year];
    double balance[year];
    for (int i = 0; i < year; i++) {
        rate_percent[i] = 0.00f + rate + i;
        balance[i] = 100.00f;
        if (i == 0) {

            printf("\t|Years|");
        }
        printf("\t%.0f%%", rate_percent[i]);
        if (i == year - 1) {
            printf("\n");
        }
    }

    for (int i = 0; i < year; i++) {
        for (int k = 0; k < year; k++) {
            balance[k] += (rate_percent[k] / 100) * balance[k];
            if (k == 0) {
                printf("\t%2d", i + 1);
            }
            printf("\t%0.2f", balance[k]);
        }
        printf("\n");
    }

    return 0;
}

//
// int year = 0;
// float rate = 0.0f;
// float init_balance = INITAIL_BALANCE;
//
// printf("Enter Interest Plan : ");
// scanf("%f", &rate);
// printf("Enter Year Plan : ");
// scanf("%d", &year);
//
// float rate_list[year];
// float compute_interest[year];
// double balance[year];
// for (int i = 0; i < year; i++) {
//
//     if (i == 0) {
//         printf("\tYears");
//     }
//     rate_list[i] = 0.00f + rate + i;
//     compute_interest[i] = init_balance / rate_list[i];
//     balance[i] = init_balance;
//     printf("\t%.0f%%", rate_list[i]);
// }
//
// for (int i = 0; i < year; i++) {
//     printf("\n");
//     for (int k = 0; k < year; k++) {
//         if (k == 0) {
//             printf("\t%d", i + 1);
//         }
//         compute_interest[k] = balance[k] / rate_list[k];
//         balance[k] += compute_interest[k];
//
//         ;
//         printf("\t%0.2f", balance[k]);
//     }
// }
