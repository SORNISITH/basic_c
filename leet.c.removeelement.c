#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int value);
int main(int argc, char* argv[])
{

    int xs[8] = { 0, 1, 2, 2, 3, 0, 4, 2 };

    int ret_index = removeElement(xs, 8, 2);
    return EXIT_SUCCESS;
}
int removeElement(int* nums, int numsSize, int value)
{
    if (numsSize <= 0) {
        return 0;
    }
    int index = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != value) {
            nums[index] = nums[i];
            index++;
        }
    }
    return index;
}
