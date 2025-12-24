#include <bits/stdc++.h>
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

vector<int> maxStud(int n, int m, int q, vector<int> &a, vector<int> &strength, vector<vector<int>> &trans) {
    unordered_map<int, int> sch;
    vector<set<pii>> schools(m + 1);
    vector<int> res;

    for (int i = 0; i < n; i++) {
        sch[i + 1] = a[i];
        schools[a[i]].insert({strength[i], i + 1});
    }

    set<pii> mxes;
    for (auto it : schools) {
        if (it.size() > 0) mxes.insert({it.begin()->first, it.begin()->second});
    }

    for (int i = 0; i < q; i++) {
        int student = trans[i][0], dest = trans[i][1];
        int src = sch[student];

        int str = strength[student - 1];
        sch[student] = dest;
        schools[src].erase({str, student});
        schools[dest].insert({str, student});

        if (mxes.find({schools[src].begin()->first, schools[src].begin()->second}) != mxes.end()) {
            mxes.erase({schools[src].begin()->first, schools[src].begin()->second});
        }
        mxes.insert({schools[dest].begin()->first, schools[dest].begin()->second});

        res.push_back(mxes.rbegin()->first);

        // int mx = 0;
        // for (auto it : schools) {
        //     if (it.size() > 0) mx = max(mx, it.begin()->first);
        // }
        // res.push_back(mx);
    }

    return res;
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n), strength(n);
    vector<vector<int>> trans(q, vector<int>(2, 0));

    for (int &i : a) cin >> i;
    for (int &i : strength) cin >> i;
    for (int i = 0; i < q; i++) cin >> trans[i][0] >> trans[i][1];

    vector<int> ans = maxStud(n, m, q, a, strength, trans);
    for (int i : ans) cout << i << " ";
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
