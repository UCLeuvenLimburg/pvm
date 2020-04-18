# Assignment

Write the following functions operating on `linked_list`s:

* `range(a, b)` should return a new `linked_list` containing the values from `a` until `b` (exclusive).
* `copy_list(list)` should return a copy of the list.
* `prepend(&list, value)` should add an extra value to the front of the list.
* `append(&list, value)` should add an extra value at the back of the list.

## `prepend`

The first parameter of this function is `linked_list**`
This is due to the fact that a list is represented by a pointer to its first node.
`prepend` adds a new node at the front of the list, meaning there is a new first node.
The first parameter is used as both an input and an output parameter:

* Input: it provides `prepend` with a pointer to the first node.
* Output: it's overwritten thereby giving the caller access to the new first node.

An alternative would've been to simply return a pointer to the new first node, but well, you know me.

```c++
linked_list xs; // {1, 2, 3}
prepend(&xs, 0);
// xs == {0, 1, 2, 3}
```

## `append`

Like `prepend`, the first parameter is used both for input and output.
Since `append` is supposed to simply add a new node at the end of the list, one might not expect to need output: the list keeps the same first node, so there is no need for an updated pointer.

However, consider the case where the linked list is empty.
In this case, there is no first node, and `append`ing creates a first node.
Hence the need to be able to update the pointer.
In other words, the first parameter will only need to be overwritten if it's initially `nullptr`.
