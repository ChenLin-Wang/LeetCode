#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string vowels = "aeiouAEIOU";
    string input, dels;
    cout << "Enter the string: "; cin >> input; cin.ignore();
    cout << "Enter the delimiters: "; getline(cin, dels);
    
    string res = "";
    string word = "";
    int value = 0;
    int resValue = 0;
    for (auto c: input) {
        size_t idx = dels.find(c);
        if (idx != string::npos) {
            if (value > resValue) {
                resValue = value;
                res = word;
            }
            value = 0;
            word = "";
        } else {
            word += c;
            if (vowels.find(c) != string::npos) {
                value += 2;
            } else if (isalpha(c)) {
                value += 1;
            } else if (isdigit(c)) {
                value += c - '0';
            }
        }
    }
    
    if (value > resValue) {
        resValue = value;
        res = word;
    }
    
    cout << "Result: " << res << endl;
    
    return 0;
}