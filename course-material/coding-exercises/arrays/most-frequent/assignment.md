# Assignment

Write a function with signature

```c++
int most_frequent(int* ns, unsigned size);
```

* `ns` points to the first element of an array. This array contains numbers ranging from 0 to 100.
* `size` represents the number of elements in this array.

`most_frequent` should return the element which occurs most often in the array.
You can assume the array contains at least one element and that
there is only one most frequent element.

## Hints

* First, count the frequency of each element in the array. The easiest
  way is to create an array `freqs` initially filled with 0's. For each value `n` in `ns`,
  you increment `freqs[n]`.
* Once you got the frequencies, it shouldn't be too hard to find
  the element with the greatest frequency.
