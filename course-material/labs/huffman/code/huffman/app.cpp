#include "frequency-table.h"
#include "huffman-tree.h"
#include <iostream>
#include <bitset>
#include <string>
#include <sstream>


FrequencyTable<char> build_frequency_table(const std::string& string)
{
    FrequencyTable<char> ft = count(string);

    std::cout << "Frequencies" << std::endl;
    for (auto c : ft.elements())
    {
        std::cout << c << " " << ft[c] << std::endl;
    }

    std::cout << std::endl;

    return ft;
}

std::map<char, Bits> build_code_book(std::shared_ptr<HuffmanTree<char>> tree)
{
    auto codes = tree->extract_codes();

    std::cout << "Codes" << std::endl;
    for (auto it : codes)
    {
        std::cout << it.first << " " << it.second << std::endl;
    }
    std::cout << std::endl;

    return codes;
}

void encode(const std::string& string, std::map<char, Bits> codes)
{
    Bits encoding;
    for (auto c : string)
    {
        encoding.concatenate(codes[c]);
    }

    std::cout << "Original string: " << string << std::endl;
    std::cout << "Encoding: " << encoding << std::endl;
    std::cout << "Length: " << encoding.size() << std::endl;
}

void encode(const std::string& string)
{
    auto ft = build_frequency_table(string);
    auto tree = build_tree(ft);
    auto codes = build_code_book(tree);
    encode(string, codes);
}


int main()
{
    encode("ACDBAEDBAADBCAAABDAAAAC");
}
