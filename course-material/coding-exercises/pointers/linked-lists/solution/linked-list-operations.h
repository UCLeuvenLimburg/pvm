#ifndef LINKED_LIST_OPERATIONS_H
#define LINKED_LIST_OPERATIONS_H

#include "linked-list.h"


int nth_value(linked_list* first, int index);
unsigned length(linked_list* first);
int sum(linked_list* first);
linked_list* last(linked_list* first);
linked_list* penultimate(linked_list* first);
void zero(linked_list* first);
void cumulative(linked_list* first);
bool equal(linked_list* xs, linked_list* ys);

#endif
