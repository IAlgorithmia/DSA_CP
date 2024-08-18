#include <stdio.h>
#define LOWER_BOUND -10
#define UPPER_BOUND 10
#define ARRAY_SIZE (UPPER_BOUND - LOWER_BOUND + 1)
int a[ARRAY_SIZE]; // Declare an array with the desired bounds
// Calculate the base address of the array
int main()
{
    int *base = &a[0] - LOWER_BOUND;
    // Now we can access elements using the desired subscripts
    *(base - 10) = 1;
    *(base - 9) = 2;
    *(base - 8) = 3;
    // ...
    *(base + 10) = 21;
}