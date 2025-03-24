#include "../header.h"

string Solution::zigzagConvert(string s, int numRows) {
    if (numRows <= 1) return s;
    string res = "";
    for (int r = 0; r < numRows; r ++) {
        int x = r;
        while(x < s.size()) {
            res += s[x];
            if (r == 0 || r == (numRows - 1)) {
                x += 2 * numRows - 2;
            } else {
                x += 2 * numRows - 2 * r - 2;
                if (x < s.size()) res += s[x];
                x += 2 * r;
            }
        }
    }
    return res;
}

void Test::test6() {
    cout << Solution::zigzagConvert("PAYPALISHIRING", 1) << endl;
}

// x       x       x
// x     x x     x x
// x   x   x   x   x
// x x     x x     x
// x       x       x

// 0 (+5+3)               (2 * numRows - 2) 
// 1 (+4+2) (+2+0)
// 2 (+3+1) (+3+1)        (2 * numRows - 2 * r - 2) (2r)
// 3 (+2+0) (+4+2)
// 4 (+5+3)               (2 * numRows - 2) 
