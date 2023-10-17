#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> idx;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (idx.count(nums[i])) {
                bool c = abs(i - idx[nums[i]]) <= k;
                if (c) {
                    return true;
                }
            }

            idx[nums[i]] = i;
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = { 1,2,3,1,2,3 };
    cout << s.containsNearbyDuplicate(nums, 2) << endl;

    return 0;
}