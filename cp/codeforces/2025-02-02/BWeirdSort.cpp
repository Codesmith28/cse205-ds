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
const int ninf = -inf;
int mod = 1e9 + 7;

void solve( ) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), p(n);
    for (int &i : a) cin >> i;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        p[x - 1] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (p[i] == 0) continue;
        int j = i;
        while (j < n && p[j] == 1) j++;
        sort(a.begin( ) + i, a.begin( ) + j + 1);
        i = j;
    }

    bool flag = true;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            flag = false;
            break;
        }
    }

    cout << (flag ? "YES" : "NO") << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solve( );
    }

    return 0;
}
