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

void solve( ) {
    int n;
    cin >> n;
    vector<vector<int>> abp(n, vector<int>(3));
    for (int i = 0; i < n; i++) cin >> abp[i][0] >> abp[i][1] >> abp[i][2]; // st, en, val

    vector<int> memo(n);
    memo[0] = abp[0][2];

    sort(abp.begin( ), abp.end( ), [](const vector<int> &a, const vector<int> &b) {
        return a[1] < b[1];
    });

    auto bin_srch = [&](int idx) -> int {
        int low = 0, high = idx - 1;
        int res = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (abp[mid][1] < abp[idx][0]) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    };

    for (int i = 1; i < n; i++) {
        int not_take = memo[i - 1];
        int take = abp[i][2];
        int last_end = bin_srch(i);
        if (last_end != -1) take += memo[last_end];
        memo[i] = max(take, not_take);
    }

    cout << memo[n - 1] << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    /*cin >> testCases;*/

    while (testCases--) {
        solve( );
    }

    return 0;
}
