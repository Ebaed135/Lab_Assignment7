#include <stdio.h>

void bubbleSortCount();
void selectionSortCount();


int main(void) {
  
  

  int arr1[] = {97,  16,  45,  63,  13,  22,  7,  58,  72};
  int arr2[] = {90,  80,  70,  60,  50,  40,  30,  20,  10};

  bubbleSortCount(arr1, 9);
  bubbleSortCount(arr2, 9);
  selectionSortCount(arr1, 9);
  selectionSortCount(arr2, 9);
  
  return 0;
}

void bubbleSortCount(int arr[], int n) {
  int i, j, temp;
  long long int swapCount = 0;
  int uniqueValues[101] = {0}; // Assuming values are between 0 and 100

  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        // Swap arr[j] and arr[j+1]
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;

        swapCount++; // Increment total swap count
        uniqueValues[arr[j]]++; // Increment swap count for arr[j]
        uniqueValues[arr[j + 1]]++; // Increment swap count for arr[j+1]
      }
    }
  }

  // Print total swap count
  

  // Print number of swaps for each unique value
  for (i = 0; i < 101; i++) {
    if (uniqueValues[i] > 0) {
      printf("Value %d swapped %d times\n", i, uniqueValues[i]);
    }
  }
   printf("Total number of swaps: %lld\n", swapCount);
}


void selectionSortCount(int arr[], int n) {
    int i, j, min_idx, temp;
    long long int swapCount = 0;
    int uniqueValues[101] = {0}; // Assuming values are between 0 and 100

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the current element
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;

        swapCount++; // Increment total swap count
        uniqueValues[arr[i]]++; // Increment swap count for the current element
        uniqueValues[arr[min_idx]]++; // Increment swap count for the swapped element
    }

    // Print the number of swaps for each unique value
    for (i = 0; i < 101; i++) {
        if (uniqueValues[i] > 0) {
            printf("Value %d swapped %d times\n", i, uniqueValues[i]);
        }
    }
    printf("Total number of swaps: %lld\n", swapCount);
}
