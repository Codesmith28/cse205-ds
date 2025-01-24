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

class DSU {
  public:
    vector<int> Parent, Rank;

    DSU(int n) {
        Parent.resize(n);
        Rank.resize(n, 0);
        for (int i = 0; i < n; i++) Parent[i] = i;
    }

    int Find(int x) {
        if (Parent[x] != x) Parent[x] = Find(Parent[x]);
        return Parent[x];
    }

    bool Union(int x, int y) {
        int xset = Find(x), yset = Find(y);
        if (xset != yset) {
            Rank[xset] < Rank[yset] ? Parent[xset] = yset : Parent[yset] = xset;
            Rank[xset] += Rank[xset] == Rank[yset];
            return true;
        }
        return false;
    }
};

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

// mst:
void kruskal(vector<vector<int>> &edges) {
    sort(edges.begin( ), edges.end( ));
    int n = edges.size( );
    int mst = 0, edge_count = 0;

    DSU dsu(n);
    for (int i = 0; i < n; i++) {
        if (dsu.Union(edges[i][1], edges[i][2])) {
            mst += edges[i][0];
            edge_count++;
        }
        if (edge_count == n - 1) break;
    }

    if (edge_count == n - 1) {
        cout << mst << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}

void solve( ) {
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
