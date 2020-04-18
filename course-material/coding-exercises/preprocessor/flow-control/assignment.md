# Assignment

The `if`, `while` and `for` are examples of flow control statements.
Using macros, we can introduce our own.

## `UNLESS`

Define `UNLESS(cond) { body }` so that `body` is executed only if `cond` is `false`.

```c++
UNLESS ( after_midnight() )
{
    feed_mogwai();
}
```

## `REPEAT`

Define `REPEAT { body }` that endlessly repeats `body`.

```c++
REPEAT
{
    receive_http_request();
    respond_to_request();
}
```

## `UNTIL`

Define `UNTIL (cond) { body }` so that `body` gets repeated until `cond` is `true`.

```c++
UNTIL ( end_of_file_reached() )
{
    process_next_line();
}
```
