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

// number of BSTs with n distinct nodes and height atleast h
void solve( ) {
    int n, h;
    cin >> n >> h;

    // tree[n][h] = no. of BSTs with n nodes and height h
    vector<vector<int>> tree(n + 1, vector<int>(n + 1, 0));
    tree[0][0] = 1;
    for (int i = 1; i <= n; i++) tree[i][0] = 0;
    for (int i = 1; i <= n; i++) tree[0][i] = 0;

    // root val = m
    // h[root] = 1 + max(h[left] + h[right])
    // h[left] = h - 1 / h[right] = h - 1

    // h[left] = h - 1 :
    // left has tree[m - 1][h - 1] trees
    // right has tree[n - m][j] trees, j in [0, h-1]
    // total trees: tree[m - 1][h - 1] * sum_j(tree[n - m][j]) for first half

    // same for h[right] = h - 1
    // but j in [0, h - 2] in left to prevent double counting

    for (int nodes = 1; nodes <= n; nodes++) {
        for (int hei = 1; hei <= n; hei++) {
            for (int root = 1; root <= nodes; root++) {
                int lnodes = root - 1;
                int rnodes = nodes - root;

                int rsum = 0;
                int lsum = 0;

                for (int j = 0; j <= hei - 1; j++) rsum += tree[rnodes][j];
                for (int j = 0; j <= hei - 2; j++) lsum += tree[lnodes][j];

                tree[nodes][hei] += tree[lnodes][hei - 1] * rsum;
                tree[nodes][hei] += tree[rnodes][hei - 1] * lsum;
            }
        }
    }

    int res = 0;
    for (int i = h; i <= n; i++) res += tree[n][i];
    cout << res << endl;
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