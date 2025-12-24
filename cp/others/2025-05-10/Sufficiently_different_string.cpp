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
    string s;
    cin >> s;
    int k;
    cin >> k;

    set<char> st(s.begin( ), s.end( ));
    int n = s.size( );
    string res = "";
    vector<bool> used(26, false);

    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (res.size( ) == n) break;
        bool found = st.count(ch);
        if (found) {
            if (k) {
                res += ch;
                used[ch - 'a'] = true;
                k--;
            }
        } else {
            res += ch;
            used[ch - 'a'] = true;
        }
    }

    cout << ((res.size( ) == n) ? res : "NOPE") << endl;
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
