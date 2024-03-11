#include "../header.h"

int Solution::findMaxConsecutiveOnes(vector<int>& nums) {
    int i = 0;
    int c = 0;
    int maxC = 0;
    for (auto j : nums) {
        c = (j == 1) ? c + 1 : 0;
        if (maxC < c) maxC = c;
        i ++;
    }
    return maxC;
}



void Test::test485() {
    vector<int> inp = {1, 1, 0, 1, 1, 1};
    int res = Solution::findMaxConsecutiveOnes(inp);
    cout << res << endl;
}