Description
===========
Reviewing some computer science basics.

This is for fun, comment out lines and edit variables or calls in `main.cpp` to 
get different results. Be careful with Bogosort, anything more than a few
elements can get out of hand.

Compile
=======
Because I'll forget how...

GNU
---

    g++ main.cpp array_functions.cpp llll.cpp search_functions.cpp sort_functions.cpp -o test.exe


Visual Studios
--------------
Copy and paste is what I do.


Compileing with g++ timing the sort functions becomes useless, they're all 0. On
the other hand, compiling in Visual Studios will give a result in seconds
(fractions of seconds in most cases) even with the default of only 4 elements. 
Aparently Visual Studios takes a long time to cout.


Example Output
==============
Sorts
-----

### Buble Sort
    Bubble Sort
    -----------
    Unsorted array: {67, 64, 19, 2}
  
    Pass 1
      Sorted so far: {}
  
      Check position 0 against position 1.
      67 is greater than 64 so swap. --> {64, 67, 19, 2}
  
      Check position 1 against position 2.
      67 is greater than 19 so swap. --> {64, 19, 67, 2}
  
      Check position 2 against position 3.
      67 is greater than 2 so swap. --> {64, 19, 2, 67}
  
    Pass 2
      Sorted so far: {67}
  
      Check position 0 against position 1.
      64 is greater than 19 so swap. --> {19, 64, 2, 67}
  
      Check position 1 against position 2.
      64 is greater than 2 so swap. --> {19, 2, 64, 67}
  
    Pass 3
      Sorted so far: {64, 67}
  
      Check position 0 against position 1.
      19 is greater than 2 so swap. --> {2, 19, 64, 67}
  
    Final array: {2, 19, 64, 67}
    Time to complete 0 seconds.


###Selection Sort
    Selection Sort
    --------------
    Unsorted array: {67, 64, 19, 2}
  
    Pass 1
      Sorted so far: {}
  
      Check position 0 against position 1
      64 is greater than 67 so swap. --> {64, 67, 19, 2}
  
      Check position 0 against position 2
      19 is greater than 64 so swap. --> {19, 67, 64, 2}
  
      Check position 0 against position 3
      2 is greater than 19 so swap. --> {2, 67, 64, 19}
  
    Pass 2
      Sorted so far: {19}
  
      Check position 1 against position 2
      64 is greater than 67 so swap. --> {2, 64, 67, 19}
  
      Check position 1 against position 3
      19 is greater than 64 so swap. --> {2, 19, 67, 64}
  
    Pass 3
      Sorted so far: {67, 64}
  
      Check position 2 against position 3
      64 is greater than 67 so swap. --> {2, 19, 64, 67}
  
    Final array: {2, 19, 64, 67}
    Time to complete 0 seconds.
  

### Insertion Sort
    Insertion Sort
    --------------
    Unsorted array: {67, 64, 19, 2}
  
    Pass 1
      Sorted so far: {67}
      Assign array position 1 to temporary variable (temp = 64).
  
      Compare temp against position 0.
      It's lower so copy position 0 right --> {67, 67}
      Insert 64 into position 0 --> {64, 67}
  
    Pass 2
      Sorted so far: {64, 67}
      Assign array position 2 to temporary variable (temp = 19).
  
      Compare temp against position 1.
      It's lower so copy position 1 right --> {64, 67, 67}
  
      Compare temp against position 0.
      It's lower so copy position 0 right --> {64, 64, 67}
      Insert 19 into position 0 --> {19, 64, 67}
  
    Pass 3
      Sorted so far: {19, 64, 67}
      Assign array position 3 to temporary variable (temp = 2).
  
      Compare temp against position 2.
      It's lower so copy position 2 right --> {19, 64, 67, 67}
  
      Compare temp against position 1.
      It's lower so copy position 1 right --> {19, 64, 64, 67}
  
      Compare temp against position 0.
      It's lower so copy position 0 right --> {19, 19, 64, 67}
      Insert 2 into position 0 --> {2, 19, 64, 67}
  
    Final array: {2, 19, 64, 67}
    Time to complete 0 seconds.
    

### Bogosort
    Bogosort
    --------
      Unsorted array = {42, 82, 94, 91}
      Checking position 0: 42 is lower than 82, continue.
      Checking position 1: 82 is lower than 94, continue.
      Checking position 2: 94 is not lower than 94, start over.
  
      Reshuffled array = {42, 94, 82, 91}
      Checking position 0: 42 is lower than 94, continue.
      Checking position 1: 94 is not lower than 82, start over.
  
      Reshuffled array = {42, 82, 91, 94}
      Checking position 0: 42 is lower than 82, continue.
      Checking position 1: 82 is lower than 91, continue.
      Checking position 2: 91 is lower than 94, continue.
      
    Final array: {42, 82, 91, 94}
    It took 2 reshuffles to complete.
    Time to complete 0 seconds.


