#define CATCH_CONFIG_RUNNER
#include "Catch.h"


int main(int argc, char* const argv[])
{
    std::cout << "WARNING: YOU ARE RUNNING THE SOLUTION'S TESTS" << std::endl;
    std::cout << "RIGHT CLICK ON THE STUDENT PROJECT AND SET IT AS STARTUP PROJECT" << std::endl;

    Catch::Session().run(argc, argv);
}
