#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utility.h"

void swap(int* a, int* b);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
double get_time_quickSort(int arr[], int n);