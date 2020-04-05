# Assignment

You are given a hierarchy of `Shape` classes as well as an enum `tag` in `shapes.h`.

An enum allows you to define a type which has a fixed set of possible values.
For example, `bool` could have been defined as an enum:

```c++
enum class bool
{
    false,
    true
}

bool x = bool::true;
```

Say the `Shape` hierarchy has not been written by you and cannot be modified.
However, you need an easy way to determine, given a `Shape` object,
which actual shape (rectangle, square, ellipse or circle) it is.

```c++
void foo(const Shape& shape)
{
    switch (get_tag(shape))
    {
    case tag::circle:
        ...
    case tag::ellipse:
        ...
    case tag::rectangle:
        ...
    case tag::square:
        ...
    }
}
```

Write a function with signature

```c++
tag get_tag(const Shape& shape);
```

that determines the dynamic type of `shape` and returns the corresponding `tag` value.

Hint: [Dynamic cast](https://en.cppreference.com/w/cpp/language/dynamic_cast).
