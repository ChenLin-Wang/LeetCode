#include "../header.h"

// not finished

bool Solution::regexMatch(string s, string p) {
    vector<string> ps = {};
    char pre = '\0';
    for (const auto &c: p) {
        if (c == '*') {
            ps.push_back(string{pre, c});
            pre = '\0';
        } else { 
            if (pre != '\0') ps.push_back(string({pre}));
            pre = c;
        }
    }
    if (pre != '\0') ps.push_back(string({pre}));

    for (auto pp: ps) cout << pp << " "; cout << endl;

    int i = 0, j = 0;
    string cur = ps[i], next;
    char c = cur[0], n;
    for (; i < ps.size() - 1; i ++) {
        cur = ps[i];
        next = ps[i + 1];
        c = cur[0];
        n = next[0];
        if (cur.size() == 1) {
            if (c != '.' && s[j] != c) return false;
            cout << "1: (" << s[j] << ") " << cur << " - " << next << " = " << j << endl;
            j++;
        } else {
            cout << i << "(): " << cur << endl;
            while(true) {
                if (j == s.size()) return false;
                if (n == '.' || s[j] == n) break;
                if (c != '.' && s[j] != c) break;
                cout << "2: (" << s[j] << ") " << cur << " - " << next << " = " << j << endl;
                j++;
            }
        }
        
        if (i == ps.size() - 2) {
            cout << next << endl;
            cur = next;
            c = n;
        }
    }
    if (cur.size() == 1) {
        if (c != '.' && s[j] != c) return false;
        cout << "3: (" << s[j] << ") " << cur << " = " << j << endl;
        j++;
    } else {
        while(true) {
            if (j == s.size()) return true;
            if (c != '.' && s[j] != c) break;
            cout << "4: (" << s[j] << ") " << cur << " = " << j << endl;
            j++;
        }
    }
    return j == s.size();
}

// bool Solution::regexMatch(string s, string p) {
//     char pre = '\0';
//     char next = '\0';
//     int i = 0;
//     for (const auto &c: p) {
//         if (c == '*') {
//             if (pre == '.') return true;
//             else {
//                 while (true) {
//                     if (i == s.size()) return true;
//                     if (s[i] != pre) break;
//                     i++;
//                 }
//             }
//             pre = '\0';
//         } else {
//             if (pre != '\0') {
//                 if (pre != '.' && s[i] != pre) return false;
//                 i ++;
//             }
//             pre = c;
//         }
//     }
//     if (pre != '\0') {
//         if (pre != '.' && s[i] != pre) return false;
//         i++;
//     }
//     return i == s.size();
// }

void Test::test10() {
    cout << Solution::regexMatch("mississippi", "mis*is*ip*.") << endl;
}