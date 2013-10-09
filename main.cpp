#include <algorithm>
#include <cstdlib>
#include <ctime>    //time difference 0 when compiled on gcc, but gives a result in Visual Studios.
#include <iostream>
#include "sort_functions.h"

using namespace std;

int main() {
    
    const int Asize = 4;
    int A[Asize];
    int B[Asize];
    
    createArray(A, Asize);
    copy(A, A+Asize, B); //Make a backup copy of array A so the exact same array is passed to each sort.
	
    bubbleSort(A, Asize);
    
    copy(B, B+Asize, A); //Restore array A from backup.
    selectionSort(A, Asize);
	
    copy(B, B+Asize, A); //Restore array A from backup.
    insertionSort(A, Asize);
    
    copy(B, B+Asize, A); //Restore array A from backup.
    bogoSort(A, Asize);

    copy(B, B+Asize, A); //Restore array A from backup.
    quickSort(A, Asize-1);

    return 0;
}
