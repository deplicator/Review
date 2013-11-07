#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "array_functions.h"
#include "search_functions.h"
#include "sort_functions.h"

using namespace std;

void bruteForceSearch(int sorted[], int size, int N) {
    cout << "Start Brute Force Search for " << N << "." << endl;
    int foundFlag = 1;
    for(int i = 0; i < size; i++) {
        if(sorted[i] == N) {
            cout << "Found " << N << " in element " << i << "." << endl;
            foundFlag = 0;
        }
    }
    if(foundFlag) {
        cout << N << " not found in array." << endl;
    }
}


void binarySearch(int sorted[], int size, int N) {
    cout << "Start Binary Search for " << N << "." << endl;
    int left = 0;
    int right = size - 1;
    int middle;
    int foundFlag = 1;
    
    while(left < right) {
        middle = (left + right) / 2;
        cout << left << " " << right << " " << middle << endl;
        
        if(N < sorted[middle]) {
            cout << N << " is less than " << sorted[middle] << endl;
            right = middle - 1;
        } else if(N > sorted[middle]) {
            cout << N << " is greater than " << sorted[middle] << endl;
            left = middle + 1;
        } else {
            cout << "Found " << N << " in element " << middle << "." << endl;
            foundFlag = 0;
            break;
        }
        
    }
    
    if(foundFlag) {
         cout << N << " not found in array." << endl;
    }
    
}


void interpolationSearch(int sorted[], int size, int N) {
    
}
