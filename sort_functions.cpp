#include <iostream>
#include <cstdlib>
#include <algorithm>

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
    cout << endl << "Unsorted array = ";
    printArray(A, Asize);
    cout << endl;
    cout << endl;
    //bubbleSort(A, Asize);
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


void bubbleSort(int array[], int size) {
    cout << "Start Bubble Sort" << endl;
    for (int i = size; i > 1; i--) {
        cout << "pass " << size - i + 1 << " = ";
        printArray(array, i);
        cout << endl;
        for (int j = 0; j < (i - 1); j++) {
            cout << "    check " << j + 1 << " = " << array[j] << " against " << array[j + 1] << endl;
            if (array[j] > array[j + 1]) {
                cout << "        " << array[j] << " is higher than " << array[j + 1] << ", so swap." << endl;
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                cout << "        current array -->";
                printArray(array, i);
                cout << endl << endl;
            } else {
                cout << "        " << array[j] << " is lower than " << array[j + 1] << ", no change." << endl << endl;
            }
        }
        
    }
}


void bogoSort(int array[], int size) {
    cout << "Start Bogosort on ";
    printArray(array, size);
    cout << endl;
    int count = 0;
    int globalCount = 1;
    while(count < size) {
        cout << "pass " << globalCount << endl;
        if (array[count] < array[count + 1]) {
            cout << "    check " << count + 1 << " - " << array[count] << " is lower than " << array[count + 1] << " continue."<< endl;
            count ++;
        } else {
            count = 0;
            cout << "    check " << count + 1 << " - " << array[count] << " is not lower than " << array[count + 1] << endl << "Reshuffling array = ";
            randomizeArray(array, size);
            printArray(array, size);
            cout << endl;
        }
        globalCount++;        
    }
}




































