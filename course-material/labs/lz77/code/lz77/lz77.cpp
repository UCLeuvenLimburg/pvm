#include "lz77.h"
#include <algorithm>
#include <assert.h>
#include <sstream>
#include <vector>


unsigned match_length(const std::string& history, const std::string& future)
{
    unsigned i = 0;

    while (i < history.size() && i < future.size())
    {
        if (history[i] != future[i])
        {
            return i;
        }

        ++i;
    }

    return i;
}

void find_longest_match(const std::string& string, unsigned history_length, unsigned max_length, unsigned* distance, unsigned* length)
{
    *distance = 0;
    *length = 0;

    for (unsigned i = 0; i != history_length; ++i)
    {
        unsigned ml = match_length(string.substr(i, string.size() - i), string.substr(history_length, string.size() - history_length));

        if (ml > 0 && ml >= *length)
        {
            *distance = history_length - i;
            *length = std::min(ml, max_length);
        }
    }
}

std::vector<triplet> encode(unsigned max_distance, unsigned max_length, const std::string& string)
{
    std::vector<triplet> result;
    unsigned index = 0;
    unsigned distance;
    unsigned length;

    while (index < string.size())
    {
        unsigned history_length = std::min(index, max_distance);
        unsigned history_start = index - history_length;
        std::string history = string.substr(history_start, string.size() - history_start);

        unsigned future_length = (unsigned)string.size() - index - 1;
        find_longest_match(history.substr(0, history.size() - 1), history_length, max_length, &distance, &length);

        triplet t{ distance, length, string[index + length] };
        result.push_back(t);

        assert(t.distance <= max_distance);
        assert(t.length <= max_length);

        index += length + 1;
    }

    return result;
}

std::ostream& operator <<(std::ostream& out, const triplet& t)
{
    return out << "[" << t.distance << ", " << t.length << ", '" << t.datum << "']";
}

std::string decode(const std::vector<triplet>& triplets)
{
    std::vector<char> result;

    unsigned index = 0;
    for (auto& triplet : triplets)
    {
        for (unsigned i = 0; i != triplet.length; ++i)
        {
            result.push_back(result[index - triplet.distance + i]);
        }

        result.push_back(triplet.datum);

        index += triplet.length + 1;
    }

    std::stringstream ss;

    for (auto c : result)
    {
        ss << c;
    }

    return ss.str();
}

bool triplet::operator ==(const triplet& t) const
{
    return this->datum == t.datum && this->distance == t.distance && this->length == t.length;
}