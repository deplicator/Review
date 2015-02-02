#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "headers/array_functions.h"
#include "headers/sort_functions.h"

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
    cout << "  Unsorted array: ";
    printArray(array, size);
    cout << endl << endl;
    
    for (int i = size; i > 1; i--) {
        cout << "  Pass " << size - i + 1 << endl << "    Sorted so far: ";
        printArray(array, size, i);
        cout << endl << endl;
        for (int j = 0; j < (i - 1); j++) {
            cout << "    Check position " << j << " against position " << j + 1 << "." << endl;
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
    cout << "  Unsorted array: ";
    printArray(array, size);
    cout << endl << endl;
    
    for (int i = 0; i < (size - 1); i++) {
        cout << "  Pass " << i + 1 << endl << "    Sorted so far: ";
        printArray(array, size, size - i);
        cout << endl << endl;
        
        for (int j = (i + 1); j < size; j++) {
            cout << "    Check position " << i << " against position " << j << endl;
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
void insertionSort(int list[], int size) {
	clock_t start, end;
    start = clock();

    cout << endl << "  Insertion Sort" << endl;
    cout << "  --------------" << endl;
    cout << "  Unsorted array: ";
    printArray(list, size);
    cout << endl << endl;
    
    int temp, j;
    for (int i = 1; i < size; i++) {
        temp = list[i];
        cout << "  Pass " << i << endl <<"    Sorted so far: ";
        printArray(list, i);
        cout << endl << "    Assign array position " << i 
             << " to temporary variable (temp = " << temp << ")." << endl;
        
        int behindFlag; //Only used for pretty output.
        for (j = (i - 1); j >= 0; j--) {
            behindFlag = 0;
            cout << endl << "    Compare temp against position " << j << "." << endl;
            if (temp < list[j]) {
                list[j + 1] = list[j];
                cout << "    It's lower so copy position " << j << " right --> ";
                printArray(list, i + 1);
                cout << endl;
            } else {
                cout << "    It's higher so insert behind --> ";
                behindFlag = 1;
                break;
            }
        }
        list[j + 1] = temp;
        
        if(behindFlag) {
            printArray(list, i + 1);
            cout << endl << endl;
        } else {
            cout << "    Insert " << temp << " into position " << j + 1 << " --> ";
            printArray(list, i + 1);
            cout << endl << endl;
        }
    }

    end = clock();

    cout << "  Final array: ";
    printArray(list, size);
    cout << endl << "  Time to complete " << ((float)end - start) / CLOCKS_PER_SEC << " seconds." << endl << endl;
}


/*
 * Bogosort
 * http://en.wikipedia.org/wiki/Bogosort
 */
void bogoSort(int unsorted[], int size) {
	clock_t start, end;
    start = clock();

    cout << endl << "  Bogosort" << endl;
    cout << "  --------" << endl;
    cout << "    Unsorted array = ";
    printArray(unsorted, size);
    cout << endl;
    int count = 0;
    int reshuffleCount = 0;
    while(count < size-1) {
        cout << "    Checking position " << count << ": " << unsorted[count];

        if (unsorted[count] < unsorted[count + 1] || unsorted[count] == unsorted[count + 1] ) {
            cout << " is lower than " << unsorted[count + 1] << ", continue."<< endl;
            count++;
        } else {
            count = 0;
            cout << " is not lower than " << unsorted[count + 2] << ", start over." << endl << endl;
            cout << "    Reshuffled array = ";
            random_shuffle(&unsorted[0], &unsorted[size]);
            printArray(unsorted, size);
            reshuffleCount++;
            cout << endl;
        }
    }

	end = clock();
    
    cout << endl << "  Final array: ";
    printArray(unsorted, size);
	cout << endl << "  It took " << reshuffleCount << " reshuffles to complete.";
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
    cout << "  Unsorted array: ";
    printArray(unsorted, right+1);
    cout << endl << endl;

    cout << "    First call to quickSort." << endl;
	//rule 1
	int left = 0;
	int pivot = unsorted[left];
	int L = left;
	int R = right;
	
	cout << "    Set pivot = " << pivot << endl;
	cout << "    Set left = " << left << endl;
	cout << "    Set right = " << right << endl << endl;

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
	
	cout << "    Set pivot = " << pivot << endl;
	cout << "    Set left = " << left << endl;
	cout << "    Set right = " << right << endl;

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
 * Merge Sort - initial call
 */
void mergeSort(int unsorted[], int right) {
    clock_t start, end;
    start = clock();

    int Backup[right+1];
    int left = 0;
    
    cout << endl << "  Merge Sort" << endl;
    cout << "  --------------" << endl;
    cout << "  Unsorted array: ";
    printArray(unsorted, right+1);
    cout << endl << endl;
    
    
	cout << "    Left:  " << left << endl;
	cout << "    Right: " << right << endl;
	
	if(left < right) {
		int middle = (left + right) / 2;
		cout << "    Calculate middle: " << middle << endl;
		mergeSort(unsorted, Backup, left, middle);
		mergeSort(unsorted, Backup, middle + 1, right);
		merge(unsorted, Backup, left, middle, right);
	}
	
	end = clock();
    
    cout << endl << "  Final array: ";
    printArray(unsorted, right+1);
    cout << endl << "  Time to complete " << (end - start) / (double)CLOCKS_PER_SEC << " seconds." << endl << endl;
}


/*
 * Merge Sort - recursive calls
 */
void mergeSort(int A[], int B[], int left, int right) {
    cout << endl << "  Calling Merge Sort" << endl;
    cout << "    Passed array: ";
    printArray(A, right+1);
    cout << endl;
    
	cout << "    Left:  " << left << endl;
	cout << "    Right: " << right << endl;
	
	if(left < right) {
		int middle = (left + right) / 2;
		cout << "    Calculate middle: " << middle << endl << endl;
		mergeSort(A, B, left, middle);
		mergeSort(A, B, middle + 1, right);
		merge(A, B, left, middle, right);
	}
}


/*
 * Merge, function used by Merge Sort.
 */
void merge(int A[], int B[], int left, int middle, int right) {
	cout << endl << "  Calling Merge" << endl;
	int i = left;
	int j = middle + 1;
	int k = left;

	while(i <= middle && j <= right) {
		if(A[i] < A[j]) {
			B[k] = A[i];
			cout << "    Copy " << A[i] << " to element " << k << " in backup array." << endl;
			cout << "    Incrementing i to " << i << "." << endl;
			i++;
		} else {
			B[k] = A[j];
			cout << "    Copy " << A[j] << " to element " << k << " in backup array." << endl;
			cout << "    Incrementing j to " << j << "." << endl;
			j++;
		}
		k++;
		cout << "    Incrementing k to " << k << "." << endl;
	}
	while(i <= middle) {
		cout << "    One array was longer, finish adding it to the backup array." << endl;
		B[k] = A[i];
		cout << "    Copy " << A[i] << " to element " << k << " in backup array." << endl;
		i++;
		cout << "    Incrementing i to " << i << "." << endl;
		k++;
		cout << "    Incrementing k to " << k << "." << endl;
	}
	while(j <= right) {
		cout << "    One array was longer, finish adding it to the backup array." << endl;
		B[k] = A[j];
		cout << "    Copy " << A[j] << " to element " << k << " in backup array." << endl;
		j++;
		cout << "    Incrementing j to " << j << "." << endl;
		k++;
		cout << "    Incrementing k to " << k << "." << endl;
	}

	for(int i = left; i<= right; i++) {
		A[i] = B[i];
	}
}

