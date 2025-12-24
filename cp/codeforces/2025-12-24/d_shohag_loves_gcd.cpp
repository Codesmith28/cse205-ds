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
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (int &i : a) cin >> i;

        // divisor list
        vector<vector<int>> divisors(n + 1);
        for (int i = 1; i <= n; i++) {
                for (int j = i + i; j <= n; j += i) {
                        divisors[j].push_back(i);
                }
        }

        /*
         * if i divides j
         *      => gcd(i, j) = i
         *      => a_gcd(i, j) = a_i
         *      => cond: a_i != gcd(a_i, a_j) => a_i should not divide a_j
         * */

        sort(a.begin( ), a.end( ));
        vector<int> res(n + 1, -1);

        for (int i = 1; i <= n; i++) {
                set<int> banned; // banned values
                for (int d : divisors[i]) {
                        if (res[d] != -1) banned.insert(res[d]);
                }

                // pick largest possible value not banned
                for (int idx = (int)a.size( ) - 1; idx >= 0; idx--) {
                        if (banned.find(a[idx]) == banned.end( )) {
                                res[i] = a[idx];
                                break;
                        }
                }

                if (res[i] == -1) {
                        cout << -1 << endl;
                        return;
                }

                dbg(i, banned, res);
        }

        for (int i = 1; i <= n; i++) cout << res[i] << " ";
        cout << endl;
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
