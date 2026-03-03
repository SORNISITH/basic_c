#include <stdio.h>

// this my thinking and wrong many time
// int euclid_gcd(int u, int v)
// {
//     if (u < v) {
//         u ^= v;
//         v ^= u;
//         u ^= v;
//     } // swwwup make sure u > v
//     int temp;
//     while ((temp = u % v) > 0) {
//         u = v;
//         v = temp;
//     }
//     return v;
// }
//
// int subarrayGCD(int* nums, int numsSize, int k)
// {
//     int ret = 0;
//     for (int i = 0; i < numsSize; ++i) {
//         for (int j = i; j < numsSize; ++j) {
//             int gcd = 0;
//
//             for (int x = i; x <= j; ++x) {
//                 if (gcd == 0) {
//                     gcd = nums[x];
//                 } else {
//                     gcd = euclid_gcd(gcd, nums[x]);
//                     if ((gcd != k && nums[x] == k ) || ( nums[x] < k )  ) {
//                         break;
//                     }
//                 }
//             }
//
//             if (gcd == k) {
//                 ++ret;
//             }
//         }
//     }
//     return ret;
// }
//

int euclid_gcd(int u, int v)
{
    while (v != 0) {
        int temp = v;
        v = u % v;
        u = temp;
    }
    return u;
}
int subarrayGCD(int* nums, int numsSize, int k)
{
    int ret = 0;
    for (int i = 0; i < numsSize; ++i) {
        int current_gcd = nums[i];
        for (int j = i; j < numsSize; ++j) {
            current_gcd = euclid_gcd(current_gcd, nums[j]);
            if (current_gcd == k) {
                ++ret;
            } else if (current_gcd % k != 0) {
                break;
            }
        }
    }
    return ret;
}

int main()
{
    int n[4] = { 3, 12, 9, 6 };
    int n1[5] = { 3, 3, 4, 1, 2 };
    int n2[3] = { 3, 3, 3 };
    int x = subarrayGCD(n2, 3, 3);
    printf("\n%d", x);

    return 0;
}
