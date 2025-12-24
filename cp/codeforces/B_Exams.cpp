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
    vector<pii> ab(n);
    for (int i = 0; i < n; i++) {
        cin >> ab[i].first;
        cin >> ab[i].second;
    }

    sort(ab.begin( ), ab.end( ), [](pii x, pii y) {
        return x.first < y.first;
    });

    dbg(ab);

    vector<int> due, due_temp;
    for (auto it : ab) due.push_back(it.second);

    dbg(due);

    due_temp = due;
    sort(due_temp.begin( ), due_temp.end( ));

    dbg(due_temp);

    if (due_temp == due) {
        cout << ab[n - 1].second << endl;
    } else {
        cout << ab[n - 1].first << endl;
    }
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    // cin >> test_cases;

    while (test_cases--) {
        solve( );
    }

    return 0;
}