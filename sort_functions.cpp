#include <algorithm>
#include <cstdlib>
#include <time.h>
#include <iostream>

using namespace std;

void createArray(int array[], int size);
void randomizeArray(int array[], int size);
void printArray(int array[], int size);

void bubbleSort(int array[], int size);
void selectionSort(int array[], int size);
void insertionSort(int array[], int size);
void bogoSort(int array[], int size);

int main() {

    clock_t start, end;
    
    start = clock();
    
    int Asize = 4;
    int A[Asize];
    
    createArray(A, Asize);
    
    randomizeArray(A, Asize);
    bubbleSort(A, Asize);
    
    randomizeArray(A, Asize);
    selectionSort(A, Asize);
    
    randomizeArray(A, Asize);
    insertionSort(A, Asize);
    
    //randomizeArray(A, Asize);
    //bogoSort(A, Asize);

    end = clock();
    
    cout << start << endl << end << endl;

    return 0;
}


void createArray(int array[], int size) {
    srand(time(NULL));
    for(int i = 0; i < size; i++) {
        array[i] = (rand() % 99) + 1;
    }
}


void randomizeArray(int array[], int size) {
    random_shuffle(&array[0], &array[size]);
}


void printArray(int array[], int size) {
    cout << "{";
    for (int i = 0; i < size; i++) {
        cout << array[i];
        if (i != (size - 1)) {
            cout << ", ";
        }
    }
    cout << "}";
}

/*
 * Bubble Sort
 */
void bubbleSort(int array[], int size) {

    cout << endl << "  Bubble Sort" << endl;
    cout << "  -----------" << endl;
    cout << "  original array: ";
    printArray(array, size);
    cout << endl << endl;
    
    for (int i = size; i > 1; i--) {
        cout << "  pass " << size - i + 1 << " = ";
        printArray(array, i);
        cout << endl;
        for (int j = 0; j < (i - 1); j++) {
            cout << "    check array[" << j << "] against array[" << j + 1 << "]" << endl;
            if (array[j] > array[j + 1]) {
                cout << "    " << array[j] << " is greater than " << array[j + 1] << " so swap. -->";
                
                
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                
                printArray(array, size);
                cout << endl << endl;
            } else {
                cout << "    " << array[j] << " is less than " << array[j + 1] << " so continue. --> ";
                printArray(array, size);
                cout << endl << endl;
            }
        }
    }
    
    cout << "  final array: ";
    printArray(array, size);
    cout << endl << endl;
}


/*
 * Selection Sort
 */
void selectionSort(int array[], int size) {
    cout << endl << "  Selection Sort" << endl;
    cout << "  --------------" << endl;
    cout << "  original array: ";
    printArray(array, size);
    cout << endl << endl;
    
    for (int i = 0; i < (size - 1); i++) {
        cout << "  pass " << i + 1 << " = ";
        printArray(array, (size - i));
        cout << endl;
        
        for (int j = (i + 1); j < size; j++) {
            cout << "    check array[" << i << "] against array[" << j << "]" << endl;
            if (array[i] > array [j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                cout << "    " << array[i] << " is greater than " << array[j] << " so swap. --> ";
                printArray(array, size);
                cout << endl << endl;
            } else {
                cout << "    " << array[i] << " is less than " << array[j] << " so continue. --> ";
                printArray(array, size);
                cout << endl << endl;
            }
        }
    }
    
    cout << "  final array: ";
    printArray(array, size);
    cout << endl << endl;
}


/*
 * Insertion Sort
 */
void insertionSort(int array[], int size) {
    cout << endl << "  Insertion Sort" << endl;
    cout << "  --------------" << endl;
    cout << "  original array: ";
    printArray(array, size);
    cout << endl << endl;
    
    int temp, j;
    for (int i = 1; i < size; i++) {
        temp = array[i];
        cout << "  pass " << i << " = sorted so far: ";
        printArray(array, i);
        cout << " temp = " << temp << endl;

        for (j = (i - 1); j >= 0; j--) {
            cout << "    compare temp against element " << j << endl;
            if (temp < array[j]) {
                array[j + 1] = array[j];
                cout << "    it's lower so copy element " << j << " right --> ";
                printArray(array, i + 1);
                cout << endl << endl;
            } else {
                cout << "    it's higher so insert behind --> ";
                break;
            }
        }
        array[j + 1] = temp;
        printArray(array, i + 1);
        cout << endl << endl;
    }
    
    cout << "  final array: ";
    printArray(array, size);
    cout << endl << endl;
}


/*
 * Bogosort
 * http://en.wikipedia.org/wiki/Bogosort
 */
void bogoSort(int array[], int size) {

    cout << endl << "  Bogosort" << endl;
    cout << "  --------" << endl;
    cout << "    Initial array = ";
    printArray(array, size);
    cout << endl;
    int count = 0;
    int reshuffleCount = 0;
    while(count < size-1) {
        cout << "    checking element " << count << ": " << array[count];

        if (array[count] < array[count + 1] || array[count] == array[count + 1] ) {
            cout << " is lower than " << array[count + 1] << " continue."<< endl;
            count++;
        } else {
            count = 0;
            cout << " is not lower than " << array[count + 2] << endl << endl;
            cout << "    Reshuffling array = ";
            randomizeArray(array, size);
            printArray(array, size);
            reshuffleCount++;
            cout << endl;
        }
    }
    cout << endl << "  It took " << reshuffleCount << " reshuffels to complete." << endl;
    cout << "  final array: ";
    printArray(array, size);
    cout << endl << endl;
    
    

}




































