#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        priority_queue< pair<int, int>, vector<pair<int, int>> > pq;
        for (int i = 0; i < score.size(); i++) {
            pq.push({ score[i], i });
        }

        vector<string> ans(score.size());
        int idx = 1;

        while (!pq.empty()) {

            pair<int, int> temp = pq.top();
            pq.pop();
            int pos = temp.second;

            string rank = "";
            if (idx > 3) {
                rank = to_string(idx);
            }
            else if (idx == 1) {
                rank = "Gold Medal";
            }
            else if (idx == 2) {
                rank = "Silver Medal";
            }
            else {
                rank = "Bronze Medal";
            }

            ans[pos] = rank;
            idx++;
        }

        return ans;
    }
};

int main() {

    return 0;
}