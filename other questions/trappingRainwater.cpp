#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();

        vector<int> rightMax(n);
        vector<int> leftMax(n);

        rightMax[n - 1] = height[n - 1];
        leftMax[0] = height[0];

        int tempMaxR = height[n - 1];
        int tempMaxL = height[0];

        // for right max:
        for (int i = n - 2; i >= 0; i--)
        { // Start from index n-2
            rightMax[i] = max(height[i + 1], tempMaxR);
            tempMaxR = rightMax[i];
        }

        // for left max:
        for (int i = 1; i < n; i++)
        { // Start from index 1
            leftMax[i] = max(height[i - 1], tempMaxL);
            tempMaxL = leftMax[i];
        }

        // now to add up to the answer:
        int water = 0;
        for (int i = 0; i < n; i++)
        {
            int temp = min(leftMax[i], rightMax[i]) - height[i];
            water += max(temp, 0);
        }

        return water;
    }
};
