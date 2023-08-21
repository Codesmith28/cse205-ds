#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution
{
public:
    void maker(vector<int> &nums, vector<vector<int>> &curr, vector<int> tempo, int i, int n)
    {
        if (i >= n)
        {
            curr.push_back(tempo);
            return;
        }

        // curr.push_back(tempo);

        int entry = nums[i];
        maker(nums, curr, tempo, i + 1, n);

        tempo.push_back(entry);
        sort(tempo.begin(), tempo.end());

        maker(nums, curr, tempo, i + 1, n);
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> curr;
        int i = 0;
        vector<int> tempo;

        maker(nums, curr, tempo, i, n);

        // remove duplicates from the curr:
        sort(curr.begin(), curr.end());
        curr.erase(unique(curr.begin(), curr.end()), curr.end());

        return curr;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1, 2, 2};    
    vector<vector<int>> ans = sol.subsetsWithDup(nums);

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