# Endianness

Determine the [https://en.wikipedia.org/wiki/Endianness](endianness) of your machine by performing the following test in code:

* Allocate a multibyte integer value (e.g. an `uint32_t`).
* [Reinterpret](https://en.cppreference.com/w/cpp/language/reinterpret_cast) it as an array of `uint8_t`s.
* Check the order of the bytes.

If the least significant digit comes first, your machine is little endian, otherwise big endian.

Write functions with signatures

```c++
bool is_big_endian();
bool is_little_endian();
```

that check your machine's endianness.
