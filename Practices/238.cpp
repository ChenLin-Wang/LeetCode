#include "header.h"

vector<int> Solution::productExceptSelf(vector<int>& nums) {
    vector<int> res(nums.size());
    int i;
    int v = 1;
    for (i = 0; i < nums.size(); i ++) {
        res[i] = v;
        v *= nums[i];
    }
    v = 1;
    for (i = nums.size() - 1; i >= 0; i--) {
        res[i] *= v;
        v *= nums[i];
    }
    return res;
}


void Test::test238() {
    vector<int> inp = {1, 2, 3, 4};
    vector<int> res = Solution::productExceptSelf(inp);
    for (auto i : res) {
        cout << i << endl;
    }
}