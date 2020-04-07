# Assignment

## Structs

You are given a struct named `linked_list`:

```c++
struct linked_list
{
    int value;
    linked_list* next;
};
```

You can interpret this struct as a class definition where all members are public.
We can create a `linked_list` object as follows

```c++
// creates object on stack
linked_list a, b;

a.value = 1;
a.next  = &b;
b.value = 2;
b.next  = nullptr;
```

This creates a linked list containing two nodes `a` and `b`.
The first node's `value` is `1`, the second node's `value` is `2`.
The end of the list is represented by `nullptr`.

If you have a pointer to a `linked_list`, you can access its fields in two ways:

```c++
linked_list* p;

int value1 = (*p).value;
int value2 = p->value;
```

In other words, `p->x` can be seen as a shorthand notation for `(*p).x`.

## Task

You are tasked with writing the following functions that operate on `linked_list`s:

* `nth_value(p, n)` returns the `n`th value in the list pointed to by `p`.
* `length(p)` returns the number of elements in the list pointed to by `p`.
* `sum(p)` returns the sum of the `value`s in the list pointed to be `p`.
* `last(p)` returns a pointer to the last node in the list.
* `penultimate(p)` returns a pointer to the penultimate (next to last) node in the list.
* `zero(p)` overwrites all values in the list with `0`s.
* `cumulative(p)` overwrites all values in the list with the sum of the values up until then. Look at the tests for examples.
* `equal(p, q)` checks whether the two given lists are equal.
