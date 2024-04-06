/* Create  function exchangeboundaries() with a vector of integeres passed as an argument.
Function should swap the smallest and the largest value stored in the vector.
Assume that vector passed is not empty. Do not use additional variables to implement this solution. */

#include <iostream>
#include <vector>
#include <algorithm>

auto ExchangeBoundries(std::vector<int> vec) -> int{
auto min = std::min_element(vec.begin(), vec.end());
    auto max = std::max_element(vec.begin(), vec.end());
    std::swap(*min, *max);

    for (auto i : vec) {
        std::cout << i << " ";
    }
}

int main() {
    std::vector<int> vec = {2, 3, 9, 6, 7, 4, 1, 5, 8};
    ExchangeBoundries(vec);
}
