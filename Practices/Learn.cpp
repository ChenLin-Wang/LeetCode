#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> stringSplit(string s, char d) {
    vector<int> res;
    string temp = "";
    for (const auto &c: s) {
        if (c == ' ') {
            res.push_back(stoi(temp));
            temp = "";
        } else temp += c;
    }
    res.push_back(stoi(temp));
    return res;
}

int LIS(vector<int> a) {
    if (a.size() == 0) return 0;
    int maxLength = 0;
    for (int i = 0; i < a.size() - 1; i++) {
        int l = 1;
        for (int j = i + 1; j < a.size(); j++) {
            if (a[j] > a[j - 1]) l ++;
        }
        maxLength = max(maxLength, l);
    }
    return maxLength;
}

int main() {
    cout << "Enter size of array: "; int s; cin >> s;
    cout << "Enter array:" << endl; string arrStr;
    cin.ignore();
    vector<int> arr;
    if (s > 0) {
        getline(cin, arrStr);
        arr = stringSplit(arrStr, ' ');
    }
    cout << LIS(arr) << endl;
    return 0;
}