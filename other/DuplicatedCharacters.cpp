#import<iostream>
#import<vector>

using namespace std;

int main() {
    string str;
    cout << "Enter the string: "; cin >> str;
    vector<int> v('z' + 1, 0);
    
    cout << str << endl;
    
    for (char c: str) {
        v[c]++;
    }
    
    cout << "Duplicate characters and their counts:" << endl;
    
    for (int i = 0; i < v.size(); i++) {
        if (v[i] <= 1) continue;
        cout << char(i) << ": " << v[i] << endl;
    }
    
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << "Enter:" << endl;
    vector<int> v(5);
    for (int i = 0; i < v.size(); i++) {
        string str;
        cin >> str;
        v[i] = stoi(str);
    }
    
    cout << "result:" << endl;
    
    for (auto i: v) {
        cout << i << endl;
    }
}