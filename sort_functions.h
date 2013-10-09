#ifndef SORT_FUNCTIONS_H
#define SORT_FUNCTIONS_H

void createArray(int array[], int size);
void printArray(int array[], int size, int start);

void bubbleSort(int array[], int size);
void selectionSort(int array[], int size);
void insertionSort(int array[], int size);
void bogoSort(int array[], int size);
void quickSort(int unsorted[], int right);
void quickSort(int unsorted[], int right, int left);

#endif
