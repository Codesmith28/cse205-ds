#include <bits/stdc++.h>
#include <cmath>
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
    string s;
    cin >> s;

    int side = sqrt(n);
    if (side * side != n) {
        cout << "No" << endl;
        return;
    }

    bool isBeautiful = true;

    for (int i = 0; i < side; i++) {
        if (s[i] != '1' || s[n - 1 - i] != '1') {
            isBeautiful = false;
            break;
        }
    }

    for (int i = 1; i < side - 1 && isBeautiful; i++) {
        if (s[i * side] != '1' || s[(i + 1) * side - 1] != '1') {
            isBeautiful = false;
            break;
        }
        for (int j = 1; j < side - 1; j++) {
            if (s[i * side + j] != '0') {
                isBeautiful = false;
                break;
            }
        }
    }

    cout << (isBeautiful ? "Yes" : "No") << endl;
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