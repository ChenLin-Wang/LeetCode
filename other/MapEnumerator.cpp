#import<iostream>
#import<map>

using namespace std;

int main() {
    string str;
    cout << "Enter the string: "; cin >> str;
    map<char, int> m;
    
    for (char c: str) {
        if (m.find(c) == m.end()) {
            m[c] = 1;
        } else {
            m[c] = m[c] + 1;
        }
    }
    
    cout << "Duplicate characters and their counts:" << endl;
    
    for (auto pair: m) {
        if (pair.second <= 1) continue;
        cout << pair.first << ": " << pair.second << endl;
    }
    
    return 0;
}