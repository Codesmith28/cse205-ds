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
    long long minCost(vector<int> &bask1, vector<int> &bask2) {
        using ll = long long;
        sort(bask1.begin( ), bask1.end( ));
        sort(bask2.begin( ), bask2.end( ));

        map<int, int> cnt1, cnt2;
        set<int> all;
        for (int i : bask1) cnt1[i]++, all.insert(i);
        for (int i : bask2) cnt2[i]++, all.insert(i);

        for (int i : all) {
            if ((cnt1[i] + cnt2[i]) & 1) return -1;
        }

        int mn = *all.begin( );
        vector<int> extra1, extra2;

        // Collect surplus
        for (int i : all) {
            int c1 = cnt1[i], c2 = cnt2[i];
            int diff = abs(c1 - c2);
            diff /= 2;
            if (c1 > c2) {
                for (int k = 0; k < diff; k++) extra1.push_back(i);
            } else if (c2 > c1) {
                for (int k = 0; k < diff; k++) extra2.push_back(i);
            }
        }

        sort(extra1.begin( ), extra1.end( ));
        sort(extra2.rbegin( ), extra2.rend( ));

        ll cost = 0;
        for (int i = 0; i < extra1.size( ); i++) {
            int case1 = 2 * mn;                    // swap via mn element
            int case2 = min(extra1[i], extra2[i]); // swap 2 elements
            cost += min(case1, case2);
        }

        return cost;
    }
};

// [4,2,2,2]
// [1,4,1,2]
// [2,3,4,1]
// [3,2,5,1]

int main( ) {
    vector<vector<int>> basket1 = {
        {4, 2, 2, 2},
        {2, 3, 4, 1},
        {84, 80, 43, 8, 80, 88, 43, 14, 100, 88}
    };
    vector<vector<int>> basket2 = {
        {1, 4, 1, 2},
        {3, 2, 5, 1},
        {32, 32, 42, 68, 68, 100, 42, 84, 14, 8}
    };
    Solution sol;
    for (int i = 0; i < basket1.size( ); i++) cout << sol.minCost(basket1[i], basket2[i]) << endl;
    return 0;
}
