/* Write a program that will read numbers from a text file (assuming that the file consists exclusively of numbers)
and display their sum. Get the path to the file from the user via standard input. */

#include <iostream>
#include <fstream>

auto main() -> int {
    auto filename = "NumbersToSum.txt";
    auto file = std::fstream(filename, std::ios::out);
    file << "1 2 3 4 5 6 7 8 9 10";
    file.close();

    auto num = int();
    auto sum = int();
    file = std::fstream(filename, std::ios::in);
    while (file >> num)
        sum += num;

    std::cout << sum << std::endl;
}