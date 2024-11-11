#include <bits/stdc++.h>
#include <set>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
    int x, n;
    cin >> x >> n;

    set<pii> ranges;
    multiset<int> lens;

    ranges.insert({0, x});
    lens.insert(x);

    vector<int> res;

    int p;
    for (int i = 0; i < n; i++) {
        cin >> p;
        auto low = ranges.lower_bound({p, 0});
        low--;

        int st = low->first, en = low->second;
        ranges.erase(low);
        lens.erase(lens.find(en - st));

        ranges.insert({st, p});
        ranges.insert({p, en});
        lens.insert(p - st);
        lens.insert(en - p);

        res.push_back(*lens.rbegin());
    }

    for (int &i : res) cout << i << " ";
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}