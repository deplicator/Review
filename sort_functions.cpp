#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void createArray(int array[], int size);
void randomizeArray(int array[], int size);
void printArray(int array[], int size);
void bubbleSort(int array[], int size);
void bogoSort(int array[], int size);

int main() {
    int A[4];
    int Asize = 4;
    
    createArray(A, Asize);
    cout << endl << "  Unsorted array = ";
    printArray(A, Asize);
    cout << endl;
    cout << endl;
    
    bubbleSort(A, Asize);
    
    randomizeArray(A, Asize);
    bogoSort(A, Asize);



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
 * Bubble sort.
 */
void bubbleSort(int array[], int size) {

    cout << "  Bubble Sort" << endl;
    cout << "  -----------" << endl << endl;
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
                cout << "    " << array[j] << " is higher than " << array[j + 1] << ", so swap." << endl;
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                cout << "    current array -->";
                printArray(array, i);
                cout << endl << endl;
            } else {
                cout << "    " << array[j] << " is lower than " << array[j + 1] << ", no change." << endl << endl;
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

    cout << endl << "  Bogosort";
    cout << endl << "  --------" << endl << endl;
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




































