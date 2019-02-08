#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include "frequency-table.h"
#include "bits.h"
#include <algorithm>
#include <memory>
#include <map>

template<typename T> class HuffmanBranch;
template<typename T> class HuffmanLeaf;

template<typename T>
class HuffmanTree
{
private:
    virtual void fill_in_codes(Bits& accumulated_bits, std::map<T, Bits>&) const = 0;

    friend class HuffmanBranch<T>;
    friend class HuffmanLeaf<T>;

public:
    HuffmanTree(unsigned weight) : weight(weight) { }
    virtual ~HuffmanTree() { }

    std::map<T, Bits> extract_codes() const
    {
        std::map<T, Bits> table;
        Bits bits;

        fill_in_codes(bits, table);

        return table;
    }

    unsigned weight;
};

template<typename T>
class HuffmanBranch : public HuffmanTree<T>
{
private:
    void fill_in_codes(Bits& accumulated_bits, std::map<T, Bits>& table) const override
    {
        accumulated_bits.append(0);
        left->fill_in_codes(accumulated_bits, table);
        accumulated_bits.drop_last();

        accumulated_bits.append(1);
        right->fill_in_codes(accumulated_bits, table);
        accumulated_bits.drop_last();
    }

public:
    HuffmanBranch(std::shared_ptr<HuffmanTree<T>> left, std::shared_ptr<HuffmanTree<T>> right)
        : HuffmanTree(left->weight + right->weight), left(left), right(right) { }

    std::shared_ptr<HuffmanTree<T>> left, right;
};


template<typename T>
class HuffmanLeaf : public HuffmanTree<T>
{
private:
    void fill_in_codes(Bits& accumulated_bits, std::map<T, Bits>& table) const override
    {
        table[value] = accumulated_bits;
    }

public:
    HuffmanLeaf(const T& value, unsigned weight)
        : HuffmanTree(weight), value(value) { }

    T value;
};

template<typename T>
std::shared_ptr<HuffmanTree<T>> build_tree(const FrequencyTable<T>& frequencies)
{
    std::vector<std::shared_ptr<HuffmanTree<T>>> list;

    for (auto x : frequencies.elements())
    {
        list.push_back(std::make_shared<HuffmanLeaf<T>>(x, frequencies[x]));
    }

    while (list.size() > 1)
    {
        std::sort(list.begin(), list.end(), [](auto p, auto q) -> bool { 
            return p->weight > q->weight; 
        });

        auto a = list.back();
        list.pop_back();
        auto b = list.back();
        list.pop_back();

        auto branch = std::make_shared<HuffmanBranch<T>>(a, b);
        list.push_back(branch);
    }

    return list.front();
}

#endif
