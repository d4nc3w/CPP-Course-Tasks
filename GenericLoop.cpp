/* Create a template function named repeat() that takes two parameters: an integer n and a parameterless lambda function.
The template should call the lambda function n times.
This is meant to be a kind of substitute for the classic for() loop,
which executes its body n times using a local variable. */

#include <iostream>
#include <vector>
#include <string>
#include <fmt/ranges.h>

template<typename T>
auto repeat(int n, T lambda) {
    for (auto i = 0; i < n; i++)
        lambda();
}

auto main() -> int {
    auto n = int();
    std::cout << "Enter a number: ";
    std::cin >> n;
    std::cout << std::endl;
    repeat(n, [](){fmt::print("Hello\n");});
}