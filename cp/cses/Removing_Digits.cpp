#include <algorithm>
#include <bits/stdc++.h>
#include <string>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int  long long
#define pii  pair<int, int>
#define endl "\n"

void solve() {
    int n;
    cin >> n;

    auto recur = [&](auto &&recur, int curr) -> int {
        if (curr == 0) return 0;
        string num = to_string(curr);
        char mx = *max_element(num.begin(), num.end());
        int mx_dig = mx - '0';
        int cnt = INT_MAX;
        if (curr - mx_dig >= 0) cnt = min(cnt, 1 + recur(recur, curr - mx_dig));
        return cnt;
    };

    cout << recur(recur, n) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}