#include <algorithm>
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
    vector<int> a(n);
    for (int &i : a) cin >> i;

    map<int, int> fq;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (a[i] >= a[j]) {
                fq[i]++;
            }
        }
    }

    // dbg(fq);

    int mx = 0;
    for (auto it : fq) {
        mx = max(mx, it.second);
    }

    cout << n - mx << endl;
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