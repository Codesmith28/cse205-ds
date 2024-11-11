#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* (╯°□°)╯︵ ┻━┻ */

class Solution {
  public:
    int maxFrequency(vector<int> &n, int k, int numOperations) {
    }
};

int main( ) {
    int sz = 1;
    vector<vector<int>> n = {
        {1, 4, 5},
        {5, 11, 20, 20},
    };
    vector<int> k = {1, 5};
    vector<int> ops = {2, 1};
    sz = n.size( );
    Solution s;
    for (int i = 0; i < sz; i++) cout << s.maxFrequency(n[i], k[i], ops[i]) << endl;
    return 0;
}