### Quick Sort
    Quick Sort
    --------------
    Unsorted array: {1, 95, 89, 36}
  
      First call to quickSort.
      Set pivot = 1
      Set left = 0
      Set right = 3
  
      Compare pivot to array[right]: 1 is less than 36, decrement right to 2
      Compare pivot to array[right]: 1 is less than 89, decrement right to 1
      Compare pivot to array[right]: 1 is less than 95, decrement right to 0
      No numbers left for comparison, copy pivot to array[left].
      Number less than 1 are before element 0 and numbers greater than 1 are after.
      Array at end of this call: {1, 95, 89, 36}
  
      Recursive quickSort call on: {95, 89, 36}
      Set pivot = 95
      Set left = 1
      Set right = 3
      Compare pivot to array[right]: 95 is greater than 36 copy 36 over 95, increment left to 2
      Compare pivot to array[left]: 95 is greater than 89, increment left to 3
      No numbers left for comparison, copy pivot to array[left].
      Number less than 95 are before element 3 and numbers greater than 95 are after.
      Array at end of this call: {1, 36, 89, 95}
  
      Recursive quickSort call on: {36, 89}
      Set pivot = 36
      Set left = 1
      Set right = 2
      Compare pivot to array[right]: 36 is less than 89, decrement right to 1
      No numbers left for comparison, copy pivot to array[left].
      Number less than 36 are before element 1 and numbers greater than 36 are after.
      Array at end of this call: {1, 36, 89}
  
    Final array: {1, 36, 89, 95}
    Time to complete 0 seconds.


### Merge Sort
    Merge Sort
    --------------
    Unsorted array: {21, 26, 51, 70}
  
      Left:  0
      Right: 3
      Calculate middle: 1
  
    Calling Merge Sort
      Passed array: {21, 26}
      Left:  0
      Right: 1
      Calculate middle: 0
  
  
    Calling Merge Sort
      Passed array: {21}
      Left:  0
      Right: 0
  
    Calling Merge Sort
      Passed array: {21, 26}
      Left:  1
      Right: 1
  
    Calling Merge
      Copy 21 to element 0 in backup array.
      Incrementing i to 0.
      Incrementing k to 1.
      One array was longer, finish adding it to the backup array.
      Copy 26 to element 1 in backup array.
      Incrementing j to 2.
      Incrementing k to 2.
  
    Calling Merge Sort
      Passed array: {21, 26, 51, 70}
      Left:  2
      Right: 3
      Calculate middle: 2
  
  
    Calling Merge Sort
      Passed array: {21, 26, 51}
      Left:  2
      Right: 2
  
    Calling Merge Sort
      Passed array: {21, 26, 51, 70}
      Left:  3
      Right: 3
  
    Calling Merge
      Copy 51 to element 2 in backup array.
      Incrementing i to 2.
      Incrementing k to 3.
      One array was longer, finish adding it to the backup array.
      Copy 70 to element 3 in backup array.
      Incrementing j to 4.
      Incrementing k to 4.
  
    Calling Merge
      Copy 21 to element 0 in backup array.
      Incrementing i to 0.
      Incrementing k to 1.
      Copy 26 to element 1 in backup array.
      Incrementing i to 1.
      Incrementing k to 2.
      One array was longer, finish adding it to the backup array.
      Copy 51 to element 2 in backup array.
      Incrementing j to 3.
      Incrementing k to 3.
      One array was longer, finish adding it to the backup array.
      Copy 70 to element 3 in backup array.
      Incrementing j to 4.
      Incrementing k to 4.
  
    Final array: {21, 26, 51, 70}
    Time to complete 0 seconds.



Searches
--------

### Brute Force Search
    Brute Force Search
    ------------------
    Searching for 4 in {1, 2, 3, 4, 5}.
  
      Compare value of position 0 in array with 4.
      They are not equal, keep searching.
  
      Compare value of position 1 in array with 4.
      They are not equal, keep searching.
  
      Compare value of position 2 in array with 4.
      They are not equal, keep searching.
  
      Compare value of position 3 in array with 4.
      Found 4 at position 3!
      Search took 4 comparisons.
  

### Binary Search
    Binary Search
    -------------
    Searching for 4 in {1, 2, 3, 4, 5}.
  
      Set left to 0.
      Set right to 4.
      Calculate middle: (0 + 4) / 2 = 2
      4 is greater than 3, keep searching
  
      Set left to 3.
      Set right to 4.
      Calculate middle: (3 + 4) / 2 = 3
      Found 4 in position 3!
      Search took 2 comparisons.
  

### Interpolation Search
    Interpolation Search
    --------------------
    Searching for 4 in {1, 2, 3, 4, 5}.
  
      Set left to 0.
      Set right to 4.
      Calculate middle: 0 + ((4 - 1) * (4 - 0) / (5 - 1)) = 3
      Found 4 in position 3!
      Search took 1 comparisons.

