#include <iostream>
#include <vector>
#include <algorithm>
#include <fmt/ranges.h>
#include <set>
#include <map>
#include <string>

#define PRINT std::cout <<

int main() {
    PRINT "Hello\n";
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    /*{
    auto it = vec.begin() + 1;
    fmt::print("{}\n", *it); //2
    vec.erase(vec.begin());
    fmt::print("{}\n", *it); //3
    vec = {1, 2, 3, 4, 5, 6, 7};
    it = vec.end() - 1;
    fmt::print("{}\n", *it); //7
    //vec.erase(vec.begin(), vec.end());
    vec.clear();
    fmt::print("{}\n", *it); //7 don't use it
    }*/
    //set
    vec = { 1,2,0,2,2,2,5,1,0,3 };
    {
        auto set = std::set<int>(vec.begin(), vec.end());
        fmt::print("set-> {}\n", set);
        /*fmt::print("size -> {}\n", vec.size());
        std::ranges::unique(vec);
        fmt::print("size -> {}\n", vec.size());
        fmt::print("vec -> {}\n",vec);*/
        /*std::ranges::sort(vec);
        std::ranges::unique(vec);
        fmt::print("vec -> {}\n",vec);*/
        std::ranges::sort(vec);
        auto toErase = std::ranges::unique(vec);
        vec.erase(toErase.begin(), toErase.end());
        fmt::print("vec -> {}\n",vec);
    }
    //map
    {
        auto str = std::string("text");
        auto occurrences = std::map<char, int>();
        for(auto letter : str){
            occurrences[letter] += 1;
        }
        fmt::print("map -> {}\n", occurrences);
        for(auto pair : occurrences){
            fmt::print("{} -> {}\n", pair.first, pair.second);
        }
    }
    vec = { 1,2,0,2,2,2,5,1,0,3 };
    {
        std::ranges::sort(vec);
        auto [beginIter, endItrer] = std::ranges::unique(vec);
        vec.erase(beginIter, endItrer);
        fmt::print("vec -> {}\n",vec);
        auto str = std::string("text");
        auto occurrences = std::map<char, int>();
        for(auto letter : str){
            occurrences[letter] += 1;
        }
        for(auto [key, value] : occurrences){
            fmt::print("{} -> {}\n", key, value);
        }
    }
}