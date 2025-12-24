#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class MinStack {
public:

    vector< pair<int, int> > v;

    MinStack() {

    }

    void push(int val) {
        if (v.empty()) {
            v.push_back({ val, val });
        }
        else {
            v.push_back({ val, min(v.back().second, val) });
        }
    }

    void pop() {
        v.pop_back();
    }

    int top() {
        return v.back().first;
    }

    int getMin() {
        return v.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    MinStack* obj = new MinStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    obj->push(5);

    cout << obj->getMin() << endl;
    obj->pop();
    return 0;
}