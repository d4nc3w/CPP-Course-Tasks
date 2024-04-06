/* Write a program that will open a text file with the following structure:

Name1 wololo heheh
Name2 123 456 19 22
Name3 some random text right there

Then the program should create text files (with the extension .txt) with names specified by the first words
in each line (for example, in the above example, they will be Name1.txt, Name2.txt, and Name3.txt).
The contents of these files should be the elements specified in the original file after their names.
 Each word you place in the newly created files should be placed on a separate line. */

#include <iostream>
#include <fstream>

auto main() -> int {
    auto filename = std::string();
    filename = "data";
    auto file = std::fstream(filename + ".txt", std::ios::in);
    auto line = std::string();
    
    std::cout << filename << ": ";
    while(file >> line) {
        std::cout << line << " ";
    }
    std::cout << std::endl;
}


