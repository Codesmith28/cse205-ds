#include <bits/stdc++.h>
#include <iostream>
#include <queue>
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

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<pii>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    auto dj = [&](int src, vector<int> &spath) -> void {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, src});
        spath[src] = 0;

        while (!pq.empty()) {
            auto [curr_dis, curr_node] = pq.top();
            pq.pop();

            if (spath[curr_node] < curr_dis) continue;
            for (auto [nei, dis] : adj[curr_node]) {
                if (spath[nei] > curr_dis + dis) {
                    spath[nei] = curr_dis + dis;
                    pq.push({spath[nei], nei});
                }
            }
        }
    };

    vector<int> spath(n + 1, LLONG_MAX);
    dj(1, spath);

    for (int i = 1; i <= n; i++) {
        cout << spath[i] << " ";
    }
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