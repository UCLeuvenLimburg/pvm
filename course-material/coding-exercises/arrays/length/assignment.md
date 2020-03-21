# Assignment

Write a function with signature

```c++
unsigned length(int* start, int* end);
```

* `start` points to the first element of an array.
* `end` points to **one past** the last element of the same array.

Given that you know where the array starts and where it ends, it is
possible to compute the number of elements in it.

## Hints

* You can rely on [pointer arithmetic](https://lmgtfy.com/?q=c%2B%2B+pointer+subtraction).
* You can iterate over the array (`start[i]`) and go on until you find an element whose address equals `end`.
