#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum element in the array
int findMax(int arr[], int n) {
    int max = arr[0];
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform Counting Sort
void countingSort(int arr[], int n) {
    int max = findMax(arr, n);

    // Create a count array to store the count of each element
    int count[max + 1];
	int i;
    // Initialize the count array to all zeros
    for (i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Count the occurrences of each element in the input array
    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Reconstruct the sorted array from the count array
    int output[n];
    int outputIndex = 0;

    for (i = 0; i <= max; i++) {
        while (count[i] > 0) {
            output[outputIndex] = i;
            outputIndex++;
            count[i]--;
        }
    }

    // Copy the sorted array back to the original array
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
	int i;
    int arr[n];

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform Counting Sort
    countingSort(arr, n);

    printf("Sorted array using Counting Sort: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

//Hence we can conclude that the time compelxities for count sort is O(n + k) for all cases