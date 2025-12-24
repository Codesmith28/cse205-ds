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
    string s;
    cin >> s;

    for (int i = 1; i < n; i++) {
        if (s[i] == '_' && s[i - 1] == '(') s[i] = ')';
    }

    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == '_' && s[i + 1] == ')') s[i] = '(';
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '_') s[i] = '(';
    }

    stack<int> st;
    int gaps = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
            int x = st.top( );
            st.pop( );
            gaps += i - x;
        }
    }

    cout << gaps << endl;
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