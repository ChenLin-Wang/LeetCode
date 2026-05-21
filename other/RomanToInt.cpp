#include<iostream>
#include<map>

using namespace std;

int main() {
    string romans;
    cout << "Enter the romans: "; cin >> romans;
    
    map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    
    int res = 0;
    int pre = 0;
    for (auto c: romans) {
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
    
    cout << "Result: " << res << endl;
    
    return 0;
}