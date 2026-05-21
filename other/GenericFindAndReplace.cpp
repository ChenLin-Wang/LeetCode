#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v = { 2, 4, 8, 1, 2, 36, 21};
    
    auto idx = find(v.begin(), v.end(), 8);
    cout << distance(v.end(), idx) << endl;
    
    auto reversed_idx = find(v.rbegin(), v.rend(), 8);
    cout << distance(v.rbegin(), reversed_idx) << endl;
    
    replace(v.begin(), v.end(), 2, 10);
    
    for (auto i: v) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}