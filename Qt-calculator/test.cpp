#include "catch.hpp"
#include "inf_to_post.h"
#include "logic.h"

TEST_CASE("Precedence of operator test")
{
    REQUIRE(precedence('/') == 2);
    REQUIRE(precedence('*') == 2);
    REQUIRE(precedence('+') == 1);
    REQUIRE(precedence('-') == 1);
}

TEST_CASE("Infix to postfix conversion")
{
    REQUIRE(infixToPostfix("(2 - 3 + 4 ) * (5 + 6 * 7 )") == "2 3 - 4 + 5 6 7 * + * ");
    REQUIRE(infixToPostfix("45 + 15") == "45 15 + ");
    REQUIRE(infixToPostfix("3 + 9 - (3 - 88 ) * 7") == "3 9 + 3 88 - 7 * - ");
    REQUIRE(infixToPostfix("(425 * 98 + (14 / 2 ) * 78 / (45 * 2 ))") == "425 98 * 14 2 / 78 * 45 2 * / + ");
}

TEST_CASE("Checking if input is an operator")
{
    REQUIRE(isOperator('+') == 1);
    REQUIRE(isOperator('-') == 1);
    REQUIRE(isOperator('*') == 1);
    REQUIRE(isOperator('/') == 1);
}

TEST_CASE("Checking if input is an operand", "[0,1,2,3,4,5,6,7,8,9]")
{
    REQUIRE(isOperand('0') == 1);
    REQUIRE(isOperand('1') == 1);
    REQUIRE(isOperand('2') == 1);
    REQUIRE(isOperand('3') == 1);
    REQUIRE(isOperand('4') == 1);
    REQUIRE(isOperand('5') == 1);
    REQUIRE(isOperand('6') == 1);
    REQUIRE(isOperand('7') == 1);
    REQUIRE(isOperand('8') == 1);
    REQUIRE(isOperand('9') == 1);
}

TEST_CASE("Postfix evaluation")
{
    REQUIRE(evaluate("(2 - 3 + 4 ) * (5 + 6 * 7 )") == 141);
    REQUIRE(evaluate("45 + 15") == 60);
    REQUIRE(evaluate("3 + 9 - (3 - 88 ) * 7") == 607);
    //REQUIRE(evaluate("(425 * 98 + (14 / 2 ) * 78 / (45 * 2 ))") == 41656.0666666667);

}

TEST_CASE("Binary operation", "addition, subtraction, multiplication, division")
{
    REQUIRE(operation(50,20,'+') == 70);
    REQUIRE(operation(5,12,'-') == 7);
    REQUIRE(operation(5,45,'*') == 225);
    REQUIRE(operation(4,40,'/') == 10);
}

TEST_CASE("Unary operation")
{
    REQUIRE(unaryOperation("+/-", "14") == -14);
    REQUIRE(unaryOperation("%", "78") == 0.78);
    REQUIRE(unaryOperation("1/x", "2") == 0.5);
}
