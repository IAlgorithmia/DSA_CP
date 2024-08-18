#include <stdio.h>
void swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
int main()
{
	printf("Enter the number of elements you want in the array : "); int num; scanf("%d", &num);
	int arr[num];
	int i, j;
	for (i = 0; i <= num - 1; i++)
	{
		printf("Enter the element : ");
		scanf("%d",&arr[i]);
	}
	for (i = 0; i <= num - 1; i++)
	{
		for (j = 0; j <= num - 1; j++)
		{
			if (arr[i] < arr[j])
			{
				swap(&arr[i], &arr[j]);
			}
		}
	}
	printf("The sorted array is : \n");
	for (i = 0; i <= num - 1; i++)
	{
		printf("%d ", arr[i]);
	}
}
