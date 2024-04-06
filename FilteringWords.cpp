/* Write a function called filtered() which takes std::vector<std::string> and std::set<std::string> as arguments.
Treat the first argument (vector) as the source of words (assuming that one string stores one word).
Treat the second argument (set) as the source of prohibited words.
The function should return a new vector of words that does not contain any prohibited ones.
In other words, return a vector that contains all the words from the
first argument that do not appear in the second argument. */

#include <iostream>
#include <vector>
#include <set>
#include <string>

auto filtered(std::vector<std::string> vec, std::set<std::string> set) -> std::vector<std::string> {
    auto result = std::vector<std::string>();
    for (auto word : vec) {
        if (set.find(word) == set.end()) {
            result.push_back(word);
        }
    }
    return result;
}

auto main() -> int {
    std::vector<std::string> vec = {"Hello", "World!", "I", "fucking", "lol", "love", "you", "lol"};
    std::set<std::string> set = {"fucking", "lol"};

    vec = filtered(vec, set);
    for (auto word : vec) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
}
