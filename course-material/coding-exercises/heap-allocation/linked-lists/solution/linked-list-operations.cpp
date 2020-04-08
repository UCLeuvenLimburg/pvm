#include "linked-list-operations.h"

linked_list* range(int a, int b)
{
    linked_list* current = nullptr;

    while (a < b)
    {
        current = new linked_list{ b - 1, current };
        --b;
    }

    return current;
}

linked_list* copy_list(linked_list* start)
{
    linked_list dummy{ 0, nullptr };
    auto p_original = start;
    auto p_copy = &dummy;

    while (p_original != nullptr)
    {
        auto p_fresh = new linked_list{ p_original->value, nullptr };
        p_copy->next = p_fresh;
        p_copy = p_fresh;
        p_original = p_original->next;
    }

    return dummy.next;
}

void prepend(linked_list** start, int value)
{
     *start = new linked_list{ value, *start };
}

void append(linked_list** start, int value)
{
    linked_list dummy{ 0, *start };
    auto current = &dummy;

    while (current->next != nullptr)
    {
        current = current->next;
    }
    
    current->next = new linked_list{ value, nullptr };

    *start = dummy.next;
}
