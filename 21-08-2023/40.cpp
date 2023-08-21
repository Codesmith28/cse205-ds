#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution
{
public:
    void maker(vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums, int sum, int target, int it)
    {

        // return with the temp pushed into the answer as the condition is met:
        if (sum == target)
        {
            ans.push_back(temp);
            return;
        }

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

        int element = nums[it];

        // take it:
        temp.push_back(element);
        sum += element;
        maker(ans, temp, nums, sum, target, it + 1);

        // ignore the consecutive same elements => solution for memory limit exceeded
        while ((it + 1 < nums.size()) and nums[it] == nums[it + 1])
        {
            it++;
        }

        // don't take it:
        temp.pop_back();
        sum -= element;
        maker(ans, temp, nums, sum, target, it + 1);
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;
        int it = 0;
        int sum = 0;

        maker(ans, temp, candidates, sum, target, it);

        // remove duplicates:
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> ans = sol.combinationSum2(candidates, target);

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