#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:

    bool isConsec(vector<int> v) {
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i + 1] - v[i] != 1) {
                return false;
            }
        }
        return true;
    }

    bool isNStraightHand(vector<int>& hand, int grpSize) {
        unordered_map<int, int> fq;

        for (auto it : hand) {
            fq[it]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto it : fq) {
            pq.push(it.first);
        }

        while (!pq.empty()) {
            vector<int> temp; // to store the answer

            // making the groups:
            for (int i = 0; i < grpSize; i++) {
                if (!pq.empty()) {
                    temp.push_back(pq.top());
                    pq.pop();
                }
            }

            // re-inserting all used elements as per their fq:
            for (int i = 0; i < temp.size(); i++) {
                if (--fq[temp[i]] > 0) {
                    pq.push(temp[i]);
                }
            }

            // validating the group formed
            if (temp.size() == grpSize) {
                if (!isConsec(temp)) {
                    return false;
                }
            }
            else {
                return false;
            }
        }

        return true;
    }
};

int main() {

    return 0;
}