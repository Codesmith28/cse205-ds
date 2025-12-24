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

void solve( ) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &i : a) cin >> i;

        // i < j < k < l and a[i] == a[k] && a[j] == a[l]
        // fix j and k and count how many i (pref) and l (suff) are there

        map<int, int> pref, suff;
        int res = 0;

        for (int j = 0; j < n; j++) {
                suff.clear( );
                for (int k = n - 1; k > j; k--) {
                        res += pref[a[k]] * suff[a[j]];
                        suff[a[k]]++;
                }
                pref[a[j]]++;
        }

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
