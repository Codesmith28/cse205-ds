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

        // min continuous strokes need to paint the fence (horizontal or vertical)
        auto recur = [&](auto &&go, int l, int r, int hCovered) -> int {
                if (l > r) return 0;
                int vCost = (r - l + 1);

                int mn = *min_element(a.begin( ) + l, a.begin( ) + r + 1);
                int hCost = mn - hCovered;

                int prev = l;
                for (int i = l; i <= r; i++) {
                        if (a[i] == mn) { // break encountered
                                hCost += go(go, prev, i - 1, mn);
                                prev = i + 1;
                        }
                }
                hCost += go(go, prev, r, mn);

                return min(hCost, vCost);
        };

        cout << recur(recur, 0, n - 1, 0) << endl;
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
