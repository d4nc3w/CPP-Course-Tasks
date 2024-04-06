
#include <iostream>
#include <vector>

template<typename T>
std::vector<T> operator+(const std::vector<T> &vec1, const std::vector<T> &vec2) {
    auto result = std::vector<T>();
    auto iterations = std::max(vec1.size(), vec2.size());
    for (size_t i = 0; i < iterations; ++i) {
        T value1 = (i < vec1.size()) ? vec1[i] : 0;
        T value2 = (i < vec2.size()) ? vec2[i] : 0;
        result.push_back(value1 + value2);
    }
    return result;
}

auto main() -> int {
    std::vector<int> vec1{1, 2, 3, 4};
    std::vector<int> vec2{5, 6, 7};

    std::vector<int> result = vec1 + vec2;

    for (auto &elem : result) {
        std::cout << elem << "\t";
    }
    std::cout << std::endl;
}
