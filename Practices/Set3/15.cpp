#include "../header.h"

bool compare(int n1, int n2) { return n1 < n2; }

vector<vector<int>> Solution::threeSum(vector<int>& nums) {
    vector<vector<int>> res = {};
    sort(nums.begin(), nums.end(), compare);
    for (int i = 0; i < nums.size() - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int left = i + 1, right = nums.size() - 1;
        while(left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                res.push_back({nums[i], nums[left], nums[right]});
                while(left < right && nums[left] == nums[left + 1]) left ++;
                while(left < right && nums[right] == nums[right - 1]) right --;
                left++;
                right--;
            } else if (sum >= 0) right --;
            else left ++;
        }
    }
    return res;
}

void Test::test15() {
    vector<int> ns = {-1,0,1,2,-1,-4};

    for (const auto &nums: Solution::threeSum(ns)) {
        for (const auto &n: nums) {
            cout << n << " ";
        }
        cout << endl;
    }
}