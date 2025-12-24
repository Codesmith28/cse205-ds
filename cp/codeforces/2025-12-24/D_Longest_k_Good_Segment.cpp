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

void solve( ) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    map<int, int> fq;
    int rmx = n, lmx = 1, mxlen = 0;

    // to find the longest segment with atmost k distinct elements
    // return the start (l) and end (r) of the resultant segment

    int l = 0;
    for (int r = 0; r < n; r++) {
        fq[a[r]]++;
        while (fq.size( ) > k) {
            fq[a[l]]--;
            if (fq[a[l]] == 0) fq.erase(a[l]);
            l++;
        }
        if (r - l + 1 > mxlen) {
            mxlen = r - l + 1;
            lmx = l;
            rmx = r;
        }
    }

    cout << lmx + 1 << " " << rmx + 1 << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    // cin >> test_cases;

    while (test_cases--) {
        solve( );
    }

    return 0;
}