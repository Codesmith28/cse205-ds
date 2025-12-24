#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int  long long
#define pii  pair<int, int>
#define endl "\n"

const int inf = 3e6 + 10;

void solve( ) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &i : a) cin >> i;

        int res = 0;
        for (int mx = 1; mx <= 30; mx++) { // fixing bob's number
                int currSum = 0;
                int bestSum = -inf;
                for (int i : a) {
                        int val = (i > mx) ? -inf : i; // elements out of bound are ignored like -ves
                        currSum += val;
                        currSum = max(currSum, 0LL);
                        if (val != -inf) bestSum = max(bestSum, currSum);
                }
                res = max(res, bestSum - mx);
        }

        cout << res << endl;
}

int32_t main( ) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int testCases = 1;
        // cin >> testCases;

        while (testCases--) {
                solve( );
        }

        return 0;
}
