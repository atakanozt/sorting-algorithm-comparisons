#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utility.h"

/*
THE IMPLEMENTATION OF MERGE SORT ALGORITHM IS SOURCED FROM https://www.geeksforgeeks.org/merge-sort/
You can find the further information at https://www.geeksforgeeks.org/merge-sort/

*/
void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);
double get_time_mergeSort(int *arr, int n);
