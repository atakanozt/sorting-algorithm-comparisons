#include "quick_sort.h"


// Partition function for quicksort
int partitionq(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose the last element as the pivot
    int i = (low - 1);      // Index of the smaller element
 
    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;    // Increment index of the smaller element
            swap(&arr[i], &arr[j]);
        }
    }
 
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quicksort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pivotIndex = partitionq(arr, low, high);
 
        // Recursively sort the elements before and after the pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

double get_time_quickSort(int arr[], int n) {
    // Measure the time taken for sorting
    clock_t start_time = clock();
    
    quickSort(arr, 0, n - 1);
    
    clock_t end_time = clock();
    
    // Calculate the elapsed time in milliseconds
    double elapsed_time = (double)(end_time - start_time) * 1000.0 / CLOCKS_PER_SEC;
    
    return elapsed_time;
}
