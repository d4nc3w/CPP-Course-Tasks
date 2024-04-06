/* Fill in the following snipet of code in a way, that will make it print out sorted elements.
Do not use standard algorithms. Try instead using std::set. */

#include <iostream>
#include <set>
#include <vector>

auto main() -> int {
    std::vector<int> vec = {3, 4, 2, 5, 6, 1};
    auto set = std::set<int>(vec.begin(), vec.end());

    for (auto e : set) {
        std::cout << e << ' ';
    }
    std::cout << std::endl;
}
