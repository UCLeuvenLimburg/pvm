#include "shared.h"
#include <chrono>


long long measure_time(std::function<void()> function)
{
    auto before = std::chrono::high_resolution_clock::now();
    function();
    auto after = std::chrono::high_resolution_clock::now();

    auto duration = after - before;
    return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
}
