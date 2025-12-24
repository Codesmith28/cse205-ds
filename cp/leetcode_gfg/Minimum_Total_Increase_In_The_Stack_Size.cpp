#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long

int solve(vector<int> &arr) {
    int n = arr.size( );
    int ans = 0;

    deque<int> dq{0};
    for (int i = n - 2; i > 0; i -= 2) {
        ans += max(0LL, max(arr[i - 1], arr[i + 1]) - arr[i] + 1);
        dq.push_front(ans);
    }

    if (n % 2 == 1) return ans;

    int pref = 0;
    for (int i = 1; i < n - 1; i += 2) {
        pref += max(0LL, max(arr[i - 1], arr[i + 1]) - arr[i] + 1);
        ans = min(ans, pref + dq[i / 2 + 1]);
    }

    return ans;
}

int32_t main( ) {
    vector<vector<int>> arrs = {
        {3, 2, 1, 2, 3},
        {3, 1, 4, 5, 5, 2}
    };
    for (auto it : arrs) cout << solve(it) << endl;
    return 0;
}
