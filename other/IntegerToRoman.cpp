#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> scales = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    vector<string> symbols = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    
    int num;
    cout << "Enter number: "; cin >> num;
    string roman = "";
    
    while(num > 0) {
        int scale;
        int i = 0;
        for (; i <= scales.size(); i++) {
            int s = scales[i];
            if (num / s > 0) {
                scale = s;
                break;
            }
        }
        
        roman += symbols[i];
        num -= scale;
    }
    
    cout << "result: " << roman << endl;
    
    return 0;
}