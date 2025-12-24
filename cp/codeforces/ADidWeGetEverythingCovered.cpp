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
    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;

    set<char> st;
    string res;

    for (int i = 0; i < m; i++) {
        st.insert(s[i]);
        if (st.size( ) == k) {
            st.clear( );
            res += s[i];
        }
    }

    if (res.size( ) >= n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
        for (int i = 0; i < 26 && res.size( ) < n; i++) {
            if (st.find('a' + i) == st.end( )) {
                while (res.size( ) < n) res += 'a' + i;
            }
        }
        cout << res << endl;
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
