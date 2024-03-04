#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int, vector<int>> pq;
        for (auto it : nums) {
            pq.push(it);
        }

        int ans = 1;
        for (int i = 0; i < 2; i++) {
            int temp = pq.top();
            pq.pop();
            cout << temp << endl;
            ans *= (temp - 1);
        }

        return ans;
    }
};

int main() {

    return 0;
}