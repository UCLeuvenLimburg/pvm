# Assignment

This exercise is more of a puzzle/challenge.
It will require you to experiment and look online for information.
By solving this puzzle, you will learn about the peculiarities of the preprocessor.

Know that it is possible to ask for the [output of the preprocessor](https://lmgtfy.com/?q=msvc+preprocessor+output).
This allows you to find out what your macros are translated to and can be very helpful while trying to solve this exercise.

We want `REPEAT_N(N) { body }` to execute `body` `N` times. That's all.

However, you might run into some troubles when the `REPEAT_N` macro is used multiple times in the same function.
In such cases, you will need to [generate unique variable names](https://lmgtfy.com/?q=c%2B%2B+macro+generate+unique+identifier).

You shouldn't make use of libraries (e.g., Boost) to solve this exercise.
