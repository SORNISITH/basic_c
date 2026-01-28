#include <ctype.h>
#include <stdio.h>
void conver_clock_to();
void digit_12_to_24_clock();
void count_digit();
int main(int argc, char* argv[])
{
    digit_12_to_24_clock();
    return 0;
}

void digit_12_to_24_clock()
{
    char clock[32] = { 0 };
    char remove_white_clock[32] = { 0 };
    char hour[3], minute[3], dm[3];
    printf("Enter 12h Time : ");
    scanf("%s", clock);

    for (int i = 0, k = 0; clock[i] != '\0'; i++) {
        if (clock[i] != ' ') {
            remove_white_clock[k] = toupper(clock[i]);
            if (remove_white_clock[k] != ':' || remove_white_clock[k] != '\n' || remove_white_clock[k] != '/') {
            }
            k++;
        }
    }

    printf("%s\n", clock);
    printf("%s", remove_white_clock);
}

// void conver_clock_to()
// {
//     int h, m, hh;
//     char slash;
//     char dm;
//     printf("Enter 24h/12h time : ");
//     char pm[16] = { ' ' }, rm_space_pm[16];
//     scanf("%d%c%d%s", &h, &slash, &m, pm);
//
//     for (int i = 0, k = 0; pm[i] != '\0'; i++) {
//         if (pm[i] != ' ' || pm[i] != '\n' || pm[i] != '\t') {
//             rm_space_pm[k] = toupper(pm[i]);
//             k++;
//         }
//     }
//     printf("%s\n", pm);
//     printf("%s\n", rm_space_pm);
//     if (h >= 1 && h <= 12 && (rm_space_pm[0] == 'P' || rm_space_pm[0] == 'A')) {
//         if (pm[0] == 'P') {
//             h = (h = 1) ? 13 : (h == 2) ? 14
//                 : (h == 3)              ? 15
//                 : (h == 4)              ? 16
//                 : (h == 5)              ? 17
//                 : (h == 6)              ? 18
//                 : (h == 7)              ? 19
//                 : (h == 8)              ? 20
//                 : (h == 9)              ? 21
//                 : (h == 10)             ? 22
//                 : (h == 11)             ? 23
//                 : (h == 12)             ? 00
//                                         : ' ';
//         }
//         printf("Equivalent 24-h time : %02d%c%02d \n", hh, slash, m);
//     } else if (h >= 1 && h <= 24 && (rm_space_pm[0] != 'P' || rm_space_pm[0] != 'A')) {
//         if (h == 13)
//             h = 1;
//         if (h == 14)
//             h = 2;
//         if (h == 15)
//             h = 3;
//         if (h == 16)
//             h = 4;
//         if (h == 17)
//             h = 5;
//         if (h == 18)
//             h = 6;
//         if (h == 19)
//             h = 7;
//         if (h == 20)
//             h = 8;
//         if (h == 21)
//             h = 9;
//         if (h == 22)
//             h = 10;
//         if (h == 23)
//             h = 11;
//         if (h == 24)
//             h = 00;
//         dm = (h >= 1 && h <= 12) ? 'A' : 'P';
//         printf("Equivalent 12-h time : %2d%c%02d %cM\n", h, slash, m, dm);
//     } else {
//         printf("Invalid Time Format  either 24 nor 12h");
//     }
// }

void count_digit()
{
    int input = 0;
    printf("Enter an Number : ");
    scanf("%d", &input);
    if (input == -1)
        return;
    if (input >= 0 && input <= 9) {
        printf("1 digit\n");
    }
    if (input >= 10 && input <= 99) {
        printf("2 digit\n");
    }
    if (input >= 100 && input <= 999) {
        printf("3 digit\n");
    }
    if (input >= 1000 && input <= 9999) {
        printf("4 digit\n");
    }
    if (input >= 10000 && input <= 99999) {
        printf("5 digit\n");
    }
    count_digit();
}
