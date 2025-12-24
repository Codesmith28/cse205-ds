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
        int n;
        cin >> n;
        vector<pii> edges;
        for (int i = 0; i < n - 1; i++) {
                int a, b;
                cin >> a >> b;
                edges.emplace_back(a, b);
        }

        // output: a b x y => break {a, b} bulid {x, y}

        // make clusters
        // store redundaant edges where union = fasle
        // connect the roots of the clusters in place of them

        DSU dsu(n + 1);
        vector<pii> redund;
        set<int> roots;

        for (auto &[a, b] : edges) {
                if (!dsu.Union(a, b)) {
                        redund.emplace_back(a, b);
                }
        }
        for (int i = 1; i <= n; i++) {
                roots.insert(dsu.Find(i));
        }

        if (roots.size( ) <= 1) {
                cout << 0 << endl;
                return;
        }

        int mainRoot = *roots.begin( );
        roots.erase(roots.begin( ));

        vector<tuple<int, int, int, int>> res;
        for (int i = 0; i < redund.size( ); i++) {
                int a = redund[i].first;
                int b = redund[i].second;
                int nxtRoot = *roots.begin( );
                roots.erase(roots.begin( ));
                res.emplace_back(a, b, mainRoot, nxtRoot);
                dsu.Union(mainRoot, nxtRoot);
        }

        cout << res.size( ) << endl;
        for (auto &[a, b, x, y] : res) {
                cout << a << " " << b << " " << x << " " << y << endl;
        }
}

int32_t main( ) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int testCases = 1;
        // cin >> testCases;

        while (testCases--) {
                solve( );
        }

        return 0;
}
