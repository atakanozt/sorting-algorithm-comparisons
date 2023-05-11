#include "shell_sort.h"

// Shell sort function
void shellSort(int arr[], int n) {
    // Start with a large gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort for this gap size
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
 
            // Shift elements until the correct location for arr[i] is found
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
 
            arr[j] = temp;
        }
    }
}

double get_time_shellSort(int arr[], int n) {
    // Measure the time taken for sorting
    clock_t start_time = clock();
    
    shellSort(arr, n);
    
    clock_t end_time = clock();
    
    // Calculate the elapsed time in milliseconds
    double elapsed_time = (double)(end_time - start_time) * 1000.0 / CLOCKS_PER_SEC;
    
    return elapsed_time;
}
