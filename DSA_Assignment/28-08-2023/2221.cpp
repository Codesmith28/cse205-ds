#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    int ans = 0;

    void reducer(vector<int>& nums) {
        if (nums.size() == 1) {
            ans = nums[0];
            return;
        }

        vector<int> temp;
        for (int i = 0; i < nums.size() - 1; i++) {
            temp.push_back((nums[i] + nums[i + 1]) % 10);
        }

        reducer(temp);
    }

    int triangularSum(vector<int>& nums) {
        reducer(nums);
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,2,3,4,5,6,7,8,9,10 };

    cout << s.triangularSum(nums) << endl;
    return 0;
}