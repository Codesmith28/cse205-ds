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
    string s, t;
    cin >> s >> t;
    int n = s.size( );

    map<char, int> fs, ft;
    for (char c : s) fs[c]++;
    for (char c : s) ft[c]++;
    map<char, int> rem;

    for (auto [k, v] : fs) {
        int diff = fs[k] - ft[k];
        rem[k] = diff;
        if (diff < 0) {
            cout << "NO" << endl;
            return;
        }
    }

    vector<bool> pres(n, true);
    for (int i = 0; i < n; i++) {
        if (rem[s[i]] > 0) {
            rem[s[i]]--;
            pres[i] = false;
        }
    }

    string ns;
    for (int i = 0; i < n; i++)
        if (pres[i]) ns.push_back(s[i]);

    cout << (ns == t ? "YES" : "NO") << endl;
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
