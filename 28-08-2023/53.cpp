#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mxTemp = INT_MIN;
        int lastMx = 0;

        for (int i = 0; i < nums.size(); i++) {
            lastMx += nums[i];

            if (mxTemp < lastMx) {
                mxTemp = lastMx;
            }

            if (lastMx < 0) {
                lastMx = 0;
            }
        }

        return mxTemp;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
    cout << s.maxSubArray(nums) << endl;

    return 0;
}