/* Create a VERSION enum, which will have three values: EVEN, ODD, PRIME
Create a remove_if_enum() function, with a vector of integers, and a VERSION enum passed as an argument.
Function should remove elements from the vector if they are either: prime, even or odd numbers. */

#include <iostream>
#include <vector>
#include <algorithm>
#include <fmt/ranges.h>
enum class VERSION{
    EVEN,ODD,PRIME
};
std::vector<int> remove_if_enum(std::vector<int> vec, VERSION version){
    switch (version) {
        case VERSION::EVEN : std::erase_if(vec ,[](int x) {
            return x%2==0;
        });
            break;
        case VERSION::ODD : std::erase_if(vec,[](int x) {
            return x%2!=0;
        });
            break;
        case VERSION::PRIME : std::erase_if(vec,[](int n) {
                if (n <= 1)
                    return false;
                for (int i = 2; i <= std::sqrt(n); i++) {
                    if (n % i == 0)
                        return false;
                }
                return true;
            });
            break;
    }
    return vec;
}
//additonal
void remove_if_enum_ref(std::vector<int>& vec, VERSION version){
    switch (version) {
        case VERSION::EVEN : std::erase_if(vec ,[](int x) {
            return x%2==0;
        });
            break;
        case VERSION::ODD : std::erase_if(vec,[](int x) {
            return x%2!=0;
        });
            break;
        case VERSION::PRIME : std::erase_if(vec,[](int n) {
                if (n <= 1)
                    return false;
                for (int i = 2; i <= std::sqrt(n); i++) {
                    if (n % i == 0)
                        return false;
                }
                return true;
            });
            break;
    }
}
int main(){
    {
        std::vector<int> vec = {1, 2, 3, 4, 5, 5};
        vec = remove_if_enum(vec, VERSION::ODD);
        fmt::print("{}\n", vec);
        vec = {1, 2, 3, 4, 5, 5};
        vec = remove_if_enum(vec, VERSION::EVEN);
        fmt::print("{}\n", vec);
        vec = {1, 2, 3, 4, 5, 5};
        vec = remove_if_enum(vec, VERSION::PRIME);
        fmt::print("{}\n", vec);
    }
    //additional
    fmt::print("Option 2\n");
    {
        std::vector<int> vec = {1, 2, 3, 4, 5, 5};
        remove_if_enum_ref(vec, VERSION::ODD);
        fmt::print("{}\n", vec);
        vec = {1, 2, 3, 4, 5, 5};
        remove_if_enum_ref(vec, VERSION::EVEN);
        fmt::print("{}\n", vec);
        vec = {1, 2, 3, 4, 5, 5};
        remove_if_enum_ref(vec, VERSION::PRIME);
        fmt::print("{}\n", vec);
    }
}