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
    int n, x;
    cin >> n >> x;

    int curr = 0, sum = 0;
    vector<int> res(n);

    for (int i = 0; i < n - 1; i++) {
        if (((sum | curr) & ~x) == 0) {
            res[i] = curr;
            sum |= curr;
            curr++;
        } else {
            res[i] = 0;
        }
    }

    if (((sum | curr) == x)) {
        res[n - 1] = curr;
    } else if (((sum | x) == x)) {
        res[n - 1] = x;
    } else {
        res[n - 1] = 0;
    }

    for (int a : res) cout << a << " ";
    cout << endl;
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