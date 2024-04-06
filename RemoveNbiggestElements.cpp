/* Create a function called eraseNBiggest(), which will accept a vector of real numbers and an integer n as arguments.
It should remove n biggest values from the passed vector. */

#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

auto eraseNBiggest(std::vector<double> vec, int n) -> void {
    for (int i = 0; i < n; i++) {
    }

}

auto main() -> int {
    std::vector<double> vec = {1.0, 2.0, 3.0, 4.0, 5.0};
    eraseNBiggest(vec, 2);
}
