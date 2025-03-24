#include "../header.h"
#include <algorithm>

long long getCost(string s, char to) {
    if (s.size() == 1) return s[0] == to ? 0 : 1;
    int max;
    for (max = s.size() - 1; max >= 0; max--) if (s[max] != to) break;
    if (max < 0) return 0;
    long long res = 0;
    long long cost = 1;
    for (int i = 0; i < max; i++) {
        int j = i + 1;
        if (s[i] != s[j]) {
            res += cost;
        }
        cost ++;
    }
    res += cost;
    return res;
}

long long Solution::minimumCostToMakeAllCharactersEqual(string s) {
    if (s.size() == 1) return 0;
    int half = s.size() / 2;
    string str1 = s.substr(0, half);
    string str2 = s.substr(half, s.size() - half);
    reverse(str2.begin(), str2.end());
    long long v1 = getCost(str1, '0') + getCost(str2, '0');
    long long v2 = getCost(str1, '1') + getCost(str2, '1');
    return v1 > v2 ? v2 : v1;
}

void Test::test2712() {
    cout << Solution::minimumCostToMakeAllCharactersEqual("000010000") << endl;
}




// 010110

// 100 2
// 000 3
// 001 3
// 000 1


// 110100

// 001100 3
// 111100 2
// 111111 2

// 7

// 000100 2
// 000011 3
// 000000 2

// 7

// 010101
// 12345

// 011010
// 123456
// 120456 = 17
// 103456

// 100101 = 6
// 011011 = 5
// 100111 = 4
// 011111 = 3
// 111111 = 1

// 19


// 10011101 -> 1
// 12345678
// 1030067 = 17

// 01100011 -> 7
// 10011111 -> 6
// 01111111 -> 3
// 11111111 -> 1


// 010111011 -> 0
// 123456789
// 123006709 = 28

// 010111011
// 101000100 -> 9
// 010111000 -> 7
// 101000000 -> 6
// 010000000 -> 3
// 100000000 -> 2
// 000000000 -> 1


// 0001111 -> 1

// 000 1111 = 3
// 0001 111 = 3