/* Create a lambda function that takes two integers as input and returns a bool value.
Lambda should return true if the last digit of the first argument is less than the last digit of the second argument.
*/

#include <iostream>
#include <vector>
#include <algorithm>

auto main() -> int {
    auto comparator = [](int a , int b) -> bool {
        if (a % 10 < b % 10) {
            return true;
        } else {
            return false;
        }
    };

//Create a second lambda function that takes a single integer as input. It should return the last digit of the integer.
    auto projection = [](int a) -> int {
        return a%10;
    };

    std::cout << comparator(123, 456) << std::endl;
    std::cout << comparator(19, 45) << std::endl;
    std::cout << projection(125) << std::endl;
    std::cout << projection(43) << std::endl;

/*Create two identical vectors that store integers. Sort them using the std::ranges::sort() algorithm.
Make sure that the numbers are sorted only by their last digits.
To achieve this, use the comparator and a projection respectively. */
    std::vector<int> vec1 = {123, 456, 19, 45};
    std::vector<int> vec2 = {123, 456, 19, 45};
    std::ranges::sort(vec1, comparator);
    std::ranges::sort(vec2, std::ranges::less(), projection);

    for (auto element : vec1) std::cout << element << ' ';
    std::cout << '\n';
    for (auto element : vec2) std::cout << element << ' ';
    std::cout << '\n';
}
