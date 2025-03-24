#include "../header.h"
#include <map>

int Solution::countDaysWithoutMeetings(int days, vector<vector<int>>& meetings) {
    vector<bool> ds(days + 1, true);
    int count = days;
    for (const auto &meeting : meetings) {
        int s = meeting[0], e = meeting[1];
        for (int i = s; i <= e; i++) {
            if (ds[i]) {
                ds[i] = false;
                count --;
            }
        }
    }
    return count;
}

// int Solution::countDaysWithoutMeetings(int days, vector<vector<int>>& meetings) {
//     vector<bool> ds(days + 1, true);
//     for (const auto &meeting : meetings) {
//         int s = meeting[0], e = meeting[1];
//         for (int i = s; i <= e; i++) {
//             ds[i] = false;
//         }
//     }
//     int count = 0;
//     for (const auto &d : ds) {
//         if (d) count += 1;
//     }
//     return count - 1;
// }

void Test::test3169() {
    vector<vector<int>> ms = {{5, 7}, {1, 3}, {9, 10}};
    cout << Solution::countDaysWithoutMeetings(10, ms) << endl;
    // vector<vector<int>> ms = {{1, 6}};
    // cout << Solution::countDaysWithoutMeetings(6, ms) << endl;
}