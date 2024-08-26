#include <algorithm>
#include <bits/stdc++.h>
#include <string>
#include <utility>
#include <vector>
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
    int n, q;
    cin >> n >> q;

    vector<string> s;
    set<string> all;
    string p;
    map<string, vector<int>> idx;

    for (int i = 0; i < n; i++) {
        cin >> p;
        sort(begin(p), end(p));
        s.push_back(p);
        all.insert(p);
        idx[p].push_back(i);
    }

    int x, y;
    while (q--) {
        cin >> x >> y;
        x--, y--;
        if (x > y) swap(x, y);

        set<char> com;
        com.insert(s[x][0]);
        com.insert(s[x][1]);
        com.insert(s[y][0]);
        com.insert(s[y][1]);

        if (com.size() < 4) {
            cout << abs(x - y) << endl;
        } else if (all.size() <= 2) {
            cout << -1 << endl;
        } else {
            vector<string> bridge;
            string b = "";
            for (int i = 0; i <= 1; i++) {
                for (int j = 0; j <= 1; j++) {
                    b = "";
                    b += s[x][i];
                    b += s[y][j];
                    sort(begin(b), end(b));
                    bridge.push_back(b);
                }
            }

            int ans = INT_MAX;

            for (auto b : bridge) {
                if (idx.find(b) != idx.end()) {
                    auto it = upper_bound(begin(idx[b]), end(idx[b]), y);

                    if (it != end(idx[b])) {
                        ans = min(ans, abs(x - *it) + abs(y - *it));
                    }

                    if (it == begin(idx[b])) continue;
                    it--;

                    if (*it > x) {
                        ans = min(ans, abs(y - x));
                    } else {
                        ans = min(ans, abs(*it - x) + abs(*it - y));
                    }
                }
            }

            cout << ans << endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}