#include <bits/stdc++.h>
#include <map>
#include <set>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
    int n, x;
    cin >> n >> x;
    map<int, int> idx;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (idx.find(x - a) != idx.end()) {
            cout << idx[x - a] + 1 << " " << i + 1 << endl;
            return;
        }
        idx[a] = i;
    }

    cout << "IMPOSSIBLE" << endl;
}

int32_t main() {
    int testCases = 1;
    // cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}
