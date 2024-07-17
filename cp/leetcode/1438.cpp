#include <bits/stdc++.h>
#include <vector>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
  public:
    int longestSubarray(vector<int> &nums, int limit) {
        deque<int> maxd, mind;
        int i = 0, j;

        for (j = 0; j < nums.size(); ++j) {
            while (!maxd.empty() && nums[j] > maxd.back()) maxd.pop_back();
            while (!mind.empty() && nums[j] < mind.back()) mind.pop_back();

            maxd.push_back(nums[j]);
            mind.push_back(nums[j]);

            if (maxd.front() - mind.front() > limit) {
                if (maxd.front() == nums[i]) maxd.pop_front();
                if (mind.front() == nums[i]) mind.pop_front();
                ++i;
            }
        }

        return j - i;
    }
};

int main() {
    vector<vector<int>> nums = {
        {8, 2, 4, 7},
        {10, 1, 2, 4, 7, 2},
        {4, 2, 2, 2, 4, 4, 2, 2}
    };

    vector<int> limit = {4, 5, 0};

    Solution s;
    for (int i = 0; i < nums.size(); ++i) {
        cout << s.longestSubarray(nums[i], limit[i]) << endl;
    }

    return 0;
}