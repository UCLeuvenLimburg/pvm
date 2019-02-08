#include <iostream>


namespace
{
    struct linked_list_node
    {
        linked_list_node* next;
    };

    const linked_list_node* find_last(const linked_list_node* p)
    {
        if (p->next == nullptr) return p;
        else return find_last(p->next);
    }

    int factorial_no_tail_call(int n)
    {
        if (n == 0) return 1;
        else return n * factorial_no_tail_call(n - 1);
    }

    int factorial_tail_call(int n, int acc = 1)
    {
        if (n == 0) return acc;
        else return factorial_tail_call(n - 1, acc * n);
    }
}


void test_tail_call_optimisation()
{
    linked_list_node e{ nullptr };
    linked_list_node d{ &e };
    linked_list_node c{ &d };
    linked_list_node b{ &c };
    linked_list_node a{ &b };

    std::cout << find_last(&a) << std::endl;
}