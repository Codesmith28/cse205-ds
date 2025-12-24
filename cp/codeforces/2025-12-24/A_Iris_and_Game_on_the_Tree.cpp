#include <algorithm>
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
    int n;
    cin >> n;
    map<int, int> deg;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        deg[u]++, deg[v]++;
    }
    string s;
    cin >> s;

    // number of transitions -> odd [wt = 0] / even [wt = 1]
    // hence in odd transitions -> root == leaf
    // hence net weight of tree -> # of (root != leaf) pairs
    // degree of root -> 1

    int leafZero, leafOne, leafUnk, midUnk;
    leafZero = leafOne = leafUnk = midUnk = 0;

    for (int i = 1; i < n; i++) {
        if (deg[i] == 1) {
            if (s[i] == '0') {
                leafZero++;
            } else if (s[i] == '1') {
                leafOne++;
            } else {
                leafUnk++;
            }
        } else {
            midUnk += s[i] == '?';
        }
    }

    char root = s[0];
    int res = 0;

    if (root == '0') {
        res = leafOne + (leafUnk + 1) / 2;
    } else if (root == '1') {
        res = leafZero + (leafUnk + 1) / 2;
    } else {
        if (leafZero == leafOne) {
            int cnt = leafZero; // or leafOne
            res = cnt + (leafUnk + (midUnk % 2)) / 2;
        } else {
            int mx = max(leafZero, leafOne);
            res = mx + leafUnk / 2;
        }
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