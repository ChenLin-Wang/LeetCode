#include "../header.h"

int Solution::lengthOfLongestSubstring(string s) {
    string win = "";
    int max = 0;
    for (const auto &c: s) {
        size_t cPlace = win.find(c);
        if (cPlace == string::npos) {
            win += c;
        } else {
            int length = win.size();
            if (max < length) max = length;
            win = win.substr(cPlace + 1, win.size() - cPlace - 1);
            win += c;
        }
    }
    int length = win.size();
    if (max < length) max = length;
    return max;
}

void Test::test3() {
    cout << Solution::lengthOfLongestSubstring("dvdf") << endl;
}