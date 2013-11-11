#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "headers/array_functions.h"

//Fill an array with random numbers between 1 and 100.
void createArray(int list[], int size) {
    srand(time(NULL));
    for(int i = 0; i < size; i++) {
        list[i] = (rand() % 99) + 1;
    }
}

//Same as above, except fills the array with known numbers. 
void createArray(int list[], int size, int num) {
    srand(time(NULL));
    for(int i = 0; i < size; i++) {
        list[i] = i + num;
    }
}

//Print the array, I think it's pretty.
void printArray(int list[], int size, int start) {
    std::cout << "{";
    for (int i = start; i < size; i++) {
        std::cout << list[i];
        if (i != (size - 1)) {
            std::cout << ", ";
        }
    }
    std::cout << "}";
}
