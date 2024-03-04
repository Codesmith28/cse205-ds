#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> pq;
        for (auto it : stones) {
            pq.push(it);
        }

        while (!pq.empty()) {
            int a = pq.top();
            pq.pop();

            if (pq.empty()) {
                return a;
            }
            else {
                int b = pq.top();
                pq.pop();

                pq.push(abs(a - b));
            }
        }

        return 0;
    }
};

int main() {

    return 0;
}