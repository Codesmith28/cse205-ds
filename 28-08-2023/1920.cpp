#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {

        vector<int> ans;
        for (auto it : nums) {
            ans.push_back(nums[it]);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 0,2,1,5,3,4 };
    vector<int> ans = s.buildArray(nums);

    for (auto it : ans) {
        cout << it << " ";
    }

    return 0;
}