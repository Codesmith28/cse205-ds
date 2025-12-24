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

class DSU {
  private:
    vector<int> Parent, Rank, Size;

  public:
    DSU(int n) {
        Parent.resize(n + 1);
        Rank.resize(n + 1, 1);
        Size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) Parent[i] = i;
    }

    int Find(int x) {
        if (x != Parent[x]) Parent[x] = Find(Parent[x]);
        return Parent[x];
    }

    bool Union(int x, int y) {
        int xset = Find(x), yset = Find(y);
        if (xset != yset) {
            if (Rank[xset] < Rank[yset]) {
                Parent[xset] = yset;
                Size[yset] += Size[xset];
            } else {
                Parent[yset] = xset;
                Size[xset] += Size[yset];
                if (Rank[xset] == Rank[yset]) Rank[xset]++;
            }
            return true;
        }
        return false;
    }

    int getSize(int x) {
        return Size[Find(x)];
    }
};

void solve( ) {
    int n, m;
    cin >> n >> m;
    vector<set<int>> banned(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        banned[x].insert(y);
        banned[y].insert(x);
    }

    set<int> unvis;
    for (int i = 1; i <= n; i++) unvis.insert(i);

    DSU dsu(n);
    auto dfs = [&](auto &&go, int node) -> void {
        unvis.erase(node);
        vector<int> adj;
        for (auto it = unvis.begin( ); it != unvis.end( );) {
            int child = *it;
            if (banned[node].count(child)) {
                it++; // next node
            } else {
                dsu.Union(node, child);
                adj.push_back(child);
                it = unvis.erase(it); // move pointer forward
            }
        }
        for (auto it : adj) go(go, it);
    };

    // for all the nodes unvisited:
    for (int i = 1; i <= n; i++)
        if (unvis.count(i)) dfs(dfs, i);

    vector<int> compSize;
    vector<int> vis(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int root = dsu.Find(i);
        if (!vis[root]) {
            vis[root] = true;
            compSize.push_back(dsu.getSize(root));
        }
    }

    cout << compSize.size( ) << endl;
    sort(compSize.begin( ), compSize.end( ));
    for (int &i : compSize) cout << i << " ";
    cout << endl;
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