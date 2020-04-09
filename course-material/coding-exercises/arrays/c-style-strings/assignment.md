# Assignment

A string is in essence nothing more than an array of `char`s.
In C, that's also how strings were actually represented, i.e. as `char*`.

Now, a pointer does not convey information about the length of the array it points to.
This problem was solved by having the array end with a `'\0'` character, i.e., an actual `0` value (**not** the digit 0).
This is known a (https://en.wikipedia.org/wiki/Null-terminated_string)[*null-terminated string*].

This has many consequences, among which

* No string can contain the `'\0'` character. This is no big deal since `'\0'` is not mapped to any interesting character by ASCII.
* Determining the length of a string consists of going through it until a `'\0'` is encountered.

Write the following functions that operate on C-style strings:

* `length(string)` returns the length of the string. This does not include the null terminator.
* `overwrite(destination, source)` copies the `source` string into the `destination` string. Note that this is quite a risky operation: ask yourself the question what happens if `source` has a greater length than `destination`.
* `concatenate(s1, s2)` returns a new string which is the concatenation of both given strings.
* `reverse(string)` reverses the string in place.
* `parse(string)` parses an unsigned integer in decimal notation.
