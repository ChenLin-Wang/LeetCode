#include "../header.h"

int Solution::myAtoi(string s) {
    if (s.size() == 0) return 0;
    long num = 0;
    bool emptyNum = true;
    char sign = '\0';
    for (const auto &c: s) {
        if (c < 48 || c > 57) {
            if (sign == '\0' && emptyNum) {
                if (c == '-' || c == '+') { sign = c; continue; }
                if (c == 32) continue;
            }
            break;
        } else {
            long n = num * 10 + (c - 48);
            long n2 = sign == '-' ? -n : n;
            if (n2 > INT_MAX) return INT_MAX;
            else if (n2 < INT_MIN) return INT_MIN;
            num = n;
            emptyNum = false;
        }
    }
    num = sign == '-' ? -num : num;
    return num;
}

void Test::test8() {
    cout << Solution::myAtoi("  +  413") << endl;
}