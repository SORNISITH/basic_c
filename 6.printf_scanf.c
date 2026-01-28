#include <stdio.h>
void input_output();
int main(int argc, char* argv[])
{
    input_output();
    return 0;
}

void input_output()
{
    int unit_count;

    printf("Enter Items Count : ");
    scanf("%d", &unit_count);

    float unit_price;
    printf("Enter Units prices  : ");
    scanf("%f", &unit_price);

    int day, mounth, year;
    char slash;
    printf("Enter Units Price : ");
    printf("Please Enter Date ");
    printf("(MM/DD/YYYY) : \n");
    scanf("%d%c%d%c%d", &mounth, &slash, &day, &slash, &year);

    printf("Items\tUnit\tPurchase\n");
    printf("\tPrice\tDate\n");
    printf("%d\t$%6.2f\t%d//%d//%d\n", unit_count, unit_price, mounth, day, year);
}
