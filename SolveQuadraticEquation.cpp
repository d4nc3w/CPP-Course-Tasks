/* Write a program solving quadratic equations (ax2+bx+c= 0) given the coefficients a,b and c.
The program should work in all cases (in particular, when coefficients are 0 or the discriminant is negative). */

#include <iostream>
#include <cmath>

auto main() -> int {
    double a, b, c;
    std::cout << "Please input a, b and c: " << std::endl;
    std::cin >> a >> b >> c;

    auto delta = (b*b - 4*a*c);
    auto x1 = ((-b + sqrt(delta)) / (2*a));
    auto x2 = ((-b - sqrt(delta)) / (2*a));

    std::cout << "delta = " << delta << std::endl;
    std::cout << "x1 = " << x1 << std::endl;
    std::cout << "x2 = " << x2 << std::endl;
}
