#include <bits/stdc++.h>
#include <climits>
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

        int res = 0;
        for (int i = 0; i < n; i++) res += (i % 2 == 0 ? a[i] : -a[i]);
        dbg(res, n);

        // first can always reverse the operation of second, thus second cannot gain any advantage from swapping -> always ends
        // first -> end game | swap any two and add to the cost
        // final ansewr >= res

        // swap cases -> same pairity swap | different parity swap
        // same pairity swap -> answer += abs(idx diff)

        int res1 = res;
        if ((n - 1) % 2 == 0) {
                res1 = max(res, res + n - 1);
        } else {
                res1 = max(res, res + n - 2);
        }

        // diff pairity swap -> answer += abs(idx diff) -( -a[o] + a[e]) + (a[o] - a[e]) = abs(idx diff) + 2 * (a[o] - a[e])

        // i > j:
        // when i = even, j = odd : gain = i - j + 2 * (a[j] - a[i]) => (i - 2*a[i]) + (2*a[j] - j) => (i - 2 * a[i]) - (j - 2 * a[j])
        // when i = odd, j = even : gain = i - j + 2 * (a[i] - a[j]) => (2*a[i] + i) + (-2*a[j] - j) => (2 * a[i] + i) - (2 * a[j] + j)

        int mnOdd = INT_MAX, mnEven = INT_MAX;
        int cost = 0;
        for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                        if (mnOdd != INT_MAX) cost = max(cost, (i - 2LL * a[i]) - mnOdd);
                        mnEven = min(mnEven, 2LL * a[i] + i);
                } else {
                        if (mnEven != INT_MAX) cost = max(cost, (i + 2LL * a[i]) - mnEven);
                        mnOdd = min(mnOdd, i - 2LL * a[i]);
                }
        }
        int res2 = res + cost;

        cout << max(res1, res2) << endl;
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
