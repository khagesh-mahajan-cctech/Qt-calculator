#ifndef INF_TO_POST_H
#define INF_TO_POST_H
#include <iostream>

int precedence(char c);

std::string infixToPostfix(std::string exp);

double operation(double a, double b, char op);

int isOperand(char ch);

bool isOperator(char ch);

std::string scanNum(int &i, std::string exp);

double evaluate(std::string expression);

#endif // INF_TO_POST_H
