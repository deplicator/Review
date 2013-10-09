#include <algorithm>
#include <cstdlib>
#include <ctime>    //time difference 0 when compiled on gcc, but gives a result in Visual Studios.
#include <iostream>

using namespace std;

void createArray(int array[], int size);
void printArray(int array[], int size, int start);

void bubbleSort(int array[], int size);
void selectionSort(int array[], int size);
void insertionSort(int array[], int size);
void bogoSort(int array[], int size);
void quickSort(int unsorted[], int right);
void quickSort(int unsorted[], int right, int left);

int main() {
    
    const int Asize = 10;
    int A[Asize];
    int B[Asize];
    
    createArray(A, Asize);
    copy(A, A+Asize, B); //Make a backup copy of array A so the exact same array is passed to each sort.
	
    //bubbleSort(A, Asize);
    
    //copy(B, B+Asize, A); //Restore array A from backup.
    //selectionSort(A, Asize);
	
    //copy(B, B+Asize, A); //Restore array A from backup.
    //insertionSort(A, Asize);
    
    //copy(B, B+Asize, A); //Restore array A from backup.
    //bogoSort(A, Asize);

    //copy(B, B+Asize, A); //Restore array A from backup.
    quickSort(A, Asize-1);

    return 0;
}


void createArray(int array[], int size) {
    srand(time(NULL));
    for(int i = 0; i < size; i++) {
        array[i] = (rand() % 99) + 1;
    }
}


void printArray(int array[], int size, int start = 0) {
    cout << "{";
    for (int i = start; i < size; i++) {
        cout << array[i];
        if (i != (size - 1)) {
            cout << ", ";
        }
    }
    cout << "}";
}

/*
 * Bubble Sort
 * http://en.wikipedia.org/wiki/Bubble_sort
 */
