# Assignment

Write a function with signature

```c++
uint8_t extract_byte(uint64_t n, unsigned k);
```

* `n` is an integer 8 bytes long
* `k` is a number ranging from 0 to 7.

`extract_byte` should return the `k`th byte from `n`.
The zeroth byte is the leftmost one.
