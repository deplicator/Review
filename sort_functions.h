#ifndef SORT_FUNCTIONS_H
#define SORT_FUNCTIONS_H

void bubbleSort(int array[], int size);
void selectionSort(int array[], int size);
void insertionSort(int array[], int size);
void bogoSort(int array[], int size);
void quickSort(int unsorted[], int right);
void quickSort(int unsorted[], int right, int left);
void mergeSort(int unsorted[], int right);
void mergeSort(int A[], int B[], int left, int right);
void merge(int A[], int B[], int left, int middle, int right);

#endif
