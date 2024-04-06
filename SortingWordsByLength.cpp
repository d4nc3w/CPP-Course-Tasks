/* Write a program that will read words from the user until the word stop is entered.
Display all these words by grouping them by their lengths.
Display each group on a separate line. Skip the word stop. Do not display a word more than once. */

#include <iostream>
#include <string>
#include <set>
#include <map>

auto SortByLength(std::set<std::string> words) {
    auto wordsByLength = std::map<int, std::set<std::string>>();
    for (auto word: words) {
            auto length = word.length();
            wordsByLength[length].insert(word);

    }
    for (auto [length, words]: wordsByLength) {
        std::cout << length << ": ";
        for (auto word: words)
            std::cout << word << " ";
        std::cout << std::endl;
    }
}

auto main() -> int {
    auto word = std::string();
    auto words = std::set<std::string>();

    do {
        std::cin >> word;
        if (word != "stop")
            words.insert(word);
    } while (word != "stop");

    SortByLength(words);
}


