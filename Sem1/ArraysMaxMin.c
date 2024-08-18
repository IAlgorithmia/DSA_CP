#include <stdio.h>
int num;
int maximum(int array[])
{
	int max = array[0];
	int j;
	for (j = 0; j <= num - 1; j++)
	{
		if (max < array[j])
		{
			max = array[j];
		 // j = 0; This is not compulsary, it's optional - Genius !!!!
		 // Agar piche koi chota vala hota to is element tak baat hi na aati !!
		}
	}
	return max;
}
int minimum(int array[])
{
	int min = array[0];
	int j;
	for (j = 0; j <= num - 1; j++)
	{
		if (min > array[j])
		{
			min = array[j];
			j = 0; // This is not compulsary, it's optional - Genius !!!!
		}
	}
	return min;
}
int main()
{
	printf("Enter the number of elements you want in the array : \n");
	scanf("%d", &num);
	int arr[num];
	int i;
	for (i == 0; i <= num - 1; i++)
	{
		int x;
		printf("Enter the element %d of the array : \n", i+1);
		scanf("%d", &x);
		arr[i] = x;
	}
	printf("The largest element of the array is : %d\n", maximum(arr));
	printf("The smallest element of the array is : %d\n", minimum(arr));
}
