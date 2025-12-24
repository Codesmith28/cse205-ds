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
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    stack<int> mex;

    // 0 0 -> 0
    // 0 1 -> 1
    // 1 0 -> 1
    // 1 1 -> 2

    // consecutive "01" or "10" -> 2

    for (int i = 0; i < n; i++) {
        int sum = s1[i] - '0' + s2[i] - '0';
        if (sum == 1) { // push 2
            mex.push(2);
        } else if (sum == 2) { // push 0
            if (!mex.empty( ) && mex.top( ) == 1) {
                mex.pop( );
                mex.push(2);
            } else {
                mex.push(0);
            }
        } else { // push 1
            if (!mex.empty( ) && mex.top( ) == 0) {
                mex.pop( );
                mex.push(2);
            } else {
                mex.push(1);
            }
        }
    }

    int sum = 0;
    while (!mex.empty( )) {
        sum += mex.top( );
        mex.pop( );
    }

    cout << sum << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    cin >> test_cases;

    while (test_cases--) {
        solve( );
    }

    return 0;
}