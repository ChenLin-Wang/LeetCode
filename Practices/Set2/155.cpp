#include "../header.h"

class MinStack {
public:

    vector<int> stack;
    int topi;
    bool gotMin;
    int min;

    MinStack() {
        stack = {};
        topi = -1;
        min = -1;
        gotMin = false;
    }
    
    void push(int val) {
        stack.push_back(val);
        topi ++;
        if (gotMin) {
            if (val < min) min = val;
        } else {
            gotMin = true;
            min = val;
        }
    }
    
    void pop() {
        int val = stack[topi];
        stack.pop_back();
        topi--;
        if (topi == -1) {
            gotMin = false;
            min = -1;
            return;
        }
        if (val == min) {
            int mini = stack[0];
            for (auto i : stack) {
                if (i < mini) mini = i;
            }
            min = mini;
        }
    }
    
    int top() {
        return stack[topi];
    }
    
    int getMin() {
        return min;
    }
};

void Test::test155() {
    
}