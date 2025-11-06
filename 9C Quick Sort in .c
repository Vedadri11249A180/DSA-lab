#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high) {
  
    int pivot = arr[high];
    
   
    int i = low - 1; 

   
    for (int j = low; j <= high - 1; j++) {
       
        if (arr[j] < pivot) {
            i++; // Increment index of smaller element
            swap(&arr[i], &arr[j]); // Swap it into the 'smaller' section
        }
    }
    
   
    swap(&arr[i + 1], &arr[high]);
    
   
    return i + 1;
}


void quickSort(int arr[], int low, int high) {
    if (low < high) {
      
        int pi = partition(arr, low, high);

      
        quickSort(arr, low, pi - 1);  // Left subarray
        quickSort(arr, pi + 1, high); // Right subarray
    }
}



int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("--- Quick Sort Demonstration (Lomuto Partition) ---\n");

  
    printf("Original array: ");
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    printf("Sorted array (Quick Sort): ");
    printArray(arr, n);

    return 0;
}
