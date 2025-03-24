#include "../header.h"

string Solution::longestPalindrome(string s) {
    string res = "";
    int max = 0;
    for (int i = 0; i < s.size(); i++) {
        bool repeat = s[i + 1] == s[i];
        for (int offset = 0; offset < 2; offset ++) {
            for (int j = 0; j <= i; j++) {
                if (s[i - j] == s[i + j + offset]) {
                    int length = j * 2 + 1 + offset;
                    if (max < length) {
                        res = s.substr(i - j, length);
                        max = length;
                    }
                } else break;
            }
        }
    }
    return res;
}

void Test::test5() {
    cout << Solution::longestPalindrome("aaaa") << endl;
}