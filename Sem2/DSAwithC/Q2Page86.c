#include <stdio.h>
#define ROW_LOWER_BOUND -10
#define ROW_UPPER_BOUND 10
#define COL_LOWER_BOUND -10
#define COL_UPPER_BOUND 10
#define ROW_SIZE (ROW_UPPER_BOUND - ROW_LOWER_BOUND + 1)
#define COL_SIZE (COL_UPPER_BOUND - COL_LOWER_BOUND + 1)

int a[ROW_SIZE][COL_SIZE]; // Declare a 2D array with the desired bounds
int main()
{
    // Calculate the base address of the array
    int *base = &a[0][0] - ROW_LOWER_BOUND * COL_SIZE - COL_LOWER_BOUND;
    //Basically matrix ke middle mein pahunchana hai
    // Now we can access elements using the desired subscripts
    base[-10 * COL_SIZE - 10] = 1;
    base[-10 * COL_SIZE - 9] = 2;
    base[-10 * COL_SIZE - 8] = 3;
    // ...
    base[10 * COL_SIZE + 10] = 441;
}