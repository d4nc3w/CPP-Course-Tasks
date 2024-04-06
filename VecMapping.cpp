/* Write a template function named mapped() that takes a vector of any type and a function that will
serve as a mapping function. The template should return a new vector whose elements will be equal to all elements
from the input vector (passed in by the first argument) passed to the mapping function. */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

auto main() -> int {
    auto strings = std::vector<std::string>{"abc", "defghi", "jk", "lmno"};
    auto chars = mapped(
            strings,
            [](std::string s) { return s.front(); }
    );
    auto sizes = mapped(
            strings,
            [](std::string s) { return s.size(); }
    );

    for (auto c : chars) std::cout << c << ' ';
    std::cout << '\n';
    for (auto s : sizes) std::cout << s << ' ';
}


