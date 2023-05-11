#include "quick_sort3.h"

// Partition function for quicksort
void partition(int arr[], int low, int high, int* i, int* j) {
    if (high - low <= 1) {
        if (arr[high] < arr[low])
            swap(&arr[high], &arr[low]);
        *i = low;
        *j = high;
        return;
    }

    int mid = low;
    int pivot = arr[high];
    while (mid <= high) {
        if (arr[mid] < pivot)
            swap(&arr[low++], &arr[mid++]);
        else if (arr[mid] == pivot)
            mid++;
        else if (arr[mid] > pivot)
            swap(&arr[mid], &arr[high--]);
    }
    *i = low - 1;
    *j = mid;
}

// Quicksort function with "Quick Sort 3" optimization
void quickSort3(int arr[], int low, int high) {
    if (low < high) {
        int i, j;
        partition(arr, low, high, &i, &j);

        quickSort3(arr, low, i);
        quickSort3(arr, j, high);
    }
}

double get_time_quickSort3(int arr[], int n) {
    // Measure the time taken for sorting
    clock_t start_time = clock();
    
    quickSort3(arr, 0, n - 1);
    
    clock_t end_time = clock();
    
    // Calculate the elapsed time in milliseconds
    double elapsed_time = (double)(end_time - start_time) * 1000.0 / CLOCKS_PER_SEC;
    
    return elapsed_time;
}
