#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

auto main() -> int {
    auto graph = std::map<std::string, std::set<std::string>>();
    graph["A"] = {"B", "C"};
    graph["B"] = {"E"};
    graph["C"] = {"D"};
    graph["D"] = {"B"};
    graph["E"] = {"C"};

    for (auto neighbor : graph["A"]) {
        std::cout << neighbor << ' ';
    }
}
