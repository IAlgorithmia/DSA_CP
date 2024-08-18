#include <stdio.h>
int main()
{

    // Sizeof is not a function, it's an operator
    printf("%d %d\n\n", sizeof(int), sizeof(char));
    int a = 5;
    int *ptra = &a;
    printf("%d\n\n", ptra);
    ptra++;
    printf("%d\n\n", ptra + 1); 
    // 4 bytes added since the size of int is 4 bytes
    char b = 'g';
    char *ptrb = &b;
    printf("%d\n\n", ptrb);
    ptrb++;
    printf("%d\n\n", ptrb + 1);                      
    // 1 byte added since the size of char is 1 byte
    printf("%d %d\n\n", sizeof(ptra), sizeof(ptrb)); 
    // Size of pointers
    int arr[3];
    arr[0] = 542;
    arr[1] = 420;
    arr[2] = 69;
    int *ptrarr = arr; 
    // We can also write &arr in place of arr, since both will be treated as addresses pointing to a[0]
    printf("%d and %d\n\n", ptrarr, arr); 
    // Arr is itself a pointer, pointing to the location of arr[0]
    printf("%d and %d\n\n", *ptrarr, *arr);
    printf("We get the same values, %d and %d\n\n", arr[1], *(arr + 1)); 
    // *(arr + 1) => 4 bytes added to location of arr added so naturally arr[0] + 4 => arr[1] will be printed
    // 4 bytes because the data type of the array is int. Were it char, 1 byte shall be added by the next element would've 
    // been printed again
    printf("The address of the first element of the array is %d\n\n", &arr[0]);
    printf("The address of the first element of the array is %d\n\n", arr);
    printf("The address of the second element of the array is %d\n\n", &arr[1]);
    printf("The address of the second element of the array is %d\n\n", arr + 1);
    printf("The address of the third element of the array is %d\n\n", &arr[2]);
    printf("The address of the third element of the array is %d\n\n", arr + 2);
    printf("The value at address of the first element of the array is %d\n\n", *(&arr[0]));
    printf("The value at address of the first element of the array is %d\n\n", *(arr));
    printf("The value at address of the second element of the array is %d\n\n", *(&arr[1]));
    printf("The value at address of the second element of the array is %d\n\n", *(arr + 1));
    printf("The value at address of the second element of the array is %d\n\n", *(&arr[2]));
    printf("The value at address of the second element of the array is %d\n\n", *(arr + 2));
    // Lastly, arr++ will throw an error since it's a constant, refering to locatin of arr[0], but :
    int *arrptr = arr;
    printf("%d\n\n", arrptr);
    arrptr++;
    printf("%d", arrptr);
    return 0;
}