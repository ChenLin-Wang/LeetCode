#include "../header.h"

int Solution::threeSumClosest(vector<int>& nums, int target) {
    if (nums.size() < 3) return 0;
    sort(nums.begin(), nums.end());
    int closest = 0;
    int minDiff = INT_MAX;
    for (int i = 0; i < nums.size() - 2; i ++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;;
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == target) {
                return sum;
            } else if (sum < target) left ++;
            else right --;
            int diff = abs(target - sum);
            if (diff < minDiff) {
                minDiff = diff;
                closest = sum;
            }
        }
    }
    return closest;
}

void Test::test16() {
    vector<int> nums = {-1,2,1,-4};
    cout << Solution::threeSumClosest(nums, 1) << endl;
}