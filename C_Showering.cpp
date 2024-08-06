#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
    int n, s, m;
    cin >> n >> s >> m;

    vector<pii> tasks(n);
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].first >> tasks[i].second;
    }

    int last = 0;
    bool flag = false;

    if (tasks[0].first >= s) {
        flag = true;
    }

    for (int i = 0; i < n; i++) {
        if (tasks[i].first - last >= s) {
            flag = true;
        }
        last = tasks[i].second;
    }

    if (m - last >= s) {
        flag = true;
    }

    if (flag) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int32_t main() {
    int testCases = 1;
    cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}