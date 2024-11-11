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

void solve( ) {
    int n, amo;
    cin >> n >> amo;
    vector<int> price(n), pages(n);
    for (int &i : price) cin >> i;
    for (int &i : pages) cin >> i;

    vector<int> memo(amo + 1);
    for (int idx = 0; idx < n; idx++) {
        int curr_price = price[idx];
        int curr_pages = pages[idx];
        for (int curr_expanse = amo; curr_expanse >= curr_price; curr_expanse--) {
            int take = memo[curr_expanse - curr_price] + curr_pages;
            int not_take = memo[curr_expanse];
            memo[curr_expanse] = max(take, not_take);
        }
    }

    cout << memo[amo] << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        solve( );
    }

    return 0;
}
