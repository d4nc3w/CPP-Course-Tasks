/* An anagram is a pair of words (or sets of words) that are made up from the same letters.
For example, listen and silent.
If several words are anagrams of each other, they can be called an anagram group.
Write a function largestAnagramGroupsFrom() that takes an std::string object representing a long text as an argument
and returns a vector containing the largest anagram groups from that text. */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <fmt/ranges.h>

auto largestAnagramGroupsFrom(std::string text) {
    auto words = std::vector<std::string>();
    std::set<std::string> (words.begin(), words.end());
    auto word = std::string();
    auto anagrams = std::map<std::string, std::set<std::string>>();
    auto anagramGroups = std::vector<std::vector<std::string>>();

    for (auto chr : text) {
        if (chr == ' ' || chr == ' ') {
            words.push_back(word);
            word = "";
        } else {
            word += chr;
        }
    }
    words.push_back(word);
    return words;
}

auto main() -> int {
    std::string text = "In life, we find ourselves perplexed\n"
                       "By twists and turns, and what comes next\n"
                       "We wonder where our path will lead\n"
                       "And hope for guidance, in our need\n"
                       "\n"
                       "But sometimes all we need to do\n"
                       "Is simply change our point of view\n"
                       "For listen can become silent too\n"
                       "And love can turn into vole anew\n"
                       "\n"
                       "Theres evil hiding in live\n"
                       "And cinema in iceman lives\n"
                       "To look for the positive, and let our hearts be lighter\n"
                       "But lets focus on the good, and be a little kinder\n"
                       "\n"
                       "We can find heart in earth below\n"
                       "And care in race - its apropos\n"
                       "Strained can be disrate, and thats okay\n"
                       "For tomorrow is a brand new day\n"
                       "\n"
                       "So lets embrace the twists and turns\n"
                       "And all the lessons that life confirms\n"
                       "For every problem, theres a clue\n"
                       "And an anagram to guide us through.\n"
                       "\n"
                       "For completeness, lets add few more,\n"
                       "made-up, words: elov arce";


    largestAnagramGroupsFrom(text);
    std::cout << text << std::endl;
}
