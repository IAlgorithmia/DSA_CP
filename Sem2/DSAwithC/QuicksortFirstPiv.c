#include <stdio.h>
int partition(int arr[], int low, int high)
{
   int pivot = arr[low];
   int i = low + 1;
   int j = high;
   int temp;
   while (1)
   {
      while (arr[i] <= pivot)
      {
         i++;
      }
      while (arr[j] > pivot)
      {
         j--;
      }
      if (i < j)
      {
         arr[i] = arr[i] + arr[j];
         arr[j] = arr[i] - arr[j];
         arr[i] = arr[i] - arr[j];
         i++;
         j--;
      }
      if (j <= i)
      {
         temp = arr[low];
         arr[low] = arr[j];
         arr[j] = temp;
         return j;
      }
   }
}
void quicksort(int arr[], int low, int high)
{
   if (low < high)
   {
      int thatindex;
      thatindex = partition(arr, low, high);
      quicksort(arr, low, thatindex - 1);
      quicksort(arr, thatindex + 1, high);
   }
}
void printarray(int arr[], int len)
{
   for (int i = 0; i < len; i++)
   {
      printf("%d ", arr[i]);
   }
   printf("\n");
}
int main()
{
   int len;
   printf("Enter the number of elements you want to enter : ");
   scanf("%d", &len);
   int array[len];
   printf("Enter the elements : ");
   int i;
   for (i = 0; i < len; i++)
   {
      scanf("%d", &array[i]);
   }
   quicksort(array, 0, len - 1);
   printf("The sorted array is : \n");
   printarray(array, len);
}