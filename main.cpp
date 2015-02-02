#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "headers/Node.h"
#include "headers/array_functions.h"
#include "headers/llll.h"
#include "headers/search_functions.h"
#include "headers/sort_functions.h"


using namespace std;

int main() {

    const int Asize = 4;
    int A[Asize];
    int B[Asize];

    createArray(A, Asize); //create an array with known elements.
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

    copy(B, B+Asize, A); //Restore array A from backup.
    int Bu[Asize];
    mergeSort(A, Asize-1);

    //leave A sorted for searching.
    bruteForceSearch(A, Asize, 50);
    binarySearch(A, Asize, 75);
    interpolationSearch(A, Asize, 15);

    Node* head;
    createNodes(head, 4);
    populateNodes(head, 1, 100);
    printNodeValues(head);
    insertNewNode(head, 2, 101);
    printNodeValues(head);
    removeNode(head, 3);
    printNodeValues(head);
    cleanupNodes(head);

    return 0;
}
