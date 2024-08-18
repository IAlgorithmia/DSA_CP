#include <stdio.h>
#include <stdlib.h>

#define INTERVAL 10  // Each bucket capacity

struct Node {
  int data;
  struct Node *next;
};

void BucketSort(int arr[], int length);
struct Node *InsertionSort(struct Node *list);
void print(int arr[], int length);
void printBuckets(struct Node *list);
int getBucketIndex(int value, int value2);

// Sorting function
void BucketSort(int arr[], int length) {
  int i, j;
  struct Node **buckets;
  int min_value = arr[0];
  int max_value = arr[0];

  // Find the minimum and maximum values in the array
  for (i = 1; i < length; ++i) {
    if (arr[i] < min_value) {
      min_value = arr[i];
    } else if (arr[i] > max_value) {
      max_value = arr[i];
    }
  }

  // Calculate the number of buckets
  int num_buckets = (max_value - min_value) / INTERVAL + 1;

  // Create buckets and allocate memory size
  buckets = (struct Node **)malloc(sizeof(struct Node *) * num_buckets);

  // Initialize empty buckets
  for (i = 0; i < num_buckets; ++i) {
    buckets[i] = NULL;
  }

  // Fill the buckets with respective elements
  for (i = 0; i < length; ++i) {
    struct Node *current;
    int pos = getBucketIndex(arr[i], min_value);
    current = (struct Node *)malloc(sizeof(struct Node));
    current->data = arr[i];
    current->next = buckets[pos];
    buckets[pos] = current;
  }

  // Sort the elements of each bucket
  for (i = 0; i < num_buckets; ++i) {
    buckets[i] = InsertionSort(buckets[i]);
  }

  // Merge the sorted buckets back into the original array
  for (j = 0, i = 0; i < num_buckets; ++i) {
    struct Node *node;
    node = buckets[i];
    while (node) {
      arr[j++] = node->data;
      node = node->next;
    }
  }

  // Free memory allocated for buckets
  for (i = 0; i < num_buckets; ++i) {
    struct Node *current = buckets[i];
    while (current) {
      struct Node *temp = current;
      current = current->next;
      free(temp);
    }
  }
  free(buckets);
}

// Function to sort the elements of each bucket
struct Node *InsertionSort(struct Node *list) {
  // Implementation of insertion sort
  // ...

  return list;
}

int getBucketIndex(int value, int min_value) {
  return (value - min_value) / INTERVAL;
}

void print(int arr[], int length) {
  int i;
  for (i = 0; i < length; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// Print buckets
void printBuckets(struct Node *list) {
  struct Node *cur = list;
  while (cur) {
    printf("%d ", cur->data);
    cur = cur->next;
  }
}

// Driver code
int main(void) {
  int length;
  printf("Enter the length of the array: \n");
  scanf("%d", &length);
  int i;
  int arr[length];
  printf("Enter the elements: \n");
  for (i = 0; i < length; i++) {
    scanf("%d", &arr[i]);
  }
  printf("\n-------------\n");
  printf("Unsorted array: ");
  print(arr, length);
  printf("\n-------------\n");
  printf("Sorted array: ");
  BucketSort(arr, length);
  print(arr, length);
  return 0;
}

//Hence we can conclude that the best and average case time compelxities for bucket sort are O(n + k) and for worst cse, the time complexity is O(n^20