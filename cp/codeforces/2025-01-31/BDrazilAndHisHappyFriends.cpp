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
    int n, m;
    cin >> n >> m;
    vector<bool> by(n), gr(m);
    int b;
    cin >> b;
    for (int i = 0; i < b; i++) {
        int x;
        cin >> x;
        by[x] = true;
    }
    int g;
    cin >> g;
    for (int i = 0; i < g; i++) {
        int x;
        cin >> x;
        gr[x] = true;
    }

    int days = n * m * (n + m);
    int i = 0, j = 0;
    while (days--) {
        if (by[i] == true || gr[j] == true) {
            by[i] = true;
            gr[j] = true;
        }
        i = (i + 1) % n;
        j = (j + 1) % m;
    }

    int s1 = accumulate(by.begin( ), by.end( ), 0LL);
    int s2 = accumulate(gr.begin( ), gr.end( ), 0LL);

    if (s1 == n && s2 == m) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
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
