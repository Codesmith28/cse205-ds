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
        vector<vector<int>> a(n, vector<int>(m, 0));
        vector<vector<int>> b(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) cin >> a[i][j];
        for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) cin >> b[i][j];

        auto transpose = [&](vector<vector<int>> &mat) -> vector<vector<int>> {
                int r = mat.size( );
                int c = mat[0].size( );
                vector<vector<int>> res(c, vector<int>(r, 0));
                for (int i = 0; i < r; i++) {
                        for (int j = 0; j < c; j++) {
                                res[j][i] = mat[i][j];
                        }
                }
                return res;
        };

        vector<vector<int>> aT = transpose(a);
        vector<vector<int>> bT = transpose(b);

        for (auto &it : a) sort(it.begin( ), it.end( ));
        for (auto &it : b) sort(it.begin( ), it.end( ));
        for (auto &it : aT) sort(it.begin( ), it.end( ));
        for (auto &it : bT) sort(it.begin( ), it.end( ));

        sort(a.begin( ), a.end( ));
        sort(b.begin( ), b.end( ));
        sort(aT.begin( ), aT.end( ));
        sort(bT.begin( ), bT.end( ));

        if (a == b && aT == bT) {
                cout << "YES" << endl;
        } else {
                cout << "NO" << endl;
        }
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
