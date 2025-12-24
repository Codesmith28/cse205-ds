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
