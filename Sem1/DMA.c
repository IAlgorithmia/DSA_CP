#include <stdio.h>
#include <stdlib.h>
int main()
{
    /*
    //Use of malloc
    int *ptr;
    int size;
    printf("Enter the size of the array you want : \n");
    scanf("%d", &size);
    ptr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i <= size - 1; i++)
    {
        printf("Enter the value %d of the array\n", i+1);
        scanf("%d", ptr + i);
    }
    for (int i = 0; i <= size - 1; i++)
    {
        printf("The value at %d of the array is %d\n", i+1, *(ptr + i));
    }
    */
    //Use of calloc
    int *ptr;
    int size;
    printf("Enter the size of the array you want : \n");
    scanf("%d", &size);
    ptr = (int *) calloc(size, sizeof(int));
    for (int i = 0; i <= size - 1; i++)
    {
        printf("Enter the value %d of the array\n", i+1);
        scanf("%d", ptr + i);
    } //If this input isn't taken, all the values will be printed as 0 below
    for (int i = 0; i <= size - 1; i++)
    {
        printf("The value at %d of the array is %d\n", i+1, *(ptr + i));
    }
    
    //Use of realloc
    int newsize;
    printf("Enter the new size of the array you want : \n");
    scanf("%d", &newsize);
    ptr = (int *) realloc(ptr, sizeof(int));
    for (int i = 0; i <= newsize - 2; i++)
    {
        printf("Enter the value %d of the array\n", i+1);
        scanf("%d", ptr + i);
    } //If this input isn't taken, all the values will be printed as 0 below
    free(ptr);
    for (int i = 0; i <= newsize - 1; i++)
    {
        printf("The value at %d of the array is %d\n", i+1, *(ptr + i));
    }
    return 0;
}