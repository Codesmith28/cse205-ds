#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp = nums;

        vector<int> ans;

        // using double array instead of the single one:
        for (int i = 0; i < nums.size();i++) {
            temp.push_back(nums[i]);
        }

        // iterative solution:
        for (int i = 0; i < n; i++) {
            int x = temp[i];
            int j = i + 1;
            while (j < temp.size()) {
                if (temp[j] > x) {
                    x = temp[j];
                    break;
                }
                j++;
            }

            if (x != temp[i]) {
                ans.push_back(x);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = { 1,2,1 };
    vector<int> ans = sol.nextGreaterElements(nums);

    for (auto x : ans) {
        cout << x << " ";
    }cout << endl;


    return 0;
}