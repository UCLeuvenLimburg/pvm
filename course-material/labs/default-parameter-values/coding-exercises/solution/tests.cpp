#define CATCH_CONFIG_RUNNER
#include "Catch.h"


int main(int argc, char* const argv[])
{
	std::cout << "Unfortunately, there are no tests for this exercise" << std::endl;
	std::cout << "If anyone has an idea of how to write tests that check you" << std::endl;
	std::cout << "rely on default parameter values instead of overloads, please let me know" << std::endl;

	Catch::Session().run(argc, argv);
}
