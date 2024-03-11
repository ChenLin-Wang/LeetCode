#include "../header.h"

vector<int> solution1(vector<int>& temperatures) {
    vector<int> res(temperatures.size());
    int i = 0;
    for (auto curT : temperatures) {
        for (int j = i + 1; j < temperatures.size(); j ++) {
            if (temperatures[j] > curT) {
                res[i] = j - i;
                break;
            }
        }
        i++;
    }
    return res;
}

vector<int> solution2(vector<int>& temperatures) {
    vector<int> stack = {};
    vector<int> res(temperatures.size());
    int i = 0;
    for (auto curT : temperatures) {
        while (stack.size() > 0) {
            int top = stack[stack.size() - 1];
            if (temperatures[top] >= curT) break;
            stack.pop_back();
            res[top] = i - top;
        }
        stack.push_back(i);
        i ++;
    }
    return res;
}

vector<int> Solution::dailyTemperatures(vector<int>& temperatures) {
    return solution2(temperatures);
}

void Test::test739() {
    vector<int> inp = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = Solution::dailyTemperatures(inp);
    for (auto i : res) {
        cout << i << endl;
    }
}