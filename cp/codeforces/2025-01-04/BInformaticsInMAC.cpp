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

const int inf = 1e18;
const int ninf = -1 * inf;
int mod = 1e9 + 7;

void solve( ) {
    int n;
    cin >> n;

    vector<int> a(n);
    map<int, int> fq1, fq2;

    for (int &x : a) {
        cin >> x;
        fq2[x]++;
    }

    int mex1 = 0, mex2 = 0;
    while (fq2[mex2]) mex2++;

    for (int i = 0; i < n; ++i) {
        fq1[a[i]]++;
        fq2[a[i]]--;

        if (fq2[a[i]] == 0 && mex2 > a[i]) mex2 = a[i];

        // Update mex1 and mex2
        while (fq1[mex1]) mex1++;
        while (mex2 && fq2[mex2 - 1] == 0) mex2--;

        if (mex1 == mex2) {
            cout << 2 << endl;
            cout << 1 << " " << i + 1 << endl;
            cout << i + 2 << " " << n << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    cin >> test_cases;

    while (test_cases--) {
        solve( );
    }

    return 0;
}
