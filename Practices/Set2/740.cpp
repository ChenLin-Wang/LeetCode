#include "../header.h"
#include <map>

int rob(map<int, int> &nums, int size) {
    int first = nums[0], second = max(nums[0], nums[1]);
    for (int i = 2; i < size; i++) {
        int temp = second;
        second = max(first + nums[i], second);
        first = temp;
    }
    return second;
}

int Solution::deleteAndEarn(vector<int>& nums) {
    map<int, int> m;
    int max = 0;
    for (const auto &n: nums) {
        if (max < n) max = n;
        m[n] += n;
    }
    return rob(m, max + 1);
}

void Test::test740() {
    vector<int> nums = {1,1,1,2,4,5,5,5,6};
    cout << Solution::deleteAndEarn(nums) << endl;
}