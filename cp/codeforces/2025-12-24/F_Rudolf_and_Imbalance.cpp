#include <bits/stdc++.h>
#include <cstdlib>
#include <utility>
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

const int inf = 1e18;
const int ninf = -1 * inf;

void solve( ) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(n), models(m), funcs(k);
    for (int &i : arr) cin >> i;
    for (int &i : models) cin >> i;
    for (int &i : funcs) cin >> i;

    sort(arr.begin( ), arr.end( ));
    sort(models.begin( ), models.end( ));
    sort(funcs.begin( ), funcs.end( ));

    int mxDiff1, mxDiff2, idx;
    mxDiff1 = mxDiff2 = idx = 0;

    for (int i = 1; i < n; i++) {
        int diff = arr[i] - arr[i - 1];
        mxDiff2 = max(mxDiff2, diff);
        if (mxDiff2 > mxDiff1) {
            swap(mxDiff1, mxDiff2);
            idx = i;
        }
    }

    int res = mxDiff1;
    int target = (arr[idx] + arr[idx - 1]) / 2;

    auto searchFunc = [&](int model) -> void {
        int key = target - model;
        auto it = lower_bound(funcs.begin( ), funcs.end( ), key);
        int elem;

        // before it : <= key : elem just <= target
        if (it != funcs.begin( )) {
            elem = model + *(it - 1);
            res = min(res, max({mxDiff2, abs(elem - arr[idx]), abs(elem - arr[idx - 1])}));
        }

        // at it : >= key : elem just >= target
        if (it != funcs.end( )) {
            elem = model + *it;
            res = min(res, max({mxDiff2, abs(elem - arr[idx]), abs(elem - arr[idx - 1])}));
        }
    };

    // fix model and binary search on func
    for (int &x : models) searchFunc(x);
    cout << res << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        solve( );
    }

    return 0;
}