#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string str = "1,2,3,4,5,6,7\n8,9\t10,11";
    
    stringstream s(str);
    string item;
    // for \n
    while(getline(s, item)) {
        stringstream s1(item);
        string i2;
        while(getline(s1, i2, '\t')) {
            stringstream s2(i2);
            string num;
            while(getline(s2, num, ',')) {
                cout << num << endl;
            }
        }
    }
    
    return 0;
}

int inputArrayFromCin() {
    vector<int> input;
    cout << "Input the array: ";
    string line;
    while(getline(cin, line)) {
        stringstream s(line);
        string num;
        while(getline(s, num, ',')) {
            cout << num << endl;
        }
    }
    
    return 0;
}

int inputMatrix() {
    int n;
    vector<vector<int>> arr;
    cout << "Enter size: "; cin >> n;
    cin.ignore();
    cout << "Enter array: ";
    string line;
    for (int i = 0; i < n; i++) {
        getline(cin, line); // or cin >> line;
        stringstream s(line);
        string num;
        vector<int> temp;
        while(getline(s, num, ',')) {
            temp.push_back(stoi(num));
        }
        arr.push_back(temp);
    }
    
    for(auto i: arr) {
        for (auto ii: i) {
            cout << ii << " ";
        }
        cout << endl;
    }
    
    return 0;
}