#include <stack>
#include <iostream>

std::string scanNum(size_t &i, std::string exp)
{
    std::string value;
    value = exp[i++];
    while(exp[i] != ' ' && i < exp.length())
    {
        value = value + exp[i++];
    }
    return value;
}
int precedence(char c)
{
    if(c == '/' || c == '*')
    {
        return 2;
    }
    else if(c == '+' || c == '-')
    {
        return 1;
    }
    else
        return -1;
}

std::string infixToPostfix(std::string exp)
{
    std::stack<char> stk;
    std::string result;

    for(size_t i=0; i < exp.length() ; i++)
    {
        char c = exp[i];

        if(c == ' ')
            continue;
        else if( c >= '0' && c <= '9' )
        {
            result = result + scanNum(i,exp);
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
            while(!stk.empty() && precedence(exp[i]) <= precedence(stk.top()))
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

bool isOperator(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    else
        return 0;
}

int isOperand(char ch)
{
    if(ch >= '0' && ch <= '9')
        return 1;
    else
        return 0;
}

double operation(double a, double b, char op)
{
    if(op == '+')
        return b + a;
    else if(op == '-')
        return b - a;
    else if(op == '*')
        return b * a;
    else if(op == '/')
        return b / a;
    else
        return INT_MIN;
}

double postFixEval(std::string exp)
{
    double a, b;
    std::stack<double> st;
    for(size_t i=0; i < exp.length(); i++)
    {
        if(isOperator(exp[i]) == 1)
        {
               a = st.top();
               st.pop();
               b = st.top();
               st.pop();
               st.push(operation(a, b, exp[i]));
        }
        else if(isOperand(exp[i]) == 1)
        {
            st.push(stoi(scanNum(i, exp)));
        }
    }
    return st.top();
}

double evaluate(std::string expression)
{

    std::string exp = infixToPostfix(expression);
    return postFixEval(exp);

}
