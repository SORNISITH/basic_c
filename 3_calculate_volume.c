#include <stdio.h>

#define PI 3.145159f

double calculate_volume(int radius);

int main(int argc, char* argv[])
{
    int radius_input;
    while (1 != 0) {
        printf("ENTER radius_input \n");
        printf("__________________\n");
        scanf("%d", &radius_input);
        float v = calculate_volume(radius_input);
        printf("%0.2f\n", v);
    }
    return 0;
}

double calculate_volume(int radius)
{
    // v = 4.0f/3.0fpir**3
    int r = radius;
    for (int i = 0; i < 3; i++) {
        r *= radius;
    }
    double v = (4.0f / 3.0f) * PI * r;
    return v;
}
