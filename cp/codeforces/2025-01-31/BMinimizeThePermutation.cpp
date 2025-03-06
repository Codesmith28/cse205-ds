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
int mod = 1e9 + 7;

void solve( ) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    vector<bool> vis(n, false);
    vector<int> mn = a;

    while (true) {
        bool chng = false;

        for (int i = n - 1; i > 0; i--) {
            if (!vis[i] && a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
                vis[i] = true;
                chng = true;
            }
        }

        if (!chng) break;
        mn = min(mn, a);
    }

    for (int &i : mn) cout << i << " ";
    cout << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    cin >> test_cases;

    while (test_cases--) {
        solve( );
    }

    return 0;
}
