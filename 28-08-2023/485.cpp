#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int ans = 0;
        int temp = 0;
        for (auto it : nums) {

            if (it != 1) {
                ans = max(ans, temp);
                temp = 0;
            }
            else {
                temp++;
            }
        }
        ans = max(ans, temp);

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,1,0,1,1,1 };
    cout << s.findMaxConsecutiveOnes(nums) << endl;

    return 0;
}