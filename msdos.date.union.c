#include <stdio.h>
#include <stdlib.h>
typedef union f {
    float value;
    struct fl {
        unsigned int frag : 23;
        unsigned int expo : 8;
        unsigned int sign : 1;
    } fl;
} f;

typedef struct Date {
    unsigned int day : 5;
    unsigned int month : 4;
    unsigned int year : 16;
} Date;

typedef struct Time {
    unsigned int : 5;
    unsigned int minutes : 6;
    unsigned int hours : 5;
} Time;

typedef union u_date {
    unsigned short i;
    Date date;
} u_date;

void printd(unsigned short i)
{
    u_date mydate;
    mydate.i = i;
    printf("%d - %d - %d \n", mydate.date.day, mydate.date.month, mydate.date.year + 2020);
}

short c_date(int day, int mount, int year)
{
    u_date mydate;
    mydate.date.day = day;
    mydate.date.month = mount;
    mydate.date.year = year - 2020;

    return mydate.i;
}

int main(int argc, char* argv[])
{
    short int inputd = c_date(14, 12, 2026);
    printd(inputd);
    printf("%d", inputd);
    return EXIT_SUCCESS;
}
