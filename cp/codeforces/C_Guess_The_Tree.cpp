#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
    int n;
    cin >> n;

    vector<pii> edges;

    for (int i = 2; i <= n; i++) {
        cout << "? " << 1 << " " << i << endl;
        cout.flush();
        int c;
        cin >> c;

        // ? 1 i
        int node = 1;
        while (node != c) {
            node = c;
            cout << "? " << node << " " << i << endl;
            cout.flush();
            cin >> c;
        }

        edges.push_back({node, i});
    }

    cout << "! ";
    for (auto edge : edges) {
        cout << edge.first << " " << edge.second << " ";
    }
    cout << endl;
}

int32_t main() {
    int testCases = 1;
    cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}