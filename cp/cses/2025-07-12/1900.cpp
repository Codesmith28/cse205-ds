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
    vector<int> earliestAndLatest(int n, int fp, int sp) {
    }
};

int main( ) {
    vector<int> n = {11, 5};
    vector<int> fp = {2, 1};
    vector<int> sp = {4, 5};
    Solution sol;
    for (int i = 0; i < n.size( ); i++) {
        vector<int> ans = sol.earliestAndLatest(n[i], fp[i], sp[i]);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}