#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "array_functions.h"
#include "search_functions.h"
#include "sort_functions.h"

using namespace std;

void bruteForceSearch(int sorted[], int size, int N) {
    cout << "Start brute Force search for " << N << "." << endl;
    int foundFlag = 0;
    for(int i = 0; i < size; i++) {
        if(sorted[i] == N) {
            cout << "Found " << N << " in element " << i << "." << endl;
            foundFlag = 1;
        }
    }
    if(!foundFlag) {
        cout << N << " not found in array." << endl;
    }
}


void binarySearch(int sorted[], int size, int N) {
    
}


void interpolationSearch(int sorted[], int size, int N) {
    
}
