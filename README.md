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

    g++ main.cpp array_functions.cpp search_functions.cpp sort_functions.cpp -o test.exe


Visual Studios
--------------
Copy and paste is what I do.


Compileing with g++ timing the sort functions becomes useless, they're all 0. On
the other hand, compiling in Visual Studios will give a result in seconds
(fractions of seconds in most cases) even with the default of only 4 elements. 
Aparently Visual Studios takes a long time to cout.


Example Output
==============
Searches
--------
`
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


  Interpolation Search
  --------------------
  Searching for 4 in {1, 2, 3, 4, 5}.

    Set left to 0.
    Set right to 4.
    Calculate middle: 0 + ((4 - 1) * (4 - 0) / (5 - 1)) = 3
    Found 4 in position 3!
    Search took 1 comparisons.
`
