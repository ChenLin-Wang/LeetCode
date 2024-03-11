#include "../header.h"


void solution1(vector<int>& nums, int k) {
    int i = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + i);
    reverse(nums.begin() + i, nums.end());
}


void Solution::rotate(vector<int>& nums, int k) {
    solution1(nums, k);
}


void Test::test189(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    Solution::rotate(nums, 20);

    for (auto i : nums) {
        cout << i << endl;
    }

}