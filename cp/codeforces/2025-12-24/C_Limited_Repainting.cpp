#include <bits/stdc++.h>
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

const int inf = 1e18;
const int ninf = -1 * inf;

void solve( ) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> pen(n);
    for (int &i : pen) cin >> i;

    auto check = [&](int penalty) -> bool {
        char last = 'R';
        int ops = 0;
        for (int i = 0; i < n; i++) {
            if (pen[i] > penalty) {
                if (s[i] == 'B' && last != 'B') ops++; // in range of prev
                last = s[i];
            }
        }
        return ops <= k;
    };

    int low = 0, high = *max_element(pen.begin( ), pen.end( )), res = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid)) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << res << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        solve( );
    }

    return 0;
}