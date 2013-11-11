#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "headers/search_functions.h"

//Uses a brute force search to find N.
void bruteForceSearch(int sorted[], int size, int N) {
    std::cout << "Start Brute Force Search for " << N << "." << std::endl;
    int foundFlag = 1;
    for(int i = 0; i < size; i++) {
        if(sorted[i] == N) {
            std::cout << "Found " << N << " in element " << i << "." << std::endl;
            foundFlag = 0;
        }
    }
    if(foundFlag) {
        std::cout << N << " not found in array." << std::endl;
    }
}

//Uses a binary search to find N.
void binarySearch(int sorted[], int size, int N) {
    std::cout << "Start Binary Search for " << N << "." << std::endl;
    int left = 0;
    int right = size - 1;
    int middle;
    int foundFlag = 1;
    
    while(left < right) {
        middle = (left + right) / 2;
        std::cout << left << " " << right << " " << middle << std::endl;
        
        if(N < sorted[middle]) {
            std::cout << N << " is less than " << sorted[middle] << std::endl;
            right = middle - 1;
        } else if(N > sorted[middle]) {
            std::cout << N << " is greater than " << sorted[middle] << std::endl;
            left = middle + 1;
        } else {
            std::cout << "Found " << N << " in element " << middle << "." << std::endl;
            foundFlag = 0;
            break;
        }   
    }
    if(foundFlag) {
         std::cout << N << " not found in array." << std::endl;
    }
    
}


//Uses an interpolation search to find N.
void interpolationSearch(int sorted[], int size, int N) {
    std::cout << "Start Interpolation Search for " << N << "." << std::endl;
    int left = 0;
    int right = size - 1;
    int middle;
    int foundFlag = 1;
    
    while(sorted[left] <= N && sorted[right] >= N) {
        middle = left + ((N - sorted[left]) * (right - left) / (sorted[right] - sorted[left]));
        if(N > sorted[middle]) {
            left = middle + 1;
        } else if(N < sorted[middle]) {
            right = middle - 1;
        } else {
            std::cout << "Found " << N << " in element " << middle << "." << std::endl;
            foundFlag = 0;
            break;
        }
    }
    
    if(foundFlag) {
        std::cout << N << " not found in array." << std::endl;
    }
}








