#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int& i : a) cin >> i;

    vector<int> b;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            b.push_back(i);
        }
    }

    sort(begin(b), end(b));

    // for (auto it : b) {
    //     cout << it << " ";
    // }cout << endl;

    if (b.size() == 0) {
        cout << 0 << endl;
    }
    else {
        // largest - smallest + 2
        cout << b.back() - b[0] + 2 << endl;
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