#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

struct task {
    int dead, dur;
};

void solve() {
    int n;
    cin >> n;
    vector<task> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i].dur >> t[i].dead;
    }

    sort(t.begin(), t.end(), [](struct task a, struct task b) {
        if (a.dur == b.dur) return a.dead > b.dead;
        return a.dur < b.dur;
    });

    int time = 0, res = 0;
    for (auto it : t) {
        time += it.dur;
        res += (it.dead - time);
    }

    // for (auto it : t) cout << it.dur << " " << it.dead << endl;
    cout << res << endl;
}

int32_t main() {
    int testCases = 1;
    // cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}
