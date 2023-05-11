#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "merge_sort.h"
#include "quick_sort.h"
#include "heap_sort.h"
#include "shell_sort.h"
#include "bubble_sort.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "quick_sort3.h"
#include "utility.h"

// Function to generate random arrays
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000 + 1;  // Generate random numbers between 1 and 1000000
    }
}

int main() {
    srand(time(NULL));  // Seed the random number generator
    
    int n;
    scanf("%d", &n);
    
    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    
    // Generate a random array
    generateRandomArray(arr, n);
    
    // Merge Sort
    double mergeSortTime = get_time_mergeSort(arr, n);
    printf("Merge Sort - Time taken: %f milliseconds\n", mergeSortTime);
    
    // Quick Sort
    double quickSortTime = get_time_quickSort(arr, n);
    printf("Quick Sort - Time taken: %f milliseconds\n", quickSortTime);
    
    // Heap Sort
    double heapSortTime = get_time_heapSort(arr, n);
    printf("Heap Sort - Time taken: %f milliseconds\n", heapSortTime);
    
    // Shell Sort
    double shellSortTime = get_time_shellSort(arr, n);
    printf("Shell Sort - Time taken: %f milliseconds\n", shellSortTime);
    
    // Bubble Sort
    double bubbleSortTime = get_time_bubbleSort(arr, n);
    printf("Bubble Sort - Time taken: %f milliseconds\n", bubbleSortTime);
    
    // Selection Sort
    double selectionSortTime = get_time_selectionSort(arr, n);
    printf("Selection Sort - Time taken: %f milliseconds\n", selectionSortTime);
    
    // Insertion Sort
    double insertionSortTime = get_time_insertionSort(arr, n);
    printf("Insertion Sort - Time taken: %f milliseconds\n", insertionSortTime);
    
    // Quick Sort 3
    double quickSort3Time = get_time_quickSort3(arr, n);
    printf("Quick Sort 3 - Time taken: %f milliseconds\n", quickSort3Time);
    
    // Free the dynamically allocated memory
    free(arr);
    
    return 0;
}
