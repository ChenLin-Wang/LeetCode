#include "../header.h"

int Solution::bestSightseeingPair(vector<int>& values) {
    int max = 0;
    for (int i = 0; i < values.size() - 1; i++) {
        for (int j = i + 1; j < values.size(); j++) {
            int v = values[i] + values[j] + i - j;
            if (max < v) max = v;
        }
    }
    return max;
}

void Test::test1014() {
    vector<int> values = {8, 1, 5, 2, 6};
    cout << Solution::bestSightseeingPair(values) << endl;
}