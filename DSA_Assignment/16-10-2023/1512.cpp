#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {

        int ans = 0;
        unordered_map<int, int> mp;
        for (int it : nums) {
            mp[it]++;
        }

        for (auto it : mp) {
            int n = it.second;
            ans += (n) * (n - 1) / 2;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 1,2,3,1,1,3 };
    cout << sol.numIdenticalPairs(nums) << endl;
    return 0;
}