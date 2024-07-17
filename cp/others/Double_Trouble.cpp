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

void solve() {
    int n;
    cin >> n;
    vector<int> x(n), p(n);
    for (int &i : x)
        cin >> i;
    for (int &i : p)
        cin >> i;

    int lidx = 0, ridx = n - 1;

    // case 1 - from each end:
    for (int i = 1; i < n; i++) {
        int dist = x[i] - x[i - 1];
        if (dist > p[i - 1])
            break;
        else
            lidx = i;
    }
    for (int i = n - 2; i >= 0; i--) {
        int dist = x[i + 1] - x[i];
        if (dist > p[i + 1])
            break;
        else
            ridx = i;
    }
    if (ridx - lidx <= 1) {
        cout << "YES\n";
        return;
    }

    // case 2 - from somewhere in middle:
    lidx = 0, ridx = n - 1;
    for (int i = 1; i < n; i++) {
        int dist = x[i] - x[i - 1];
        if (dist > p[i])
            break;
        else
            lidx = i;
    }
    for (int i = n - 2; i >= 0; i--) {
        int dist = x[i + 1] - x[i];
        if (dist > p[i])
            break;
        else
            ridx = i;
    }
    if (ridx - lidx <= 1) {
        cout << "YES\n";
        return;
    }

    // case 3&4 - both from left:
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        int dist = x[i + 1] - x[i];
        if (dist > p[i]) {
            cnt++;
        }
    }
    if (cnt <= 1) {
        cout << "YES\n";
        return;
    }

    // case 5&6 - both from right:
    cnt = 0;
    for (int i = n - 1; i > 0; i--) {
        int dist = x[i] - x[i - 1];
        if (dist > p[i - 1]) {
            cnt++;
        }
    }
    if (cnt <= 1) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
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