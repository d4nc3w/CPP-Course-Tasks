/* Create a function called maxNestedParenthesisDepth() which should accept std::string
as an argument and return its greatest nesting depth of parenthesis. Assume that the parenthesis are
balanced, that is there no way for the function to receive a value such as ")))(". */

#include <iostream>
#include <string>
#include <vector>

auto maxNestedParenthesisDepth(std::string string) -> int {
    int depth = 0;
    int maxDepth = 0;
    for (int i = 0; i < string.size(); i++) {
        if (string[i] == '(') {
            depth++;
            if (maxDepth <= depth) {
                maxDepth = depth;
            }
        }
        if (string[i] == ')') {
            depth--;
        }
    }
    return maxDepth;
}

auto main() -> int {
    std::cout
    << maxNestedParenthesisDepth("()") << ' '
    << maxNestedParenthesisDepth("(()(()))") << ' '
    << maxNestedParenthesisDepth("(sd()ds((ss))   a)") << ' '
    << maxNestedParenthesisDepth("(((S)))") << ' '
    << maxNestedParenthesisDepth("()()()()") << ' '
    << maxNestedParenthesisDepth("()(())()");
}
