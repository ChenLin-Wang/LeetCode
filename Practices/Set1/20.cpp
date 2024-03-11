#include "../header.h"

bool Solution::isValid(string s) {
    if (s.length() % 2 != 0) return false;
    vector<int> stack = {};
    int stackTop = -1;
    for (auto i : s) {
        int type;
        int mode;
        switch (i) {
            case '(': type = 1; mode = 1; break;
            case ')': type = 1; mode = 2; break;
            case '[': type = 2; mode = 1; break;
            case ']': type = 2; mode = 2; break;
            case '{': type = 3; mode = 1; break;
            case '}': type = 3; mode = 2; break;
            default: return false;
        }

        if (mode == 1) {
            stack.push_back(type);
            stackTop ++;
        } else {
            if (stackTop == -1) return false;
            if (stack[stackTop] == type) {
                stack.pop_back();
                stackTop --;
            } else return false;
        }
    }
    return stackTop == -1;
}

void Test::test20() {
    bool res = Solution::isValid("()[]{}");
    cout << res << endl;
}