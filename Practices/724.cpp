#include "header.h"

int Solution::pivotIndex(vector<int>& nums) {
    int m = accumulate(nums.begin(), nums.end(), 0);
    if (m - nums[0] == 0) return 0;
    float deter;
    int n = 0, i = -1, j = 0;
    for (int x : nums) {
        n += x;
        if (j == nums.size() - 1) break;
        deter = (m - nums[j + 1]) / 2.0;
        if (n == deter) {
            i = j + 1;
            break;
        }
        j ++;
    }
    return i;
}


void Test::test724() {
    vector<int> nums = {-1,-1,-1,-1,-1,-1};
    int res = Solution::pivotIndex(nums);
    cout << res << endl;
}