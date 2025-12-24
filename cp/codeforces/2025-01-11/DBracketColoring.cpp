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
    string s;
    cin >> s;

    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + (s[i - 1] == '(' ? 1 : -1);

    if (pref.back( ) != 0) {
        cout << -1 << endl;
        return;
    }

    int mn = *min_element(pref.begin( ), pref.end( ));
    int mx = *max_element(pref.begin( ), pref.end( ));

    if (mn == 0 || mx == 0) {
        cout << 1 << endl;
        for (int i = 0; i < n; i++) cout << 1 << " ";
        cout << endl;
        return;
    }

    vector<int> res;
    for (int i = 0; i < n; i++) {
        int c = (s[i] == '(' ? 1 : 2);
        res.push_back(c);
        while (i < n && pref[i + 1] != 0) {
            i++;
            res.push_back(c);
        }
    }

    cout << 2 << endl;
    for (int &i : res) cout << i << " ";
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
