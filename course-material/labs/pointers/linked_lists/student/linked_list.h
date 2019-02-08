#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct linked_list
{
    int value;
    linked_list* next;
};

unsigned length(linked_list*);
linked_list* penultimate(linked_list*);
linked_list* longest(linked_list*, linked_list*);
void make_cyclic(linked_list*);
bool has_cycle(linked_list*);

#endif
