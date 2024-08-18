#include <stdio.h>
#include <stdlib.h>

// Recursive function to compute power set
void powerSet(int set[], int n, int index, int subset[])
{
    // If we have processed all elements of the set
    if (index == n)
    {
        // Print the current subset
        printf("{ ");
        for (int i = 0; i < n; i++)
        {
            if (subset[i] == 1)
            {
                printf("%d ", set[i]);
            }
        }
        printf("}\n");
        return;
    }

    // Generate all subsets that include set[index]
    subset[index] = 1;
    powerSet(set, n, index + 1, subset);

    // Generate all subsets that do not include set[index]
    subset[index] = 0;
    powerSet(set, n, index + 1, subset);
}

// Driver code
int main()
{
    int set[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(set) / sizeof(set[0]);
    int *subset = (int *)malloc(n * sizeof(int));

    powerSet(set, n, 0, subset);

    free(subset);

    return 0;
}
