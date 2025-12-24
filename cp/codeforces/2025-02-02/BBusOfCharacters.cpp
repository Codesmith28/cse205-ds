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
    vector<pii> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i].first;
        w[i].second = i + 1;
    }
    string s;
    cin >> s;

    priority_queue<pii, vector<pii>, greater<>> avail(w.begin( ), w.end( ));
    priority_queue<pii, vector<pii>> used;

    vector<int> res;
    for (char c : s) {
        if (c == '1') {
            auto [weight, idx] = used.top( );
            used.pop( );
            res.push_back(idx);
        } else {
            auto [weight, idx] = avail.top( );
            avail.pop( );
            used.push({weight, idx});
            res.push_back(idx);
        }
    }

    for (int &i : res) cout << i << " ";
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
