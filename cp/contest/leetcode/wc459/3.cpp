#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
  public:
    using ll = long long;
    const int mxd = 4; // 63 -> 6 -> 2 -> 1

    struct BIT {
        int n;
        vector<int> tree;

        BIT(int size) {
            n = size + 2;
            tree.assign(n + 1, 0); // 1-based indexing
        }

        /// Add `val` to index `i` (1-based)
        void update(int i, int val) {
            i++;
            while (i <= n) {
                tree[i] += val;
                i += (i & -i);
            }
        }

        /// Prefix sum query: sum of elements in [1, i] (1-based)
        int query(int i) {
            i++;
            int res = 0;
            while (i > 0) {
                res += tree[i];
                i -= (i & -i);
            }
            return res;
        }

        /// Range sum query: sum of elements in [l, r] (1-based)
        int range_query(int l, int r) {
            return query(r) - query(l - 1);
        }
    };

    vector<int> popcountDepth(vector<long long> &nums, vector<vector<long long>> &queries) {
        int n = nums.size( );
        vector<int> depth(n);

        auto popdepth = [&](ll x) -> int {
            int d = 0;
            while (x > 1) {
                x = __builtin_popcountll(x);
                d++;
            }
            return d;
        };

        for (int i = 0; i < n; i++) depth[i] = popdepth(nums[i]);

        // Fenwick trees for each depth
        vector<BIT> trees(mxd + 1, BIT(n));
        for (int i = 0; i < n; i++) {
            trees[depth[i]].update(i, 1);
        }

        vector<int> res;
        for (auto &q : queries) {
            if (q[0] == 1) {
                int l = q[1], r = q[2], k = q[3];
                res.push_back(trees[k].range_query(l, r));
            } else {
                int idx = q[1];
                ll val = q[2];

                int oldd = depth[idx];
                trees[oldd].update(idx, -1); 

                int newd = popdepth(val);
                depth[idx] = newd;
                nums[idx] = val;
                trees[newd].update(idx, 1); 
            }
        }

        return res;
    }
};

int main( ) {
    vector<vector<long long>> nums = {
        {2, 4},
        {3, 5, 6},
        {1, 2},
    };
    vector<vector<vector<long long>>> queries = {
        {{1, 0, 1, 1}, {2, 1, 1}, {1, 0, 1, 0}},
        {{1, 0, 2, 2}, {2, 1, 4}, {1, 1, 2, 1}, {1, 0, 1, 0}},
        {{1, 0, 1, 1}, {2, 0, 3}, {1, 0, 0, 1}, {1, 0, 0, 2}},
    };

    Solution sol;
    for (int i = 0; i < nums.size( ); i++) {
        vector<int> ans = sol.popcountDepth(nums[i], queries[i]);
        for (int j = 0; j < ans.size( ); j++) {
            cout << ans[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
