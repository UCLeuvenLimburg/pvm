# Assignment

Imagine we are writing a Sudoku solver.
For each square, we keep track of which numbers could belong there.
Initially, these sets contain all numbers from 1 to 9.
Solving the puzzle consists of eliminating numbers from these
sets until only one remains for each square.

We need an efficient way of representing these sets.
For this exercise, we decide to represent such sets
as single `uint32_t` values. Each bit corresponds to a number:
if a number is present in the set, the bit is set to `1`, otherwise
it is `0`. Below, we show a few examples of how sets are represented by bits:

| Integer | Set |
|-|-|
|`0b0000'0000`| {} |
|`0b0000'0001`| { 0 } |
|`0b0000'0010`| { 1 } |
|`0b0000'0100`| { 2 } |
|`0b0000'1000`| { 3 } |
|`0b0001'0000`| { 4 } |
|`0b0010'0000`| { 5 } |
|`0b0100'0000`| { 6 } |
|`0b1000'0000`| { 7 } |
|`0b0000'0011`| { 0, 1 } |
|`0b0000'0101`| { 0, 2 } |

In other words, the rightmost bit represents whether `0` is an element of the set,
the 2nd rightmost bit correponds to `1`, etc. Using `uint32_t`, it is only possible
to represent sets that contain numbers ranging from `0` to `31`, which is more than sufficient
for our Sudoku solver.

## Task

Write a class `NumberSet` which models a set of numbers as a `uint32_t`.
The following member functions need to be provided:

```c++
// Create empty set
NumberSet set;

// Add 5 to set
// Adding a number that is already a member has no effect
set.add(5);

// Check if set contains 5
set.contains(5);

// Remove 5 from set
// Removing a non-member has no effect
set.remove(5);

// Intersection
set.intersection(other_set);
// set now contains the intersection of set and other_set

// Union
set.union_with(other_set);
// set now contains the union of set and other_set

// Number of elements in the set
set.size();
```
