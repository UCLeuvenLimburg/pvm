#ifndef FREQUENCY_TABLE_H
#define FREQUENCY_TABLE_H

#include <map>
#include <vector>
#include <string>


template<typename T, typename F=unsigned>
class FrequencyTable
{
    std::map<T, F> m_table;

public:
    void set(const T& t, F frequency)
    {
        auto it = m_table.find(t);

        if (frequency == 0)
        {
            if (it != m_table.end())
            {
                m_table.erase(it);
            }
        }
        else
        {
            it.second = frequency;
        }
    }

    void count(const T& t)
    {
        auto it = m_table.find(t);

        if (it == m_table.end())
        {
            m_table[t] = 1;
        }
        else
        {
            it->second++;
        }
    }

    F operator [](const T& t) const
    {
        auto it = m_table.find(t);

        if (it == m_table.end())
        {
            return 0;
        }
        else
        {
            return it->second;
        }
    }

    std::vector<T> elements() const
    {
        std::vector<T> result;

        for (auto it : m_table)
        {
            result.push_back(it.first);
        }

        return result;
    }
};

FrequencyTable<char> count(const std::string& string)
{
    FrequencyTable<char> frequencies;

    for (auto c : string)
    {
        frequencies.count(c);
    }

    return frequencies;
}

#endif
