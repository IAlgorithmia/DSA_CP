#include <stdio.h>
int main()
{
    printf("Enter the size of the array : \n");
    int num;
    scanf("%d", &num);
    int arr[num];
    int arr1[num];
    printf("Enter the array : \n");
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }
    int count;
    int place = 0;
    int total = 0;
    for (int i = 0; i < num; i++)
    {
        count = 0;
        for (int j = i + 1; j < num; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > 0)
        {
            
            arr1[place] = arr[i];
            total++;
            place++;
        }
    }
    char arr2[total];
    for (int i = 0; i < total; i++)
    {
        arr2[i] = 2 * arr1[i];
    }
    printf("The first array : \n");
    for (int i = 0; i < total; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    for (int i = 0; i < total; i++)
    {
        printf("%d ", arr2[i]);
    }
    return 0;
}