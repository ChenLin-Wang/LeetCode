#include "../header.h"

vector<vector<int>> Solution::threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();
    
    if (n < 3) return result; // 少于 3 个元素，直接返回空结果

    sort(nums.begin(), nums.end());  // 排序 O(n log n)

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;  // 去重

        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                
                // 跳过重复的 left 和 right
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            } 
            else if (sum < 0) left++;  // 让 sum 变大
            else right--;  // 让 sum 变小
        }
    }
    
    return result;
}

void Test::test15() {

}