#include "../header.h"
#include <map>

vector<string> combine(vector<string> m, vector<char> n) {
    vector<string> res;
    if (m.size() == 0) {
        for (const auto &c: n) res.push_back({c});
        return res;
    }
    for (const auto &s: m) {
        for (const auto &c: n) {
            res.push_back(s + c);
        }
    }
    return res;
}

vector<string> Solution::letterCombinations(string digits) {
    map<char, vector<char>> m;
    m['1'] = {};
    m['2'] = {'a', 'b', 'c'};
    m['3'] = {'d', 'e', 'f'};
    m['4'] = {'g', 'h', 'i'};
    m['5'] = {'j', 'k', 'l'};
    m['6'] = {'m', 'n', 'o'};
    m['7'] = {'p', 'q', 'r', 's'};
    m['8'] = {'t', 'u', 'v'};
    m['9'] = {'w', 'x', 'y', 'z'};
    m['0'] = {' '};

    vector<string> res;

    for (const auto &d: digits) {
        vector<char> cs = m[d];
        res = combine(res, cs);
    }
    return res;
}

void Test::test17() {
    for (const auto &s: Solution::letterCombinations("22")) {
        cout << s << " ";
    }
    cout << endl;
}