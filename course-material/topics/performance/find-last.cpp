struct linked_list_node
{
    linked_list_node* next;
};

const linked_list_node*
  find_last(const linked_list_node* p)
{
    if (p->next == nullptr) return p;
    else return find_last(p->next);
}
