#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        vector<string> temp;
        for (auto it : nums) {
            temp.push_back(to_string(it));
        }

        int ans = 0;
        for (auto it : temp) {
            if (it.length() % 2 == 0) {
                ans++;
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 12,345,2,6,7896 };
    cout << s.findNumbers(nums) << endl;

    return 0;
}