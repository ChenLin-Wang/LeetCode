#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char function(char c) {
    return tolower(c);
}

// islower
// isupper
// isdigit
// isalpha
// isalnum

int main() {
    string str = "abcd";
    
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    
    // transform(str.begin(), str.end(), str.begin(), [] (char c1) {
    //     return toupper(c1);
    // });

    // transform(str.begin(), str.end(), str.begin(), function);
    
    cout << str << endl;
    
    return 0;
}

int transform() {
    vector<int> v;
    vector<string> strs;
    
    for (int i = 0; i < 10; i++) {
        v.push_back(rand() % 10);
    }
    
    strs.resize(v.size());
    fill(strs.begin(), strs.end(), "Undefined");
    
    transform(v.begin(), v.end(), strs.begin(), [](int num) {
        return to_string(num) + 'p';
    });
    
    for (auto i: strs) {
        cout << i << " ";
    }
    
    cout << endl;
}

int sort() {
    vector<int> v;
    
    for (int i = 0; i < 10; i++) {
        v.push_back((rand() % 10));
    }
    
    sort(v.begin(), v.end(), less<int>());

    // sort(v.begin(), v.end(), [](int lhs, int rhs) {
    //     return lhs < rhs;
    // });
    
    for (auto i: v) {
        cout << i << " ";
    }
    
    cout << endl;
    
    return 0;
}