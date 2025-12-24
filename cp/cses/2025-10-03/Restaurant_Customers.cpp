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
    map<int, int> time;
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        time[s]++;
        time[e]--;
    }
    int curr = 0, cap = 0;
    for (auto [k, v] : time) {
        curr += v;
        cap = max(cap, curr);
    }
    cout << cap << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    // cin >> test_cases;

    while (test_cases--) {
        solve( );
    }

    return 0;
}