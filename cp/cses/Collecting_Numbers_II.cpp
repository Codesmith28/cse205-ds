#include <bits/stdc++.h>
#include <set>
#include <utility>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i] - 1] = i;
    }

    int rounds = 1;
    for (int i = 1; i < n; i++) {
        if (b[i] < b[i - 1]) rounds++;
    }

    int x, y;
    set<pii> updated;

    while (m--) {
        cin >> x >> y;
        x--, y--;

        if (a[x] + 1 <= n) updated.insert({a[x], a[x] + 1});
        if (a[x] - 1 >= 1) updated.insert({a[x] - 1, a[x]});
        if (a[y] + 1 <= n) updated.insert({a[y], a[y] + 1});
        if (a[y] - 1 >= 1) updated.insert({a[y] - 1, a[y]});

        for (pii it : updated) {
            if (b[it.first - 1] > b[it.second - 1]) rounds--;
        }

        swap(a[x], a[y]);
        b[a[x] - 1] = x;
        b[a[y] - 1] = y;

        for (pii it : updated) {
            if (b[it.first - 1] > b[it.second - 1]) rounds++;
        }
        updated.clear();

        cout << rounds << endl;
    }
}

int32_t main() {
    int testCases = 1;
    // cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}