/* Write a program which reads in a loop a sequence of integral numbers until the user enters 0,
which just signals the end of data and is not then taken into account.
After that, the program prints the value of the smallest and the largest element of the sequence
and the number of occurrences of these values in the whole sequence. */

#include <iostream>
#include <vector>
#include <algorithm>

auto main() -> int {
    std::cout << "Please input numbers: " << std::endl;
    int number;
    std::vector<int> vec;
    do{
        std::cin >> number;
        vec.push_back(number);
    } while (number != 0);
    vec.pop_back();

    auto min = std::min_element(vec.begin(), vec.end());
    auto max = std::max_element(vec.begin(), vec.end());
    int min_count = std::count(vec.begin(), vec.end(), *min);
    int max_count = std::count(vec.begin(), vec.end(), *max);

    std::cout << "The smallest number is: " << *min
    << " " << "and it occurs: " << min_count << " times" << std::endl;
    std::cout << "The largest number is: " << *max
    << " " << "and it occurs: " << max_count << " times" << std::endl;
}