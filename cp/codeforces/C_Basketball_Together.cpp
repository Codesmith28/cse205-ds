#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
    int n, d;
    cin >> n >> d;

    vector<int> a(n);
    for (int &i : a) cin >> i;
    sort(a.begin(), a.end(), greater<int>());

    int low = 0, high = n - 1, res = 0;
    int curr = a[low];

    while (low <= high) {
        int mx = a[low];
        if (curr <= d) {
            high--;
            curr += mx;
        } else {
            res++;
            low++;
            curr = a[low];
        }
    }

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