#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "headers/array_functions.h"
#include "headers/search_functions.h"

/*
 * Uses a brute force search to find N.
 */
void bruteForceSearch(int sorted[], int size, int N) {
    std::cout << "\n";
    std::cout << "  Brute Force Search\n";
    std::cout << "  ------------------\n";
    std::cout << "  Searching for " << N << " in ";
    printArray(sorted, size);
    std::cout << ".\n\n";
    
    int foundFlag = 1;
    int searchCount = 0;
    
    for(int i = 0; i < size; i++) {
        std::cout << "    Compare value of position " << i << " in array with " << N << ".\n";
        if(sorted[i] == N) {
            std::cout << "    Found " << N << " at position " << i << "!\n";
            std::cout << "    Search took " << searchCount + 1 << " comparisons.\n\n";
            foundFlag = 0;
            break;
        }
        std::cout << "    They are not equal, keep searching.\n\n";
        searchCount++;
    }
    if(foundFlag) {
        std::cout << "    " << N << " was not found in array.\n";
        std::cout << "    Search took " << searchCount << " comparisons.\n\n";
    }
}

/*
 * Uses a binary search to find N.
 */
void binarySearch(int sorted[], int size, int N) {
    std::cout << "\n";
    std::cout << "  Binary Search\n";
    std::cout << "  -------------\n";
    std::cout << "  Searching for " << N << " in ";
    printArray(sorted, size);
    std::cout << ".\n\n";
    
    int left = 0;
    int right = size - 1;
    int middle;
    
    int foundFlag = 1;
    int searchCount = 0;
    
    while(left < right) {
        middle = (left + right) / 2;
        
        std::cout << "    Set left to " << left << ".\n";
        std::cout << "    Set right to " << right << ".\n";
        std::cout << "    Calculate middle: (" 
                  << left << " + " << right << ") / 2 = " << middle << "\n";

        if(N < sorted[middle]) {
            std::cout << "    " << N << " is less than " << sorted[middle] << ", keep searching.\n\n";
            right = middle - 1;
            searchCount++;
        } else if(N > sorted[middle]) {
            std::cout << "    " << N << " is greater than " << sorted[middle] << ", keep searching\n\n";
            left = middle + 1;
            searchCount++;
        } else {
            std::cout << "    Found " << N << " in position " << middle << "!\n";
            std::cout << "    Search took " << searchCount + 1 << " comparisons.\n\n";
            foundFlag = 0;
            break;
        }   
    }
    if(foundFlag) {
        std::cout << "    " << N << " was not found in array.\n";
        std::cout << "    Search took " << searchCount << " comparisons.\n\n";
    }
    
}


//Uses an interpolation search to find N.
void interpolationSearch(int sorted[], int size, int N) {
    std::cout << "\n";
    std::cout << "  Interpolation Search\n";
    std::cout << "  --------------------\n";
    std::cout << "  Searching for " << N << " in ";
    printArray(sorted, size);
    std::cout << ".\n\n";
    
    int left = 0;
    int right = size - 1;
    int middle;
    
    int foundFlag = 1;
    int searchCount = 0;
        
    while(sorted[left] <= N && sorted[right] >= N) {
        middle = left + ((N - sorted[left]) * (right - left) / (sorted[right] - sorted[left]));
        
        std::cout << "    Set left to " << left << ".\n";
        std::cout << "    Set right to " << right << ".\n";
        std::cout << "    Calculate middle: " << left << " + "
                  << "((" << N << " - " << sorted[left] << ") * (" 
                  << right << " - " << left << ") / (" 
                  << sorted[right] << " - " << sorted[left] << ")) = " 
                  << middle << "\n";
        
        if(N > sorted[middle]) {
            std::cout << "    " << N << " is less than " << sorted[middle] << ", keep searching.\n\n";
            left = middle + 1;
        } else if(N < sorted[middle]) {
            std::cout << "    " << N << " is greater than " << sorted[middle] << ", keep searching.\n\n";
            right = middle - 1;
        } else {
            std::cout << "    Found " << N << " in position " << middle << "!\n";
            std::cout << "    Search took " << searchCount + 1 << " comparisons.\n\n";
            foundFlag = 0;
            break;
        }
    }
    
    if(foundFlag) {
        std::cout << "    " << N << " was not found in array.\n";
        std::cout << "    Search took " << searchCount << " comparisons.\n\n";
    }
}








