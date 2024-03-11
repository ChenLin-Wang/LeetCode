#include "../header.h"

string Solution::removeDumplicates(string s) {
    vector<char> stack = {};
    int stackTop = -1;
    for (auto c : s) {
        if (stackTop > -1 && c == stack[stack.size() - 1]) { stack.pop_back(); stackTop --; }
        else { stack.push_back(c); stackTop ++; }
    }
    return string(stack.begin(), stack.end());
}

void Test::test1047() {
    cout << Solution::removeDumplicates("abbaca") << endl;
}