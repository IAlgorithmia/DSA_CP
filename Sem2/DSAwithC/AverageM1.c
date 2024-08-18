#include <stdio.h>
#include <stdlib.h>
float average(int ptr[], int len)
{
    float sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += (float)ptr[i];
    }
    return (sum / len);
}
int main()
{
    printf("Enter the number of elements whose average you want to find : ");
    int n;
    scanf("%d", &n);
    int* ptr;
    ptr = (int*)malloc(n*sizeof(int));
    printf("Enter the elements : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }
    float avg = average(ptr, n);
    printf("The average is %.2f", avg);
    return 0;
}