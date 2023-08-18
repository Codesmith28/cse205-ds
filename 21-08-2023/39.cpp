#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution
{
public:
    void maker(vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums, int sum, int target, int it)
    {
        // when all iterations are completed:
        if (it == nums.size())
        {
            return;
        }

        // return without anything from the recursion if the sum > target as we don't want that
        if (sum > target)
        {
            return;
        }

        // return with the temp pushed into the answer as the condition is met:
        if (sum == target)
        {
            ans.push_back(temp);
            return;
        }

        int element = nums[it];

        // take it:
        temp.push_back(element);
        sum += element;
        maker(ans, temp, nums, sum, target, it); // we will not move the iterator as we can take the same element again

        // don't take it:
        temp.pop_back();
        sum -= element;
        maker(ans, temp, nums, sum, target, it + 1);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        int it = 0;
        int sum = 0;

        maker(ans, temp, candidates, sum, target, it);
        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans = sol.combinationSum(nums, target);

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