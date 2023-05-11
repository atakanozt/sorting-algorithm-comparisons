#include "heap_sort.h"

// Heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i;      // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child
 
    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;
 
    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;
 
    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
 
        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Heap sort function
void heapSort(int arr[], int n) {
    // Build the heap (rearrange the array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move the current root to the end
        swap(&arr[0], &arr[i]);
 
        // Heapify the reduced heap
        heapify(arr, i, 0);
    }
}

double get_time_heapSort(int arr[], int n) {
    // Measure the time taken for sorting
    clock_t start_time = clock();
    
    heapSort(arr, n);
    
    clock_t end_time = clock();
    
    // Calculate the elapsed time in milliseconds
    double elapsed_time = (double)(end_time - start_time) * 1000.0 / CLOCKS_PER_SEC;
    
    return elapsed_time;
}
