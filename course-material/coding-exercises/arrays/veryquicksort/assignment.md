# Assignment

Write a function with signature

```c++
void veryquicksort(int* ns, unsigned size);
```

* `ns` points to an array of single digit numbers, i.e. they range from 0 to 9.
* `size` is the number of elements in this array.

`veryquicksort` must overwrite `ns` so that it contains the same
values but in increasing order. Perform the sort as follows:

* First, allocate an array of 10 elements. Since this array will only be used locally (i.e. it will not be returned)
  and its size is known at compile time, it is best to allocate this array on the stack. This is more efficient
  and you don't risk a memory leak. Call this array `frequencies`.
* Fill `frequencies` with zeros.
* Count each element in `ns` and store the results in `frequencies`. For example, if
  `ns` contains 5 twice, then `frequencies[5]` should equal `2`.
* Next, overwrite `ns` with the values in increasing order.
  * Read `frequencies[0]` and add that many `0`'s to `ns`.
  * Read `frequencies[1]` and add that many `1`'s to `ns`.
  * And so on for `2`, `3`, ..., `9`.
