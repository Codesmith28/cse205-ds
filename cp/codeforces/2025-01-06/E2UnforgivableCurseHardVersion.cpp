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
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;

    map<char, int> fq;
    bool flag = true;

    for (int i = 0; i < n; i++) {
        if (i >= k || i + k < n) {
            fq[s[i]]++;
            fq[t[i]]--;
        } else {
            flag = flag && (s[i] == t[i]);
        }
    }

    bool flag2 = true;
    for (auto &i : fq) {
        if (i.second != 0) {
            flag2 = false;
            break;
        }
    }

    cout << (flag && flag2 ? "YES" : "NO") << endl;
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
