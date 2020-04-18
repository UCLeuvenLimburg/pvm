# Assignment

Write a function with signature

```c++
void split(int* ns, unsigned size, int** odds, unsigned* n_odds, int** evens, unsigned* n_evens);
```

The goal of this function is to separate the odd and even values into separate arrays.

Parameters:

* `ns` points to the start of an array.
* `size` contains the number of elements in this array.
* `odds` is an output parameter that must receive a pointer to the array of odd elements.
* `n_odds` is an output parameter that points to a variable to which you must write the number of odd elements.
* `evens` is an output parameter tha tmust receive a pointer to the array of even elements.
* `n_evens` is an output parameter that points to a variable to which you must write the number of even elements.

## Hints

* You will need to create two new arrays, to host the odd and even numbers respectively.
  In order to create an array, you need to know its size. So, in a first step,
  you will need to count the number of odd and even numbers in `ns` and store
  them in `n_odds` and `n_evens`. only
  then will you be able to create the arrays `odds` and `evens`.
* Once you have created the `odds` and `evens` arrays,
  you can start filling them with odd and even values, respectively.
