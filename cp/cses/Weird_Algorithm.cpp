#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
    int n;
    cin >> n;

    auto solve = [&](int n, auto &&solve) -> void {
        cout << n << " ";
        if (n == 1) return;
        if (n % 2 == 0) solve(n / 2, solve);
        else solve(3 * n + 1, solve);
    };

    solve(n, solve);
}

int32_t main() {
    int testCases = 1;
    // cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}