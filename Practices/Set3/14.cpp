#include "../header.h"

string Solution::longestCommonPrefix(vector<string>& strs) {
    string pref = "";
    int i = 0;
    while(true) {
        if (i == strs[0].size()) return pref;
        char c = strs[0][i];
        for (const auto &s: strs) {
            if (s[i] != c) return pref;
        }
        pref += c;
        i++;
    }
    return pref;
}

void Test::test14() {
    vector<string> strs = {"flower","flow","flight"};
    cout << Solution::longestCommonPrefix(strs) << endl;
}