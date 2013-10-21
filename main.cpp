#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "array_functions.h"
#include "search_functions.h"
#include "sort_functions.h"


using namespace std;

int main() {
    
    const int Asize = 4;
    int A[Asize];
    int B[Asize];
    
    createArray(A, Asize);
    copy(A, A+Asize, B); //Make a backup copy of array A so the exact same array is passed to each sort.
	
    bubbleSort(A, Asize);
    /*
    copy(B, B+Asize, A); //Restore array A from backup.
    selectionSort(A, Asize);
	
    copy(B, B+Asize, A); //Restore array A from backup.
    insertionSort(A, Asize);
    
    copy(B, B+Asize, A); //Restore array A from backup.
    bogoSort(A, Asize);

    copy(B, B+Asize, A); //Restore array A from backup.
    quickSort(A, Asize-1);
    
    copy(B, B+Asize, A); //Restore array A from backup.
    int Bu[Asize];
    mergeSort(A, Asize-1);
    */
    //leave A sorted for searching.
    bruteForceSearch(A, Asize, 50);

    return 0;
}
