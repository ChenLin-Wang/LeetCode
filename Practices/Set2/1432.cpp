#include "../header.h"
#include <string>

int Solution::maxDiffFromChangeAnInteger(int num) {
    string str = to_string(num), str2 = to_string(num);
    int i = 0;
    char a = '\n';
    for (const auto &c : str) {
        if (c == '9') {
            i++;
            continue;
        }
        if (a == '\n') {
            a = c;
            str[i] = '9';
        } else {
            if (c == a) {
                str[i] = '9';
            }
        }
        i++;
    }

    i = 0;
    a = '\n';
    char b;
    if (str2[0] == '1') {
        for (const auto &c: str2) {
            if (c == '0' || c == '1') {
                i++;
                continue;
            }
            if (a == '\n') {
                a = c;
                b = '0';
                str2[i] = b;
            } else {
                if (c == a) {
                    str2[i] = b;
                }
            }
            i++;
        }
    } else {
        for (const auto &c: str2) {
            if (c == (i == 0 ? '1' : '0')) {
                i++;
                continue;
            }
            if (a == '\n') {
                a = c;
                b = i == 0 ? '1' : '0';
                str2[i] = b;
            } else {
                if (c == a) {
                    str2[i] = b;
                }
            }
            i++;
        }
    }

    return stoi(str) - stoi(str2);
}

void Test::test1432() {
    // cout << Solution::maxDiffFromChangeAnInteger(555) << endl;
    // cout << Solution::maxDiffFromChangeAnInteger(9) << endl;
    // cout << Solution::maxDiffFromChangeAnInteger(9288) << endl;
    cout << Solution::maxDiffFromChangeAnInteger(1101057) << endl;
}