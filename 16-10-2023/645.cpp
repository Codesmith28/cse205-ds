#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> fq;
        int sum = 0;
        int n = nums.size();

        int a;

        for (int it : nums) {
            fq[it]++;
            sum += it;
            if (fq[it] >= 2) {
                a = it;
            }
        }

        int all = (n) * (n + 1) / 2;
        int b = abs(all - sum + a);

        return { a, b };
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 1,2,2,4 };
    vector<int> ans = sol.findErrorNums(nums);

    return 0;
}