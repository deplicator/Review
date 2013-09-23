#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void createArray(int array[], int size);
void randomizeArray(int array[], int size);
void printArray(int array[], int size);
void bubbleSort(int array[], int size);
void selectionSort(int array[], int size);
void bogoSort(int array[], int size);

int main() {
    int A[4];
    int Asize = 4;
    
    createArray(A, Asize);
    
    randomizeArray(A, Asize);
    bubbleSort(A, Asize);
    
    randomizeArray(A, Asize);
    selectionSort(A, Asize);
    
    //randomizeArray(A, Asize);
    //bogoSort(A, Asize);



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




































