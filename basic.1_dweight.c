#include <stdio.h>
#define INCH_PER_POUND 166
int main(void)
{
    int h, len, w, vol, weight = 0;
    printf("> Enter Height of Box \t: ");
    scanf("%d", &h);
    printf("> Enter Width of Box \t: ");
    scanf("%d", &w);
    printf("> Enter Lenght of Box \t: ");
    scanf("%d", &len);
    vol = h * w * len;
    weight = (vol + INCH_PER_POUND - 1) / INCH_PER_POUND;
    printf("Dimentions \t: %dx%dx%d \n", h, w, len);
    printf("Volume (cubic inchces)  \t: %d \n", vol);
    printf("Dimensional weight (pound)  \t: %d \n", weight);
    return 0;
}
