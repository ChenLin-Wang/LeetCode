#include "../header.h"
#include <stack>
#include <unordered_map>

bool Solution::bracketExpansion(string s) {
    stack<char> st;
    
    unordered_map<char, int> m;
    m['('] = 11;
    m[')'] = 12;
    m['['] = 21;
    m[']'] = 22;
    m['{'] = 31;
    m['}'] = 32;

    for (const auto &c: s) {
        auto n = m.find(c);
        if (n == m.end()) continue;
        int v = m[c];
        int n2 = v % 10, n1 = (v / 10) % 10;
        if (n2 == 1) {
            st.push(n1);
        } else {
            if (st.top() != n1) return false;
            st.pop();
        }
    }
    return true;
}

void Test::testBracket() {
    cout << Solution::bracketExpansion("bool Solution::bracketExpansion(string s) {stack<char> st;unordered_map<char, int> m;m[''] = 11;m[''] = 12;m[''] = 21;m[''] = 22;m[''] = 31;m[''] = 32;for (const auto &c: s) {auto n = m.find(c);if (n == m.end()) continue;int v = m[c];int n2 = v % 10, n1 = (v / 10) % 10;if (n2 == 1) {st.push(n1);} else {if (st.top() != n1) return false;st.pop();}}return true;}") << endl;
}