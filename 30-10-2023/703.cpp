#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class KthLargest {
public:

    priority_queue<int, vector<int>, greater<int>> pq;
    int position;

    KthLargest(int k, vector<int>& nums) {
        position = k;
        for (auto it : nums) {
            pq.push(it);
            if (pq.size() > k) {
                pq.pop();
            }
        }
    }

    int add(int val) {
        if (pq.size() < position) {
            pq.push(val);
        }
        else  if (pq.top() < val) {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main() {

    return 0;
}