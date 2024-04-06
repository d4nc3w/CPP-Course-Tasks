/* Write a program that reads the path to a file and a series of pairs of numbers from the user.
The program should remove all lines from the specified file that are between the specified pairs of numbers.
For example, if the user enters the following input: file.txt 1 3 9 12 4 30,
then lines number 1, 2, 3, 9, 10, 11, 12 and all lines from 4 to 30 should be removed from the file named file.txt.
Note that some of these ranges may overlap. Solve this problem before you start removing lines.
You can assume that the user will enter pairs of numbers until they enter the value -1. */

#include <iostream>
#include <fstream>
#include <string>
#include <fmt/ranges.h>
#include <vector>
#include <map>

auto main() -> int {
    auto filePath = std::string();
    std::cout << "Enter the path to the file1: " << std::endl;
    filePath = ("/Users/pjotr/CLionProjects/PJATK/cmake-build-debug/RemoveLines.txt");

    auto file1 = std::fstream (filePath, std::ios::out);
    auto file2 = std::fstream (filePath, std::ios::in);
    auto word = std::string();
    std::vector<std::string> vec = {};

    std::map<int, int> ranges;
    std::cout << "Enter the ranges of lines to remove: " << std::endl;
    auto start = int();
    auto end = int();
    do {
        std::cin >> start >> end;
    } while (start != -1 || end != -1);

    auto counter = 0;
    std::string blank = " ";
    for( auto line = std::string() ; std::getline(file1, line); ){
        counter++;
        if (counter >= start && counter <= end) {
            vec.push_back(blank);
        } else {
            vec.push_back(line);
        }
    }
    file1.close();

}