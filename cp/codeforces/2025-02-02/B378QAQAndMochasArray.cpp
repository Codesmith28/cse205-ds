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
const int mod = 1e9 + 7;

void solve( ) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    sort(a.begin( ), a.end( ));

    vector<int> b;
    for (int i = 1; i < n; i++) {
        if (a[i] % a[0] != 0) {
            b.push_back(a[i]);
        }
    }

    if (b.empty( )) {
        cout << "Yes" << endl;
        return;
    }

    bool flag = 1;
    for (int i = 1; i < b.size( ); i++) {
        if (b[i] % b[0] != 0) {
            flag = 0;
            break;
        }
    }

    cout << (flag ? "Yes" : "No") << endl;
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
