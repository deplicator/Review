#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "array_functions.h"
#include "sort_functions.h"

using namespace std;

void createArray(int array[], int size) {
    srand(time(NULL));
    for(int i = 0; i < size; i++) {
        array[i] = (rand() % 99) + 1;
    }
}

void createArray(int array[], int size, int num) {
    srand(time(NULL));
    for(int i = 0; i < size; i++) {
        array[i] = i + num;
    }
}

void printArray(int array[], int size, int start) {
    cout << "{";
    for (int i = start; i < size; i++) {
        cout << array[i];
        if (i != (size - 1)) {
            cout << ", ";
        }
    }
    cout << "}";
}

