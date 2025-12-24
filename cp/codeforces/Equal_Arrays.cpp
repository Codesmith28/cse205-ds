#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    int i = 1, j = 1;
    int sum1 = a[0], sum2 = b[0];
    int sz = 0;

    while (i <= a.size() and j <= b.size()) {
        // cout << "sum1: " << sum1 << " sum2: " << sum2 << endl;
        // cout << "i: " << i << " j: " << j << endl;
        if (sum1 == sum2) {
            sz++;
            if (i == a.size() and j == b.size()) {
                break;
            }
            sum1 = a[i];
            sum2 = b[j];
            i++;
            j++;
        } else if (sum1 > sum2) {
            sum2 += b[j];
            j++;
        } else {
            sum1 += a[i];
            i++;
        }
    }

    if (sum1 == sum2) {
        cout << sz << endl;
    } else {
        cout << -1 << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}