#include <math.h>
#include <signal.h>
#include <stdio.h>
// ex page 35
void loan_calculate(float loan_amount, int mount_count);
void cash_amount_to_pay(int cash);
int main(int argc, char* argv[])
{

    cash_amount_to_pay(93);
    loan_calculate(20000.0, 12);
    return 0;
}

void loan_calculate(float loan_amount, int mount_count)
{
    static int index = 1;
    static float mountly_payment = 0.0f;
    if (index == 1) {
        mountly_payment = loan_amount / mount_count;
        printf("--- Loan Amount : %.2f\n", loan_amount);
        printf("Payment : %.2f\n", mountly_payment);
        printf("Mounth  : %d\n", mount_count);
    }
    if (mount_count <= 0)
        return;
    float remainder_loan = loan_amount - mountly_payment;
    printf("- %d Balance Loan Remaining : %.2f\n", index, remainder_loan);
    index++;
    loan_calculate(remainder_loan, mount_count - 1);
}

void cash_amount_to_pay(int cash)
{
    static int index = 0;
    int pay_check[] = { 20, 10, 5, 1 };
    if (index >= 4 || cash < 0)
        return;
    printf("$ %d Amount is : %d \n", pay_check[index], cash / pay_check[index]);
    int remainder = cash % pay_check[index];
    index++;
    cash_amount_to_pay(remainder);
}
