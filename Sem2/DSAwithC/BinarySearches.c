#include <stdio.h>
void sorter(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] < array[j])
            {
                array[i] = array[i] + array[j];
                array[j] = array[i] - array[j];
                array[i] = array[i] - array[j];
            }
        }
    }
}
int linearsearch(int array[], int size, int elem)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == elem)
        {
            return i;
        }
    }
    return -1;
}
int iterativebinarysearch(int array[], int size, int elem)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    for (int i = 0; low <= high; i++)
    {
        mid = (low + high) / 2;
        if (array[mid] == elem)
        {
            return mid;
        }
        else if (array[mid] < elem)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int recursivebinarysearch(int array[], int elem, int low, int high)
{
    if (low > high)
    {
        return -1;
    }
    else
    {
        int mid = (low + high) / 2;
        if (array[mid] == elem)
        {
            return mid;
        }
        else if (array[mid] < elem)
        {
            recursivebinarysearch(array, elem, mid + 1, high);
        }
        else
        {
            recursivebinarysearch(array, elem, low, mid - 1);
        }
    }
}
int main()
{
    printf("Enter the number of elements you want to add : \n");
    int len;
    scanf("%d", &len);
    int arr[len];
    printf("Enter the array : \n");
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element you want to search in it : \n");
    int num;
    scanf("%d", &num);
    int index1 = linearsearch(arr, len, num);
    sorter(arr, len);
    printf("The sorted array is : \n");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    int index2 = iterativebinarysearch(arr, len, num);
    int index3 = recursivebinarysearch(arr, num, 0, len - 1);
    printf("The element was found at %d by linearsearch\n", index1);
    printf("The element was found at %d by iterative binarysearch\n", index2);
    printf("The element was found at %d by recursive linearsearch", index3);
    return 0;
}