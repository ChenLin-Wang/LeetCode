#include "../header.h"
#include <algorithm>

int Solution::reverseInteger(int x) {
    long n = 0;
    while(x) {
        n = n * 10 + x % 10;
        x = x / 10;
    }
    if (n > INT_MAX || n < INT_MIN) return 0;
    return int(n);
}

// int Solution::reverseInteger(int x) {
//     long xx = x;
//     string n = to_string(abs(xx));
//     std::reverse(n.begin(), n.end());
//     string maxInt = to_string(numeric_limits<int>::max());

//     if (maxInt.size() == n.size()) {
//         for (int i = 0; i < maxInt.size(); i++) {
//             if (maxInt[i] > n[i]) return (x < 0 ? -1 : 1) * stoi(n);
//             else if (maxInt[i] < n[i]) return 0;
//         }
//         return (x < 0 ? -1 : 1) * stoi(n);
//     } else if (maxInt.size() > n.size()) return (x < 0 ? -1 : 1) * stoi(n);
//     else return 0;
// }

void Test::test7() {
    cout << Solution::reverseInteger(-2147483648) << endl;
}