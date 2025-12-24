#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> mp;
    vector<int> b;

    for (int i = 0; i < n; i++) {
        if (a[i] > k or a[i] == 0) {
            // mp[i] = 0;
        }
        else {
            // mp[i] = 1;
            b.push_back(abs(m - 1 - i));
        }
    }

    int x = *min_element(b.begin(), b.end());
    cout << x * 10 << endl;

}

int32_t main() {
    int testCases = 1;
    // cin >> testCases;    

    while (testCases--) {
        solve();
    }

    return 0;
}