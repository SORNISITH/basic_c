#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cmd(char* f)
{
    system("clear");
    system(f);
}
int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
    char f2[] = "gcc -std=c23 -Wall -Wvla -Wextra -ggdb ";
    char adv[] = " -ftime-report  -fsanitize=address ";
    char fileName[] = " main.c && a.out ";
    char rr[] = " && a.out ";
    if (argc <= 1) {
        char normalBuild[256] = " ";
        printf("[INFO] Normal build main.c \n");
        strcat(normalBuild, f2);
        strcat(normalBuild, fileName);
        cmd(normalBuild);
        exit(0);
    } else if (argc == 2) {
        char nameBuild[256] = " ";
        printf("[INFO] param no flag build by NZ! %s\n", argv[1]);
        strcat(nameBuild, f2);
        strcat(nameBuild, argv[1]);
        strcat(nameBuild, rr);
        cmd(nameBuild);
    } else if (argc >= 3) {
        char mBuild[256] = " ";
        printf("[INFO] param no flag build by NZ! \n");
        strcat(mBuild, f2);
        strcat(mBuild, adv);
        strcat(mBuild, argv[2]);
        strcat(mBuild, rr);
        cmd(mBuild);
        exit(0);
    }
    return EXIT_SUCCESS;
}
