/* Create a lambda function that takes two integers as input and returns a bool value.
The lambda should return true if the last digit of the first argument is less than the last digit of the second argument
Create a second lambda function that takes a single integer as input. It should return the last digit of the integer.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <fmt/ranges.h>

auto main() -> int {
    auto lastDigit1 = [](int a, int b) -> bool {
        return a % 10 < b % 10;
    };
    auto lastDigit2 = [](int a) -> int {
        return a % 10;
    };
    fmt::print("{}\n", lastDigit1(123, 456));
    fmt::print("{}\n", lastDigit2(123));

   /* The std::ranges::sort() algorithm, in addition to the argument specifying the range it should work on,
    also takes two optional arguments - a comparator and a projection.
    To change the order in which the elements are sorted, one or both of them can be specified.
    Create two identical vectors that store integers. Sort them using the std::ranges::sort() algorithm.
    Make sure that the numbers are sorted only by their last digits. To achieve this,
    use the comparator and a projection respectively. */

   std::vector<int> vec1 {125,342,563};
    std::vector<int> vec2 = vec1;

   auto lastDigit3 = [](int a) -> int {
       return a % 10;
   };
   std::ranges::sort(vec1, std::ranges::less{}, lastDigit3);
   std::ranges::sort(vec2, std::ranges::less{}, lastDigit3);

    std::cout << "vec1: ";
    for (auto n : vec1) std::cout << n << " ";
    std::cout << "\nvec2: ";
    for (auto n : vec2) std::cout << n << " ";
    std::cout << std::endl;
}