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
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = {x + i, i};
    }

    sort(a.begin( ), a.end( ), [&](pii &x, pii &y) {
        if (x.first == y.first) {
            return x.second > y.second;
        }
        return x.first > y.first;
    });

    map<int, int> mp;
    bool flag = false;
    for (auto it : a) {
        int sum = it.first + it.second;
        if (it.first == n) flag = true;
        if (mp.find(sum) == mp.end( )) {
            mp[it.first] = max(mp[it.first], sum);
        } else {
            mp[it.first] = max(mp[it.first], mp[sum]);
        }
    }

    cout << (flag ? mp[n] : n) << endl;
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