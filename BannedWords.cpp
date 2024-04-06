/* Create function filtered(), which will take as an argument:
std::vector\<std::string\> and std::set<std::string>.
The first argument (vector) will be source of some words,
while the second argument (set) will be a collection of banned words.
Function should return a new vector of words, which does not contain banned words. */

#include <iostream>
#include <vector>
#include <string>
#include <set>

auto filtered(std::vector<std::string> vec, std::set<std::string> set) -> std::vector<std::string> {
    //erase if
}
auto main() -> int {
    std::vector<std::string> vec = {"Car", "Fuck", "Hello", "Party", "Shit"};
    std::set<std::string> set = {"Fuck", "Shit"};
    vec = filtered(vec, set);

    for (auto words : vec) {
        std::cout << words << ' ';
    }
    std::cout << std::endl;
}