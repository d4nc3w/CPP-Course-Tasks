/* Write a function template chunk() that takes two iterators to any container
(use templates; the type of the first iterator does not have to be the same as the type of the second iterator)
and an integer n. The template is supposed to return a vector of vectors (each inner vector of length n)
containing the elements in the range represented by the two iterators passed in.
If the number of elements between the iterators is not divisible by n, the last subvector may contain fewer elements.
*/

#include <iostream>
#include <vector>
#include <string>

template<typename T, typename Y>
auto chunk(T begin, Y end, int n) -> std::vector<std::vector<typename T::value_type>> {
    auto vec = std::vector<std::vector<typename T::value_type>>{};
    auto subvec = std::vector<typename T::value_type>{};
    for (auto i = begin; i != end; i++) {
        subvec.push_back(*i);
        if (subvec.size() == n) {
            vec.push_back(subvec);
            subvec.clear();
        } else {
            if (i == end -1) {
                vec.push_back(subvec);
                subvec.clear();
            }
        }
    }
    return vec;
}
template <typename T>
auto print(std::vector<T> vec) {
    for (auto n : vec)
        std::cout << n << ' ';
    std::cout << '\n';
}

auto main() -> int {
    auto v1 = std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto v2 = std::vector<std::string>{"a", "b", "c", "d", "e", "f"};

    auto v1by3 = chunk(v1.begin(), v1.end(), 3);
    auto v1by2 = chunk(v1.begin(), v1.end(), 2);

    auto v2by5 = chunk(v2.begin(), v2.end(), 5);
    auto v2by1 = chunk(v2.begin(), v2.end(), 1);

    for (auto vec : v1by3) print(vec);
    std::cout << '\n';
    for (auto vec : v1by2) print(vec);
    std::cout << '\n';
    for (auto vec : v2by5) print(vec);
    std::cout << '\n';
    for (auto vec : v2by1) print(vec);
}