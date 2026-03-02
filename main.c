#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
int main()
{

    int x[100][100] = { 0 };

    int (*start)[100];
    int (*end)[100];

    ptrdiff_t test;
    int* p_start;
    int* p_end;

    for (p_start = &x[0][0], p_end = &x[99][99]; p_start <= p_end; p_start++) {
        test = p_end - p_start;
        printf(" %td -> %d ", test, *p_start);
    }

    return 0;
}
