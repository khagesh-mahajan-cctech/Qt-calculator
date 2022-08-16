#include <stack>
#include <iostream>

std::string scanDigits(size_t &i, std::string expression)
{
    std::string numbers;
    numbers = expression[i++];
    while(expression[i] != ' ' && i < expression.length())
    {
        numbers = numbers + expression[i++];
    }
    return numbers;
}
int precedence(char opr)
{
    if(opr == '/' || opr == '*')
    {
        return 2;
    }
    else if(opr == '+' || opr == '-')
    {
        return 1;
    }
    else
        return -1;
}


std::string infixToPostfix(std::string infixExpression)
{
    std::stack<char> stk;
    std::string result;

    for(size_t i=0; i < infixExpression.length() ; i++)
    {
        char c = infixExpression[i];

        if(c == ' ')
            continue;
        else if( c >= '0' && c <= '9' )
        {
            result = result + scanDigits(i,infixExpression);
            result = result + " ";
        }
        else if(c == '(')
        {
            stk.push(c);
        }
        else if(c == ')')
        {
            while(stk.top() != '(')
            {
                result = result + stk.top();
                result = result + " ";
                stk.pop();
            }
            stk.pop();
        }
        else
        {
            while(!stk.empty() && precedence(infixExpression[i]) <= precedence(stk.top()))
            {
                result = result + stk.top();
                result = result + " ";
                stk.pop();
            }
            stk.push(c);
        }
    }
    while(!stk.empty())
    {
        result = result + stk.top();
        result = result + " ";
        stk.pop();
    }
    return result;
}

bool isOperator(char opr)
{
    if(opr == '+' || opr == '-' || opr == '*' || opr == '/')
        return 1;
    else
        return 0;
}

int isOperand(char operand)
{
    if(operand >= '0' && operand <= '9')
        return 1;
    else
        return 0;
}

double operation(double num_one, double num_two, char opr)
{
    if(opr == '+')
        return num_two + num_one;
    else if(opr == '-')
        return num_two - num_one;
    else if(opr == '*')
        return num_two * num_one;
    else if(opr == '/')
        return num_two / num_one;
    else
        return INT_MIN;
}

double postFixEval(std::string postfixExp)
{
    double num_one, num_two;
    std::stack<double> st;
    for(size_t i=0; i < postfixExp.length(); i++)
    {
        if(isOperator(postfixExp[i]) == 1)
        {
               num_one = st.top();
               st.pop();
               num_two = st.top();
               st.pop();
               st.push(operation(num_one, num_two, postfixExp[i]));
        }
        else if(isOperand(postfixExp[i]) == 1)
        {
            st.push(stod(scanDigits(i, postfixExp)));
        }
    }
    return st.top();
}

double evaluate(std::string infixExpression)
{

    std::string postfixExp = infixToPostfix(infixExpression);
    return postFixEval(postfixExp);

}
