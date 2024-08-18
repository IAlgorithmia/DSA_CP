#include <stdio.h>
int main()
{
    // Question - An array has 1 to n elements, one of them is repeating so that the total number of elements is n + 1. We have to find the duplicate array!
    // Method 1 - 
    printf("Enter the length of the array : \n");
    int len;
    scanf("%d", &len);
    int arr[len];
    printf("Enter the elements : \n");
    for (int i = 0; i <= len - 1; i++)
    {
        scanf("%d", &arr[i]);
    }
    int check;
    for (int i = 0; i <= len - 2; i++)
    {
        for (int j = i + 1; j <= len - 1; j++)
        {
            if (arr[i] == arr[j])
            {
                printf("The duplicate element from traditional method is %d\n", arr[i]);
            }
        }
    }
    // Method 2 - 
    int arr2[len];
    for (int i = 0; i <= len - 1; i++)
    {
        arr2[i] = 0;
    }
    for (int i = 0; i <= len - 1; i++)
    {
        if (arr2[arr[i]] == 0)
        {
            arr2[arr[i]] = 1;
        }
        else
        {
            printf("The duplicate element from visited array method is %d\n", arr[i]);
        }
    }
    // Method 2 has less time complexity but more space complexity than Method 1
    // Method 3 - Lessesr time and space complexity both
    int val = ((len - 1)*(len))/2;
    int sum = 0;
    for (int i = 0; i <= len - 1; i++)
    {
        sum += arr[i];
    }
    printf("The duplicate element from mathematical method is %d", sum - val);
    return 0;
}