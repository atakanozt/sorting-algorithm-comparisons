#include "selection_sort.h"

// Selection sort function
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        swap(&arr[i], &arr[min_index]);
    }
}

double get_time_selectionSort(int arr[], int n) {
    // Measure the time taken for sorting
    clock_t start_time = clock();
    
    selectionSort(arr, n);
    
    clock_t end_time = clock();
    
    // Calculate the elapsed time in milliseconds
    double elapsed_time = (double)(end_time - start_time) * 1000.0 / CLOCKS_PER_SEC;
    
    return elapsed_time;
}
