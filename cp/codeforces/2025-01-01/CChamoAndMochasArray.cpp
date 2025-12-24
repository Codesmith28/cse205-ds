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
    int ans = min(a[0], a[1]);

    if (n == 2) {
        cout << ans << endl;
    } else {
        for (int i = 0; i < n - 2; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; j++) temp.push_back(a[i + j]);
            sort(temp.begin( ), temp.end( ));
            ans = max(ans, temp[1]);
        }
        cout << ans << endl;
    }
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
