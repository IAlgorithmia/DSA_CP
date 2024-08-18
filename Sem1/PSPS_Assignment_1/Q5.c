#include <stdio.h>
int main()
{
    int num;
    printf("Enter the desired length of the array : \n");
    scanf("%d", &num);
    int arr[num];
    for (int i = 0; i <= num - 1; i++)
    {
        printf("Enter the number : \n");
        scanf("%d", &arr[i]);
    }
    int check = 0;
    for (int i = 0; i <= num - 1; i++)
    {
        for (int j = 0; j <= num - 1; j++)
        {
            if ((arr[i] - arr[j]) < 0)
            {
                check++;
            }
        }
        if (check == num - 1)
        {
            printf("%d is the smallest element of the array\n", arr[i]);
        }
        check = 0;
    }
    return 0;
}