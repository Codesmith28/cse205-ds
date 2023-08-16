#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        // consider the max of first k elements then:
        // replace the elements in the list with largest element found yet

        vector<int> ans;
        int n = nums.size();

        // iterative approach:
        for (int i = 0; i <= n - k; i++)
        {
            int max = nums[i];
            for (int j = i; j < i + k; j++)
            {
                if (nums[j] > max)
                {
                    max = nums[j];
                }
            }
            ans.push_back(max);
        }

        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> ans = obj.maxSlidingWindow(nums, k);

    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}