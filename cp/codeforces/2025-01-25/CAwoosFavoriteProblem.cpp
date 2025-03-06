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

    map<int, int> fq1, fq2;
    for (char c : s) fq1[c]++;
    for (char c : t) fq2[c]++;

    if (fq1 != fq2) {
        cout << "NO" << endl;
        return;
    }

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'b') continue;
        while (t[j] == 'b') j++;
        bool c1 = s[i] != t[j];
        bool c2 = s[i] == 'a' && i > j;
        bool c3 = s[i] == 'c' && i < j;
        if (c1 || c2 || c3) {
            cout << "NO" << endl;
            return;
        }
        j++;
    }

    cout << "YES" << endl;
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
