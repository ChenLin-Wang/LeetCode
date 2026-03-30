#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

int main() {
    string input;
    cout << "Enter string: "; cin >> input;
    
    stack<int> s;
    unordered_map<char, int> m;
    m['('] = 11;
    m[')'] = 12;
    m['['] = 21;
    m[']'] = 22;
    m['{'] = 31;
    m['}'] = 32;
    m['<'] = 41;
    m['>'] = 42;
    
    bool res = true;
    
    for (auto c: input) {
        if (m.find(c) == m.end()) continue;
        int value = m[c];
        if (value % 10 == 1) {
            s.push(value / 10);
        } else {
            if (s.empty()) { res = false; break; }
            if (s.top() != value / 10) { res = false; break; }
            s.pop();
        }
    }
    
    res &= s.empty();
    
    cout << "result: " << (res ? "true" : "false") << endl;
    
    return 0;
}