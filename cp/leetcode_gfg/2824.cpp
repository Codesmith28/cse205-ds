#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution
{
public:
    int countPairs(vector<int> &nums, int target)
    {
        int n = nums.size();

        int ans = 0;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] + nums[j] < target)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int target = 5;

    cout << sol.countPairs(nums, target) << endl;

    return 0;
}