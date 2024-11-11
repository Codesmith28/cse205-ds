#include <algorithm>
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

void solve() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());

    set<string> data;

    auto permute = [&](int idx, auto &&permute) -> void {
        if (idx == s.size()) {
            data.insert(s);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            swap(s[i], s[idx]);
            permute(idx + 1, permute);
            swap(s[i], s[idx]);
        }
    };

    /*
        string curr = s;
        data.push_back(s);
        next_permutation(s.begin(), s.end());

        while (curr != s) {
            data.push_back(s);
            next_permutation(s.begin(), s.end());
        }
    */

    permute(0, permute);
    cout << data.size() << endl;
    for (auto it : data) cout << it << endl;
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
