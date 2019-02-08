#include "expression.h"
#include "operator.h"
#include "addition.h"
#include "multiplication.h"
#include "variable.h"
#include "literal.h"
#include "rpn-builder.h"
#include "../Catch.h"


typedef std::map<std::string, double> Context;


TEST_CASE("Literal evaluation")
{
    auto p = std::make_unique<const Literal>(5);
    const Context context;
    
    REQUIRE(p->evaluate(context) == Approx(5));
}

TEST_CASE("Variable evaluation")
{
    auto p = std::make_unique<const Variable>("x");
    Context context{ std::make_pair(std::string("x"), 42) };

    REQUIRE(p->evaluate(context) == Approx(42));
}

TEST_CASE("Addition evaluation")
{
    auto x = std::make_shared<const Variable>("x");
    auto y = std::make_shared<const Variable>("y");
    auto z = std::make_shared<const Variable>("z");

    std::vector<std::shared_ptr<const Expression>> operands { x, y, z };
    auto p = std::make_unique<const Addition>(operands);
    Context context{
        std::make_pair(std::string("x"), 1),
        std::make_pair(std::string("y"), 2),
        std::make_pair(std::string("z"), 3),
    };

    REQUIRE(p->evaluate(context) == Approx(6));
}

TEST_CASE("Multiplication evaluation")
{
    auto x = std::make_shared<const Variable>("x");
    auto y = std::make_shared<const Variable>("y");
    auto z = std::make_shared<const Variable>("z");

    std::vector<std::shared_ptr<const Expression>> operands{ x, y, z };
    auto p = std::make_unique<const Multiplication>(operands);
    Context context{
        std::make_pair(std::string("x"), 2),
        std::make_pair(std::string("y"), 3),
        std::make_pair(std::string("z"), 4),
    };

    REQUIRE(p->evaluate(context) == Approx(2 * 3 * 4));
}

TEST_CASE("RPN Builder")
{
    RPNBuilder builder;
    
    auto result = builder.literal(5).literal(7).add().build();
    const Context context;

    REQUIRE(result->evaluate(context) == Approx(5 + 7));
}