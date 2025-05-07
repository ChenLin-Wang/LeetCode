#include "../header.h"
#include <unordered_map>

string Solution::evaluateBrackets(string s, vector<vector<string>>& knowledge) {
    string res = "";
    string temp = "";
    unordered_map<string, string> m;
    for (const auto ss: knowledge) m[ss[0]] = ss[1];
    bool bracket = false;
    for (const auto &c: s) {
        if (c == '(') {
            bracket = true;
        } else if (c == ')') {
            if (m.find(temp) == m.end()) res += '?';
            else res += m[temp];
            bracket = false;
            temp = "";
        } else {
            if (bracket) temp += c;
            else res += c;
        }
    }
    return res;
}

void Test::test1807() {
    vector<vector<string>> knowledge = {{"name","bob"},{"age","two"}};
    cout << Solution::evaluateBrackets("(name)is(age)yearsold", knowledge) << endl;
}