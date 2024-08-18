#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int index, int n)
{
    while (index <= (n / 2)) // Loop should continue untill index reaches a leaf node, after that it should stop
    {
        int left, right, maxindex;
        left = 2 * index;
        right = (2 * index) + 1;
        maxindex = index; // Assuming the root is larger than its children
        if (arr[left] > arr[maxindex])
        {
            maxindex = left;
        }
        if ((right <= n) && (arr[right] > arr[maxindex]))
        {
            maxindex = right;
        }
        if (maxindex == index)
        {
            break;
        }
        else
        {
            swap(&arr[maxindex], &arr[index]);
            index = maxindex; // For continuing the loop with the new index
        }
    }
}

void heapsort(int arr[], int n)
{
    // n is the total number of elements minus 1, i.e. the last index
    // STEP 1 STARTS
    int i;
    for (i = (n / 2); i >= 1; i--)
    {
        heapify(arr, i, n);
    }
    // NOW ALL THE ELEMENTS SATISFY MAX HEAP CONDITION
    // STEP 2 STARTS
    while (n >= 1)
    {
        swap(&arr[1], &arr[n]);
        n--;
        heapify(arr, 1, n);
    }
    // ALL THE ROOT ELEMENTS (LARGEST ELEMENTS WERE SENT AT THE END, ARRAY IS NOW SORTED IN ASCENDING ORDER)
}

void main()
{
    printf("\n\nHow many elements of the array you want to enter? : \n\n");
    int len;
    scanf("%d", &len);
    int arr[len + 1];
    printf("\n\nEnter the array elements : \n\n");
    for (int i = 1; i < len + 1; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n\nThe input array is : \n\n");
    for (int i = 1; i < len + 1; i++)
    {
        printf("%d ", arr[i]);
    }
    heapsort(arr, len);
    printf("\n\nThe output array is : \n\n");
    for (int i = 1; i < len + 1; i++)
    {
        printf("%d ", arr[i]);
    }
}