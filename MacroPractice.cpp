/* Write and test a program which
  •Asks the user to enter three numbers;
  •Reads them in;
  •Then,
  –if preprocesor macroGETMAXis defined, writes the largest number on the screen;
  –if preprocesor macroGETMINis defined, writes the smallest number;
  –if both macros are defined, writes both the smallest and the largest numbers;
  –if none of them is defined, the compilation should fail. */

#include <iostream>
using namespace std;

#define GETMAX
#define GETMIN

auto main() -> int {
    int a, b, c;
    std::cout << "Please input 3 numbers: " << std::endl;
    std::cin >> a >> b >> c;

#if defined(GETMAX) && !defined(GETMIN)
    std::cout << "The largest number is: " << std::max({a, b, c}) << std::endl;
#endif

#ifdef defined(GETMIN) && !defined(GETMAX)
     std::cout << "The smallest number is: " << std::min({a, b, c}) << std::endl;
#endif

#if defined (GETMAX) && defined (GETMIN)
    std::cout << "The largest number is: " << std::max({a, b, c}) << std::endl;
    std::cout << "The smallest number is: " << std::min({a, b, c}) << std::endl;
#elif !(defined(GETMAX) || defined(GETMIN))
    std::cout << "Please define GETMAX or GETMIN" << std::endl;
#endif

    return 0;
}

