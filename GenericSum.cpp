/* Write a template function named sum() that takes a vector of any type as an argument.
Assume that this type supports addition operators (+ and +=).
The template should return the sum of all elements in the vector passed in. */

#include <iostream>
#include <vector>
#include <string>
#include <fmt/ranges.h>

template<typename T>
auto sum(std::vector<T> vec) {
    auto sum = T();
    for (auto n: vec)
        sum += n;
    fmt::print("{}\n", sum);
}

auto main() -> int {
    std::vector<int> NumVec = {1,2,3,4,5};
    std::vector<std::string> StrVec = {"H","e","l","l","o"," ","W","o","r","l","d"};
    sum(NumVec);
    sum(StrVec);

}
