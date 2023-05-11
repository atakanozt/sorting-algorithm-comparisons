#include "insertion_sort.h"

// Insertion sort function
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

double get_time_insertionSort(int arr[], int n) {
    // Measure the time taken for sorting
    clock_t start_time = clock();
    
    insertionSort(arr, n);
    
    clock_t end_time = clock();
    
    // Calculate the elapsed time in milliseconds
    double elapsed_time = (double)(end_time - start_time) * 1000.0 / CLOCKS_PER_SEC;
    
    return elapsed_time;
}
