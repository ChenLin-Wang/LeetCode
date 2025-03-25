#include "../header.h"

string Solution::intToRoman(int num) {
    vector<vector<string>> romans = {
        {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
        {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
        {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
        {"", "M", "MM", "MMM"}
    };
    string res = "";
    int i = 0;
    while(num) {
        res = romans[i][num % 10] + res;
        num /= 10;
        i++;
    }
    return res;
}

void Test::test12() {
    cout << Solution::intToRoman(58) << endl;
}