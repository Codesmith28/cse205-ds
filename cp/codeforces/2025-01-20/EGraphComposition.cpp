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

void solve( ) {
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    vector<set<int>> adj1(n);
    vector<vector<int>> adj2(n);
    DSU dsu1(n), dsu2(n);

    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj1[u].insert(v);
        adj1[v].insert(u);
    }

    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
        dsu2.Union(u, v);
    }

    int rem = 0, add = 0;

    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (auto it : adj1[i]) {
            if (dsu2.Find(i) != dsu2.Find(it)) {
                rem++;
                temp.push_back(it);
            }
        }
        for (auto it : temp) adj1[i].erase(it);
    }

    rem /= 2;

    for (int i = 0; i < n; i++) {
        for (auto it : adj1[i]) {
            dsu1.Union(i, it);
        }
    }

    for (int i = 0; i < n; i++) {
        for (auto j : adj2[i]) {
            if (dsu1.Find(i) != dsu1.Find(j)) {
                dsu1.Union(i, j);
                add++;
            }
        }
    }

    cout << rem + add << endl;
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
