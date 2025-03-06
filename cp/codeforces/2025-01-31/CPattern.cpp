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
    vector<string> v(n);
    for (auto &it : v) cin >> it;

    int m = v[0].length( );
    string res = "";

    for (int i = 0; i < m; i++) {
        set<char> st;
        for (int j = 0; j < n; j++) st.insert(v[j][i]);
        if (st.size( ) == 2 && st.count('?')) {
            char c = ' ';
            for (char x : st)
                if (x != '?') c = x;
            res += c;
        } else if (st.size( ) == 1) {
            if (st.count('?'))
                res += 'x';
            else
                res += *st.begin( );
        } else {
            res += '?';
        }
    }

    cout << res << endl;
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
