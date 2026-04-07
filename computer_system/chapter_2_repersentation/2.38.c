// As we will see in Chapter 3, the lea instruction can perform computations of
// the form (a<<k) + b, where k is either 0, 1, 2, or 3, and b is either 0 or some
// program value. The compiler often uses this instruction to perform multiplications
// by constant factors. For example, we can compute 3*a as (a<<1) + a.
// Considering cases where b is either 0 or equal to a, and all possible values of k,
// what multiples of a can be computed with a single lea instruction?
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned int bit_multiply(int a, int b)
{
}
