#include "linked-list-operations.h"


int nth_value(linked_list* first, int index)
{
    linked_list* current = first;

    for (unsigned i = 0; i != index; ++i)
    {
        current = current->next;
    }

    return current->value;
}

unsigned length(linked_list* first)
{
    unsigned count = 0;
    linked_list* current = first;

    while (current != nullptr)
    {
        ++count;
        current = current->next;
    }

    return count;
}

int sum(linked_list* first)
{
    int total = 0;
    linked_list* current = first;

    while (current != nullptr)
    {
        total += current->value;
        current = current->next;
    }

    return total;
}

linked_list* last(linked_list* first)
{
    linked_list* last = nullptr;
    linked_list* current = first;

    while (current != nullptr)
    {
        last = current;
        current = current->next;
    }

    return last;
}

linked_list* penultimate(linked_list* first)
{
    linked_list* penultimate = nullptr;
    linked_list* last = nullptr;
    linked_list* current = first;

    while (current != nullptr)
    {
        penultimate = last;
        last = current;
        current = current->next;
    }

    return penultimate;
}

void zero(linked_list* first)
{
    linked_list* current = first;

    while (current != nullptr)
    {
        current->value = 0;
        current = current->next;
    }
}

void cumulative(linked_list* first)
{
    int total = 0;
    linked_list* current = first;

    while (current != nullptr)
    {
        total += current->value;
        current->value = total;
        current = current->next;
    }
}

bool equal(linked_list* xs, linked_list* ys)
{
    while (xs != nullptr && ys != nullptr)
    {
        if (xs->value != ys->value)
        {
            return false;
        }

        xs = xs->next;
        ys = ys->next;
    }

    return xs == ys;
}
