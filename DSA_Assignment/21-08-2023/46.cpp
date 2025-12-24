#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution
{
public:
    void maker(vector<vector<int>> &ans, vector<int> &mask, vector<int> &nums, int it)
    {
        if (it == nums.size())
        {
            ans.push_back(mask);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (mask[i] == 1e9)
            {
                // unmask the i-th element with the it-th element from nums
                mask[i] = nums[it];
                // call maker with the changed mask
                maker(ans, mask, nums, it + 1);
                // remask the i-th element
                mask[i] = 1e9;
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {

        int n = nums.size();

        vector<vector<int>> ans;
        vector<int> mask(n, 1e9);
        int it = 0;

        maker(ans, mask, nums, it);
        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = sol.permute(nums);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}