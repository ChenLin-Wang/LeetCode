#include<iostream>
#include<queue>
#include<functional>

using namespace std;

bool Compare(int i1, int i2) {
    return i1 > i2;
}

int main() {
    
    priority_queue<int, vector<int>, function<bool(int, int)>> q(Compare);
    
    q.push(10);
    q.push(1);
    q.push(9);
    q.push(12);
    q.push(3);
    
    int s = q.size();
    
    for (int i = 0; i < s; i++) {
        cout << q.top() << endl;
        q.pop();
    }
    
    return 0;
}