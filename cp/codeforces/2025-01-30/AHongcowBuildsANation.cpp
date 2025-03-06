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
    vector<int> Parent, Rank, Size;

    DSU(int n) {
        Parent.resize(n);
        Rank.resize(n, 0);
        Size.resize(n, 1);
        for (int i = 0; i < n; i++) Parent[i] = i;
    }

    int Find(int x) {
        if (Parent[x] != x) Parent[x] = Find(Parent[x]);
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> c(k);
    for (int &i : c) {
        int x;
        cin >> x;
        i = x - 1;
    }
    DSU dsu(n);
    vector<pii> uv(m);
    for (pii &i : uv) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        i = {u, v};
        dsu.Union(u, v);
    }

    vector<int> cmpsz(n, 0);
    for (int i = 0; i < n; i++) cmpsz[dsu.Find(i)]++;

    auto nc2 = [&](int x) -> int {
        return x * (x - 1) / 2;
    };

    int ans = 0, left = n, mx = 0;
    for (int x : c) {
        int d = dsu.Find(x);
        mx = max(mx, cmpsz[d]);
        ans += nc2(cmpsz[d]); // connect all possible pairs
        left -= cmpsz[d];     // remove all existing nodes
    }

    ans -= nc2(mx);
    ans += nc2(mx + left);
    ans -= m;

    cout << ans << endl;
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
