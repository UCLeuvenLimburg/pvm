#include "branch-prediction.h"
#include "sequential-access.h"
#include "memory-alignment.h"
#include "cache.h"
#include "tail-call-optimisation.h"
#include "inlining.h"
#include "dead-code-elimination.h"
#include "compile-time-execution.h"
//#include "templates.h"
#include "zero-cost-abstractions.h"


int main()
{
    // Uncomment one test and run it

    //test_branch_prediction();
    test_cache();
    //test_sequential_access();
    //test_memory_alignment();
    //test_tail_call_optimisation();
    //test_inlining();
    //test_dead_code_elimination();
    //test_compile_time_execution();
    //test_templates();
    //test_zero_cost_abstractions();
}
