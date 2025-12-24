#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "../debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
      public:
        long long maxSubarrays(int n, vector<vector<int>> &conflict) {
                using ll = long long;
                vector<vector<int>> adj(n + 1);
                for (auto it : conflict) adj[it[1]].push_back(it[0]);
        }
};

int main( ) {
        Solution sol;
        vector<int> n = {
            4,
            5,
        };
        vector<vector<vector<int>>> conflict = {
            {{2, 3}, {1, 4}},
            {{1, 2}, {2, 5}, {3, 5}},
        };
        for (int i = 0; i < n.size( ); i++) {
                cout << sol.maxSubarrays(n[i], conflict[i]) << endl;
        }
        return 0;
}