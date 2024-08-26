#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), median(n), dp(n);
    for (int &i : a) cin >> i;

    auto check = [&](int med) {
        for (int i = 0; i < n; i++) {
            if (a[i] >= med)
                median[i] = 1;
            else
                median[i] = -1;
        }

        dp[0] = median[0];
        for (int i = 1; i < n; i++) {
            if (i % k == 0) {
                dp[i] = max(dp[i - k], median[i]);
            } else {
                dp[i] = dp[i - 1] + median[i];
                if (i > k) {
                    dp[i] = max(dp[i], dp[i - k]);
                }
            }
        }

        return dp[n - 1] > 0;
    };

    int low = 1, high = 1e9;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid)) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << high << endl;
}

int32_t main() {
    int testCases = 1;
    cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}