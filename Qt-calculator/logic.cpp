#include <iostream>
#include <cmath>

double unaryOperation(std::string btn, std::string text)
{
    double number = std::stod(text);

    if(btn == "+/-")
    {
        number = number * (-1);
        return number;
    }
    else if(btn == "%")
    {
        number = number / 100;
        return number;
    }
    else if(btn == "1/x")
    {
        number = 1 / number;
        return number;
    }
    else if(btn == "√")
    {
        number = sqrt(number);
        return number;
    }
    else
        return 0;
}
