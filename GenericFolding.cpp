/* Write a template function named fold() that takes a vector of any type, an object of any type and
an accumulating function whose task is to return the “combination” of the initial object and
each subsequent element from the vector. The template should return the object passed in,
suitably processed by the function. */

#include <iostream>
#include <vector>
#include <string>

template<typename T, typename U, typename F>
auto fold(std::vector<T> vec, U obj, F func) {
    for (auto n: vec)
        obj = func(obj, n);
    return obj;
}

auto main() -> int {
    auto strings = std::vector<std::string>{
            "abc", "defghi", "jk", "lmno"
    };

    auto sum_of_sizes = fold(
            strings, std::size_t(0),
            [](std::size_t i, std::string s) {
                return i + s.size();
            }
    );

    const concatenated_string = fold(
            strings,
            std::string(""),
            [](std::string sum, std::string next) {
                return sum + next;
            }
    );

    std::cout << sum_of_sizes << '\n'
              << concatenated_string;
}
