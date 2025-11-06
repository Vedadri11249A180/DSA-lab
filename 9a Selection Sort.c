#include <stdio.h>
#include <stdlib.h> 
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, minIndex;

   for (i = 0; i < n - 1; i++) {
        // Assume the current element is the minimum
        minIndex = i;


        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        
        if (minIndex != i) {
            swap(&arr[i], &arr[minIndex]);
        }
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
  
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("--- Selection Sort Demonstration ---\n");
    
    
    printf("Original array: ");
    printArray(arr, n);

  
    selectionSort(arr, n);

    
    printf("Sorted array (Selection Sort): ");
    printArray(arr, n);

    return 0;
}
