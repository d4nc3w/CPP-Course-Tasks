/* Create a function called eraseNBiggest(), which will accept a vector of real numbers and an integer n as arguments.
It should remove n biggest values from the passed vector. */

#include <iostream>
#include <vector>
#include <algorithm>

auto eraseNBiggest(std::vector<double> vec, int n) -> std::vector<double> {
    std::sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++) {
        vec.pop_back();
    }
    return vec;
}

auto main() -> int {
    std::vector<double> vec = {1.0, 11.0, 9.0, 3.0, 5.0, 2.0, 7.0};
    vec = eraseNBiggest(vec, 2);

    for (auto n : vec) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}
