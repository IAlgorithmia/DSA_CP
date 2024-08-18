#include <stdio.h>
int func(int array[]){
    for (int i = 0; i <= 4; i++){
        printf("The value of element %d is %d\n", i+1,array[i]);
        //Alternative
        //printf("The value of element %d is %d\n", i+1,*(array+i));
    }
    array[0] = 5678; 
    // If you change any value here, it'll be reflected in the main() function
}
int func2(int *ptr){
    for (int i = 0; i <= 4; i++){
        printf("The value of element %d is %d\n", i+1,ptr[i]);
        //Alternative : 
        // printf("The value of element %d is %d\n", i+1,*(ptr + i));
        ptr[0] = 66;

    }
}
int main()
{
    int arr[] = {5,1,4,2,3};
    printf("The value at index 0 is %d\n", arr[0]);
    func(arr);
    printf("The value at index 0 is %d\n", arr[0]);
    func2(arr);
    printf("The value at index 0 is %d\n", arr[0]);
    return 0;
}