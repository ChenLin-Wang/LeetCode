#include "header.h"

vector<int> Solution::plusOne(vector<int>& digits){
    bool x = 1;
    for (int i = digits.size() - 1; i >= 0; i --) {
        int d = digits[i] + x;
        x = d / 10;
        digits[i] = d % 10;
    }
    if (x == 1) {
        digits.insert(digits.begin(), 1);
    }
    return digits;
}


void Test::test66() {
    vector<int> inp = {9, 9, 9};
    vector<int> res = Solution::plusOne(inp);
    for (auto i : res) {
        cout << i << endl;
    }
}