#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <string>
#include <unordered_map>
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
    // 11, 1111, 111111 -> multiples of 11
    // 111, 111111 -> multiples 111

    // chicken mcnuggent theorem:
    int largest = 11 * 111 - 11 - 111;

    if (n > largest) {
        cout << "YES" << endl;
    } else { // brute force
        while (n >= 111) {
            if (n % 11 == 0) {
                cout << "YES" << endl;
                return;
            }
            n -= 111;
        }
        if (n >= 0 && n % 11 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
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