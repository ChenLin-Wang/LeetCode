#include "../header.h"

bool Solution::isPalindromeNum(int x) {
    if (x < 0) return 0;
    int m = x;
    long n = 0;
    while (x) {
        n = n * 10 + x % 10;
        x /= 10;
    }
    return m == n;
}

void Test::test9() {
    cout << Solution::isPalindromeNum(121) << endl;
}