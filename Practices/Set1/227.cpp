#include "../header.h"
#include <string>

int Solution::calculate(string s) {
    vector<int> stack = {};
    char op = '+';
    string num = "";
    int i = 0;
    bool back = false;
    for (auto c : s) {
        i ++;
        switch (c) {
            case ' ': 
                if (num.length() > 0) goto NumberHandle;
                continue;
            case '+':
            case '-':
            case '*':
            case '/': 
                if (num.length() > 0) { back = true;  goto NumberHandle;}
                Back:
                op = c;
                continue;
            default: 
                num += c; 
                if (i == s.length()) goto NumberHandle;
                else continue;

            NumberHandle:
            int n = stoi(num);
            num = "";
            switch (op) {
                case '-': n = -n; break;
                case '*': n *= stack[stack.size() - 1]; stack.pop_back(); break;
                case '/': n = stack[stack.size() - 1] / n; stack.pop_back(); break;
            }
            stack.push_back(n);
            if (back) { back = false; goto Back; } 
        }
    }

    int sum = 0;
    for (auto i : stack) sum += i;
    return sum;
}

void Test::test227() {
    int res = Solution::calculate("3+ 223* 2");
    cout << res << endl;
}