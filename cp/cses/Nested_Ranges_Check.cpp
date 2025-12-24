#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

struct range {
    int l, r, idx;
    bool operator<(const range &other) const {
        if (l == other.l) return r > other.r;
        return l < other.l;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<range> ranges(n);
    vector<bool> contains(n), contained(n);

    for (int i = 0; i < n; i++) {
        cin >> ranges[i].l >> ranges[i].r;
        ranges[i].idx = i;
    }

    sort(ranges.begin(), ranges.end()); // by default sorts using "<"

    int mxEnd = 0;
    for (int i = 0; i < n; i++) {
        if (ranges[i].r <= mxEnd) contained[ranges[i].idx] = true;
        mxEnd = max(mxEnd, ranges[i].r);
    }

    int mnEnd = LLONG_MAX;
    for (int i = n - 1; i >= 0; i--) {
        if (ranges[i].r >= mnEnd) contains[ranges[i].idx] = true;
        mnEnd = min(mnEnd, ranges[i].r);
    }

    for (bool i : contains) cout << i << " ";
    cout << endl;
    for (bool i : contained) cout << i << " ";
    cout << endl;
}

int32_t main() {
    int testCases = 1;
    // cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}
