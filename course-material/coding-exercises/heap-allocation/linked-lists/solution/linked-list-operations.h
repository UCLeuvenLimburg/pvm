#ifndef LINKED_LIST_OPERATIONS_H
#define LINKED_LIST_OPERATIONS_H

#include "linked-list.h"


linked_list* range(int a, int b);
linked_list* copy_list(linked_list* start);
void prepend(linked_list** start, int value);
void append(linked_list** start, int value);

#endif
