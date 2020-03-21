# Assignment

Write a function with signature

```c++
int lone_wolf(int* ns, unsigned size);
```

* `ns` points to the first element of an array.
* `size` represents the number of elements in the array.

All elements in `ns` occur in pairs, except for one, the lone wolf.
For example, take `[1, 2, 3, 1, 2]`: `1` and `2` occur twice,
but `3` has no "twin".

`lone_wolf` must return this unpaired element.
