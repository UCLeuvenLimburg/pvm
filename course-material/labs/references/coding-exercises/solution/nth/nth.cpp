#include "nth.h"
#include <assert.h>


int& nth(std::vector<int>& ns, int index)
{
    index = index % int(ns.size());
    index += ns.size();
    index = index % int(ns.size());

    // Sanity checks
    assert(0 <= index);
    assert(0 < ns.size());

    return ns[index];
}

int nth(const std::vector<int>& ns, int index)
{
	index = index % int(ns.size());
	index += ns.size();
	index = index % int(ns.size());

	// Sanity checks
	assert(0 <= index);
	assert(0 < ns.size());

	return ns[index];
}