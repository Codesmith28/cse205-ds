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

const int inf = 2e18;

struct Person {
        int x, k, m, pmask;
        // vector<int> q;
        Person(int x, int k, int m, int pmask) : x(x), k(k), m(m), pmask(pmask) {
        }
};

void solve( ) {
        int n, m, b;
        cin >> n >> m >> b;

        int x, k, mqs;
        vector<int> qs;
        vector<Person> people;
        for (int i = 0; i < n; i++) {
                int x, k, m;
                cin >> x >> k >> m;
                int probMask = 0;
                for (int j = 0; j < m; j++) {
                        int q;
                        cin >> q;
                        probMask |= (1 << (q - 1));
                }
                people.emplace_back(x, k, m, probMask);
        }

        sort(people.begin( ), people.end( ), [&](Person &a, Person &b) {
                return a.k < b.k;
        });

        int mnCost = inf;
        int queMask = (1 << m) - 1;

        vector<int> dp(queMask + 1, inf);
        dp[0] = 0;

        for (auto &it : people) {
                // calc where can the current person help:
                for (int currMask = queMask; currMask >= 0; currMask--) {
                        if (dp[currMask] == -inf) continue;
                        int nxtMask = currMask | it.pmask;
                        if (dp[nxtMask] > dp[currMask] + it.x) {
                                dp[nxtMask] = dp[currMask] + it.x;
                        }
                }

                // possible solution:
                if (dp[queMask] != inf) {
                        int maxMonitorCost = it.k * b;
                        mnCost = min(mnCost, maxMonitorCost + dp[queMask]);
                }
        }

        cout << (mnCost == inf ? -1 : mnCost) << endl;
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
