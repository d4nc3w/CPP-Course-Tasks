/* Write a program that will ask the user for a path to a folder containing text files.
The program should display the most frequent word that appears in the combined content of all of those files. */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <fmt/ranges.h>

auto main() -> int {
    auto folderPath = std::string();
    folderPath = "E:\\alcohol\\Jet Brains\\CLion 2022.3.2\\projects\\cmake-build-debug\\TextFiles";
    auto word = std::string();
    auto words = std::vector<std::string>();
    auto wordCount = std::map<std::string, int>();
    auto filepath = std::string();

    for (int i = 1; i <= 5; i++) {
        auto file = std::ifstream (folderPath + "\\File" + std::to_string(i) + ".txt", std::ios::in);

    }
    fmt::print("words: {}\n", words);
}
