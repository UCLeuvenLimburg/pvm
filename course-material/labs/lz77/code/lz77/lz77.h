#ifndef LZ77_H
#define LZ77_H

#include <iostream>
#include <vector>


struct triplet
{
    unsigned distance;
    unsigned length;
    char datum;

    bool operator ==(const triplet&) const;
};

std::ostream& operator <<(std::ostream& out, const triplet&);

unsigned match_length(const std::string& history, const std::string& future);
void find_longest_match(const std::string& string, unsigned history_length, unsigned max_length, unsigned* distance, unsigned* length);
std::vector<triplet> encode(unsigned max_distance, unsigned max_length, const std::string& string);
std::string decode(const std::vector<triplet>&);

#endif
