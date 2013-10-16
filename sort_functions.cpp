#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "array_functions.h"
#include "sort_functions.h"

using namespace std;


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



/*
 * Merge Sort
 */
void mergeSort(int A[], int B[], int left, int right) {
	cout << "calling Merge Sort with left " << left << " and right " << right << "." << endl;
	if(left < right) {
		int middle = (left + right) / 2;
		cout << "find middle: " << middle << endl;
		mergeSort(A, B, left, middle);
		mergeSort(A, B, middle + 1, right);
		merge(A, B, left, middle, right);
	}
}

/*
 * Merge, function used by Merge Sort.
 */
void merge(int A[], int B[], int left, int middle, int right) {
	cout << "calling Merge" << endl;
	int i = left;
	int j = middle + 1;
	int k = left;

	while(i <= middle && j <= right) {
		if(A[i] < A[j]) {
			B[k] = A[i];
			cout << "copy " << A[i] << " to element " << k << " in backup array." << endl;
			cout << "incrementing i to " << i << endl;
			i++;
		} else {
			B[k] = A[j];
			cout << "copy " << A[j] << " to element " << k << " in backup array." << endl;
			cout << "incrementing j to " << j << endl;
			j++;
		}
		k++;
		cout << "incrementing k to " << k << endl;
	}
	while(i <= middle) {
		cout << "One array was longer, finish adding it to the backup array." << endl;
		B[k] = A[i];
		cout << "copy " << A[i] << " to element " << k << " in backup array." << endl;
		i++;
		cout << "incrementing i to " << i << endl;
		k++;
		cout << "incrementing k to " << k << endl;
	}
	while(j <= right) {
		cout << "One array was longer, finish adding it to the backup array." << endl;
		B[k] = A[j];
		cout << "copy " << A[j] << " to element " << k << " in backup array." << endl;
		j++;
		cout << "incrementing j to " << j << endl;
		k++;
		cout << "incrementing k to " << k << endl;
	}

	for(int i = left; i<= right; i++) {
		A[i] = B[i];
	}
}

