#include <stdio.h>
void simplemerger(int arr1[], int arr2[], int len1, int len2, int ansarr[])
{
    int a = 0, b = 0, c = 0;
    while (a < len1 && b < len2)
    {
        if (arr1[a] < arr2[b])
        {
            ansarr[c] = arr1[a];
            c++; a++;
        }
        else
        {
            ansarr[c] = arr2[b];
            c++; b++;
        }
    }
    while (a < len1)
    {
        ansarr[c] = arr1[a];
        a++; c++;
    }
    while (b < len2)
    {
        ansarr[c] = arr2[b];
        b++; c++;
    }
}
int main()
{
    printf("Enter the length of the sorted array 1 : \n");
    int len1;
    scanf("%d", &len1);
    int i;
    int arr1[len1];
    printf("Enter the elements of the sorted array 1 : \n");
    for (i = 0; i < len1; i++)
    {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the length of the sorted array 2 : \n");
    int len2;
    scanf("%d", &len2);
    int arr2[len2];
    printf("Enter the elements of the sorted array 2 : \n");
    for (i = 0; i < len2; i++)
    {
        scanf("%d", &arr2[i]);
    }
    int ansarr[len1 + len2];
    simplemerger(arr1, arr2, len1, len2, ansarr);
    printf("The combined sorted array is : \n");
    for (i = 0; i < len1 + len2; i++)
    {
        printf("%d ", ansarr[i]);
    }
    return 0;
}