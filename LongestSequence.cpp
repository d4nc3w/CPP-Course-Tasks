/* Write a program reading integers until zero is entered and printing the length of the longest sequence
of consecutive numbers of the same value (and this value). */

#include <iostream>
#include <vector>

auto main() -> int {
    std::vector<int> vec;
    int number;
    int counter = 1;
    int max = 0;
    int value = 0;

    std::cout << "Please input numbers: " << std::endl;
    do {
        std::cin >> number;
        vec.push_back(number);
    } while (number != 0);

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == vec[i+1]) {
            counter++;
        } else {
            if (counter > max) {
                max = counter;
                value = vec[i];
            }
            counter = 1;
        }
    }

    std::cout << "The longest sequence of consecutive numbers of the same value is: " << max << std::endl;
    std::cout << "The value is: " << value << std::endl;

    return 0;
}

