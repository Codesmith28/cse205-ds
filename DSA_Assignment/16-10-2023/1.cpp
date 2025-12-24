#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int i, j;
        bool flag = false;

        vector<int> ans;

        map<int, int> idx;

        for (int i = 0; i < nums.size(); i++) {
            if (idx.find(target - nums[i]) != idx.end()) {
                return { i, idx[target - nums[i]] };
            }
            idx[nums[i]] = i;
        }

        return {};
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 2,7,11,15 };
    vector<int> ans = sol.twoSum(nums, 9);

    for (int it : ans) {
        cout << it << " ";
    } cout << endl;

    return 0;
}