void bubbleSort(int array[], int size) {
	clock_t start, end;
    start = clock();

    cout << endl << "  Bubble Sort" << endl;
    cout << "  -----------" << endl;
    cout << "  original array: ";
    printArray(array, size);
    cout << endl << endl;
    
    for (int i = size; i > 1; i--) {
        cout << "  pass " << size - i + 1 << endl << "    sorted so far: ";
        printArray(array, size, i);
        cout << endl << endl;
        for (int j = 0; j < (i - 1); j++) {
            cout << "    check element " << j << " against element " << j + 1 << endl;
            if (array[j] > array[j + 1]) {
                cout << "    " << array[j] << " is greater than " << array[j + 1] << " so swap. --> ";
                
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

    end = clock();

    cout << "  Final array: ";
    printArray(array, size);
    cout << endl << "  Time to complete " << ((float)end - start) / CLOCKS_PER_SEC << " seconds." << endl << endl;
}


/*
 * Selection Sort
 * http://en.wikipedia.org/wiki/Selection_sort
 */
void selectionSort(int array[], int size) {
	clock_t start, end;
    start = clock();

    cout << endl << "  Selection Sort" << endl;
    cout << "  --------------" << endl;
    cout << "  original array: ";
    printArray(array, size);
    cout << endl << endl;
    
    for (int i = 0; i < (size - 1); i++) {
        cout << "  pass " << i + 1 << endl << "    sorted so far: ";
        printArray(array, size, size - i);
        cout << endl << endl;
        
        for (int j = (i + 1); j < size; j++) {
            cout << "    check element " << i << " against element " << j << endl;
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
    
    end = clock();

    cout << "  Final array: ";
    printArray(array, size);
    cout << endl << "  Time to complete " << ((float)end - start) / CLOCKS_PER_SEC << " seconds." << endl << endl;
}


/*
 * Insertion Sort
 * http://en.wikipedia.org/wiki/Insertion_sort
 */
void insertionSort(int array[], int size) {
	clock_t start, end;
    start = clock();

    cout << endl << "  Insertion Sort" << endl;
    cout << "  --------------" << endl;
    cout << "  original array: ";
    printArray(array, size);
    cout << endl << endl;
    
    int temp, j;
    for (int i = 1; i < size; i++) {
        temp = array[i];
        cout << "  pass " << i << endl <<"    sorted so far: ";
        printArray(array, i);
        cout << endl << "    temp: " << temp << endl << endl;

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
        //printArray(array, i + 1);
        cout << endl << endl;
    }

    end = clock();

    cout << "  Final array: ";
    printArray(array, size);
    cout << endl << "  Time to complete " << ((float)end - start) / CLOCKS_PER_SEC << " seconds." << endl << endl;
}


/*
 * Bogosort
 * http://en.wikipedia.org/wiki/Bogosort
 */
void bogoSort(int array[], int size) {
	clock_t start, end;
    start = clock();

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
            random_shuffle(&array[0], &array[size]);
            printArray(array, size);
            reshuffleCount++;
            cout << endl;
        }
    }

	end = clock();
    
    cout << "  Final array: ";
    printArray(array, size);
	cout << endl << "  It took " << reshuffleCount << " reshuffels to complete." << endl;
    cout << endl << "  Time to complete " << (end - start) / (double)CLOCKS_PER_SEC << " seconds." << endl << endl;
}


/*
 * Quick Sort - initial call
 */
void quickSort(int unsorted[], int right) {
    clock_t start, end;
    start = clock();

    cout << endl << "  Quick Sort" << endl;
    cout << "  --------------" << endl;
    cout << "  original array: ";
    printArray(unsorted, right+1);
    cout << endl << endl;

    cout << "    First call to quickSort." << endl;
	//rule 1
	int left = 0;
	int pivot = unsorted[left];
	int L = left;
	int R = right;
	
	cout << "    set pivot = " << pivot << endl;
	cout << "    set left = " << left << endl;
	cout << "    set right = " << right << endl << endl;

	//rule 6
	while (left < right) {
	
		//rule 2
		while ((pivot <= unsorted[right]) && (left < right)) {
			cout << "    Compare pivot to array[right]: " ;
			cout << pivot << " is less than " << unsorted[right] << ", decrement right to " << right-1 << endl;
			right--;
		}

		//rule 3
		if (pivot > unsorted[right]) {
			cout << "    Compare pivot to array[right]: ";
			cout << pivot << " is greater than " << unsorted[right];
			cout << " copy " << unsorted[right] << " over " << unsorted[left];
			unsorted[left] = unsorted[right];
			left++;
			cout << ", increment left to " << left << endl;
		}

		//rule 4
		while ((pivot >= unsorted[left]) && (left < right)) {
			cout << "    Compare pivot to array[left]: " ;
			cout << pivot << " is greater than " << unsorted[left] << ", increment left to " << left+1 << endl;
			left++;
		}

		//rule 5
		if (pivot < unsorted[left]) {
		    cout << "    Compare pivot to array[left]: ";
			cout << pivot << " is less than " << unsorted[left];
			cout << " copy " << unsorted[left] << " over " << unsorted[right];
			unsorted[right] = unsorted[left];
			right--;
			cout << ", decrement right to " << right << endl;
		}
	}
    
    cout << "    No numbers left for comparison, copy pivot to array[left]." << endl;
    cout << "    Number less than " << pivot << " are before element " << left;
    cout << " and numbers greater than " << pivot << " are after." << endl;
	unsorted[left] = pivot;
	
	
	cout << "    Array at end of this call: ";
    printArray(unsorted, R+1);
    cout << endl;

	//rule 7
	if (L < right - 1) {
		quickSort(unsorted, right - 1, L);
	}

	if (left + 1 < R) {
		quickSort(unsorted, R, left + 1);
	}
	
    end = clock();
    
    cout << endl << "  Final array: ";
    printArray(unsorted, R+1);
    cout << endl << "  Time to complete " << (end - start) / (double)CLOCKS_PER_SEC << " seconds." << endl << endl;

}


/*
 * Quick Sort - recursive calls, this is done for the pretty output. int left
 * could have just been an optional argument set to 0.
 */
void quickSort(int unsorted[], int right, int left) {
    cout << endl;
    cout << "    Recursive quickSort call on: ";
    printArray(unsorted, right+1, left);
    cout << endl;

	//rule 1
	int pivot = unsorted[left];
	int L = left;
	int R = right;
	
	cout << "    set pivot = " << pivot << endl;
	cout << "    set left = " << left << endl;
	cout << "    set right = " << right << endl;

	//rule 6
	while (left < right) {
	
		//rule 2
		while ((pivot <= unsorted[right]) && (left < right)) {
			cout << "    Compare pivot to array[right]: " ;
			cout << pivot << " is less than " << unsorted[right] << ", decrement right to " << right-1 << endl;
			right--;
		}

		//rule 3
		if (pivot > unsorted[right]) {
			cout << "    Compare pivot to array[right]: ";
			cout << pivot << " is greater than " << unsorted[right];
			cout << " copy " << unsorted[right] << " over " << unsorted[left];
			unsorted[left] = unsorted[right];
			left++;
			cout << ", increment left to " << left << endl;
		}

		//rule 4
		while ((pivot >= unsorted[left]) && (left < right)) {
			cout << "    Compare pivot to array[left]: " ;
			cout << pivot << " is greater than " << unsorted[left] << ", increment left to " << left+1 << endl;
			left++;
		}

		//rule 5
		if (pivot < unsorted[left]) {
		    cout << "    Compare pivot to array[left]: ";
			cout << pivot << " is less than " << unsorted[left];
			cout << " copy " << unsorted[left] << " over " << unsorted[right];
			unsorted[right] = unsorted[left];
			right--;
			cout << ", decrement right to " << right << endl;
		}
	}
    
    cout << "    No numbers left for comparison, copy pivot to array[left]." << endl;
    cout << "    Number less than " << pivot << " are before element " << left;
    cout << " and numbers greater than " << pivot << " are after." << endl;
	unsorted[left] = pivot;
	
	
	cout << "    Array at end of this call: ";
    printArray(unsorted, R+1);
    cout << endl;

	//rule 7
	if (L < right - 1) {
		quickSort(unsorted, right - 1, L);
	}

	if (left + 1 < R) {
		quickSort(unsorted, R, left + 1);
	}

}









































