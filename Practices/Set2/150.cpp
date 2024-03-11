#include "../header.h"
#include <string>

int Solution::evalRPN(vector<string>& tokens) {
    vector<int> stack = {};
    for (auto curT : tokens) {
        if (isdigit(curT[curT.length() - 1])) {
            stack.push_back(stoi(curT));
            continue;
        }
        int topIndex = stack.size() - 1;
        int num1 = stack[topIndex - 1];
        int num2 = stack[topIndex];
        int res;
        stack.pop_back();
        stack.pop_back();
        switch (curT[0]) {
            case '+': res = num1 + num2; break;
            case '-': res = num1 - num2; break;
            case '*': res = num1 * num2; break;
            case '/': res = num1 / num2; break;
        }
        stack.push_back(res);
    }
    return stack[stack.size() - 1];
}


void Test::test150() {
    vector<string> inp = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << Solution::evalRPN(inp) << endl;
}