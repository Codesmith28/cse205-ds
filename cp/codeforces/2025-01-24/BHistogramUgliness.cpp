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

void solve( ) {
    int n;
    cin >> n;

    vector<int> a(n + 2, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int res = 0;
    for (int i = 1; i <= n; i++) res += abs(a[i] - a[i - 1]);
    res += a[n];

    for (int i = 1; i <= n; i++) {
        int nei = max(a[i - 1], a[i + 1]);
        if (a[i] > nei) {
            int diff = a[i] - nei;
            res -= diff;
            a[i] = nei;
        }
    }

    cout << res << endl;
}

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
