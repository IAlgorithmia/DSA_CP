#include <stdio.h>
void swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
int main()
{
    printf("Enter the size of the array : ");
    int num;
    scanf("%d", &num);
    int arr[num];
    printf("Enter the array : \n");
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
    for (int i = 0; i < num; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nEnter the rank of your choice : \n");
    int rank;
    scanf("%d", &rank);
    printf("The rank %d largest element is %d and the rank %d smallest element is %d", rank, arr[rank - 1], rank, arr[num - rank]);
    return 0;
}