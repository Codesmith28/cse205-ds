#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

int maxManhat(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += abs(i - (n - i + 1));
    }
    return sum;
}

void solve() {
    int n, k;
    cin >> n >> k;

    if (k % 2 or k > maxManhat(n)) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    vector<int> a(n);
    iota(begin(a), end(a), 1);

    if (k == 0) {
        for (auto &i : a)
            cout << i << " ";
        cout << endl;
        return;
    }

    if (k == maxManhat(n)) {
        reverse(begin(a), end(a));
        for (auto &i : a)
            cout << i << " ";
        cout << endl;
        return;
    }

    int st = 0, en = n - 1;
    while (k > 0) {
        if (k >= 2 * abs(a[en] - a[st])) {
            swap(a[st], a[en]);
            k -= 2 * abs(a[en] - a[st]);
            st++;
            en--;
        } else {
            st++;
        }
    }

    for (auto &i : a)
        cout << i << " ";
    cout << endl;
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