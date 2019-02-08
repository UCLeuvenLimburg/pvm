#include "rotate.h"


void rotate(std::vector<int>* ns, int delta)
{
    if ((*ns).size() > 0)
    {
        std::vector<int> temp((*ns).size());
        
        while (delta < 0) delta += int((*ns).size());

        for (int i = 0; i != (*ns).size(); ++i)
        {
            int j = (i + delta) % (*ns).size();

            temp[j] = (*ns)[i];
        }

        *ns = temp;
    }
}