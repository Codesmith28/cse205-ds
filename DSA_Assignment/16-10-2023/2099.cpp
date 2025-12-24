#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp.push_back({ nums[i], i });
        }

        // sorted by value:
        sort(rbegin(mp), rend(mp));
        vector<pair<int, int>> idx;

        for (int i = 0; i < k; i++) {
            idx.push_back({ mp[i].second, mp[i].first });
        }

        sort(begin(idx), end(idx));

        // for(auto it: idx) {
        //     cout << it.first << " " << it.second << endl;
        // }

        vector<int> ans;
        for (auto it : idx) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 1,2,2,4 };
    vector<int> ans = sol.maxSubsequence(nums, 2);

    for (int it : ans) {
        cout << it << " ";
    } cout << endl;

    return 0;
}