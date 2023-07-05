#include <iostream>
#include <vector>
#include <cmath>

double evaluateExpression(double t)
{
    double Pi = 3.14159265358979323846;

    double numerator = (1.0 / 6.0) * (375 * Pi * std::sin(50 * Pi * t) - 15 * std::cos(50 * Pi * t) * (2500 * Pi * Pi - 1)
                        + (15 * std::cos(0.25 * std::sqrt(15) * t) * (2500 * Pi * Pi - 1) - std::sqrt(15) * (2500 * Pi * Pi + 1) * std::sin(0.25 * std::sqrt(15) * t)) * std::exp(-0.25 * t));

    double denominator = (6250000 * Pi * Pi * Pi * Pi - 4375 * Pi * Pi + 1);

    double result = numerator / denominator;

    return result;
}

int main()
{
    double t = 0.1;  // Value of t for which expression is evaluated

    double result = evaluateExpression(t);

    std::cout << "The result of the expression at t = " << t << " is: " << result << std::endl;

    return 0;
}