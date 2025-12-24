#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
    int a, b;
    cin >> a >> b;

    int mx = max(a, b);
    vector<vector<int>> memo(mx + 1, vector<int>(mx + 1, -1));

    for (int h_cut = 0; h_cut <= a; h_cut++) {
        for (int v_cut = 0; v_cut <= b; v_cut++) {
            if (h_cut == v_cut) {
                memo[h_cut][v_cut] = 0;
            } else {
                memo[h_cut][v_cut] = INT_MAX;
                // best possible h_cut
                for (int poss = 1; poss < h_cut; poss++) memo[h_cut][v_cut] = min(memo[h_cut][v_cut], memo[poss][v_cut] + memo[h_cut - poss][v_cut] + 1);
                // best possible v_cut
                for (int poss = 1; poss < v_cut; poss++) memo[h_cut][v_cut] = min(memo[h_cut][v_cut], memo[h_cut][poss] + memo[h_cut][v_cut - poss] + 1);
            }
        }
    }

    /*for (int i = 0; i <= mx; i++) {*/
    /*    for (int j = 0; j <= mx; j++) {*/
    /*        cout << memo[i][j] << " ";*/
    /*    }*/
    /*    cout << endl;*/
    /*}*/

    cout << memo[a][b] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}
