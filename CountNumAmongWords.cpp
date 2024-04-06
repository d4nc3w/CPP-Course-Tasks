/* Write a program that will read all words from a file specified by the user and check how many of them are numbers.
Then it should display which of those numbers appears most frequently. */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <fmt/ranges.h>

auto FindMax(std::vector<int> vec){
    std::ranges::sort(vec);
    int counter = 1;
    int maxCounter = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec [i] == vec [i + 1])
            counter++;
        else {
            if (counter > maxCounter)
                maxCounter = counter;
                fmt::print("num: {} ", vec[i]);
                fmt::print("counter: {}\n", counter);
                counter = 1;
        }
    }
}

auto main() -> int {
    auto filename = std::string();
    filename = "NumbersToSum.txt";

    auto num = int();
    std::vector<int> nums;
    auto line = std::string();

    auto file = std::fstream(filename, std::ios::in);
    while (file >> line) {
        if (std::isdigit(line[0])) {
            num = std::stoi(line);
            nums.push_back(num);
        }
    }
    FindMax(nums);
}
