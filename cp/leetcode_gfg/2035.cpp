#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define ll long long
class Solution {
  public:
    int finder(set<int> &leftsum, set<int> &rightsum, int total) {
        int lsz = leftsum.size(), rsz = rightsum.size();
        int mn = INT_MAX;

        for (int ls : leftsum) {
            int target = total / 2 - ls;
            auto lb = rightsum.lower_bound(target);
            int sum = 0;
            if (lb != rightsum.end()) {
                sum = *lb;
            } else if (!rightsum.empty()) {
                sum = *rightsum.rbegin();
            }
            mn = min(mn, abs(total - 2 * (ls + sum)));
        }

        return mn;
    }

    int minimumDifference(vector<int> &nums) {
        int n = nums.size();
        int n1 = n / 2;
        int total = accumulate(nums.begin(), nums.end(), 0);

        vector<int> left(nums.begin(), nums.begin() + n1);
        vector<int> right(nums.begin() + n1, nums.end());
        vector<set<int>> leftsum(n1 + 1), rightsum(n1 + 1);

        for (int i = 0; i < (1 << n1); i++) {
            int lsum = 0, rsum = 0, cnt = 0;
            for (int j = 0; j < n1; j++) {
                if (i & (1 << j)) {
                    lsum += left[j];
                    rsum += right[j];
                    cnt++;
                }
            }
            leftsum[cnt].insert(lsum);
            rightsum[cnt].insert(rsum);
        }

        int mn = INT_MAX;
        for (int i = 0; i < n1; i++) mn = min(mn, finder(leftsum[i], rightsum[n - i], total));
        return mn;
    }
};

int main() {
    return 0;
}