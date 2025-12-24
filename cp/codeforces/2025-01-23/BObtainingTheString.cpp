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
    string s, t;
    cin >> s >> t;

    vector<int> res;

    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            int rep = -1;
            for (int j = i + 1; j < n; j++) {
                if (s[j] == t[i]) {
                    rep = j;
                    break;
                }
            }
            if (rep == -1) {
                cout << -1 << endl;
                return;
            }
            for (int j = rep - 1; j >= i; j--) {
                swap(s[j], s[j + 1]);
                res.push_back(j + 1);
            }
        }
    }

    cout << res.size( ) << endl;
    for (auto it : res) cout << it << " ";
    cout << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    /*cin >> test_cases;*/

    while (test_cases--) {
        solve( );
    }

    return 0;
}
