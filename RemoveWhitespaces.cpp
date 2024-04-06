/* Create a function called reduceAdjacentWhitespaces() that accepts an argument of a type std::string and returns
it modified in such a way that every sequence of adjacent whitespace characters is reduced to a singular space. */

#include <iostream>
#include <string>

auto reduceAdjacentWhitespaces (std::string string) -> std::string {
    int numOfspaces = 0;
    for (int i = 0; i < string.size(); i++) {
        if (string[i] == ' ') {
            numOfspaces++;
        }
    }
    for (int i = 0; i < numOfspaces-1; i++) {
        std::erase_if(string, [](char c) { return c == ' '; });
    }
    return string;
}

auto main() -> int {
    std::cout << '['
              << reduceAdjacentWhitespaces("Abc")
              << "]\n"
              << '['
              << reduceAdjacentWhitespaces("A b c")
              << "]\n"
              << '['
              << reduceAdjacentWhitespaces("   A\tb c      ")
              << "]\n"
              << '['
              << reduceAdjacentWhitespaces("A\t\tb\n \n  \t c")
              << "]\n";
}


