#include "../header.h"
#include <map>

int Solution::romanToInt(string s) {
    map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;

    int pre = 0;
    int res = 0;
    for (const auto &c: s) {
        int v = m[c];
        if (pre > 0 && pre < v) {
            res += v - pre;
            pre = 0;
        } else {
            res += pre;
            pre = v;
        }
    }
    res += pre;
    return res;
}

void Test::test13() {
    cout << Solution::romanToInt("III") << endl;
}