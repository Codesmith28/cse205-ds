#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>

void solve() {
    int n
        , k
        , l
        , c
        , d
        , p
        , nl
        , np;

    cin >> n
        >> k
        >> l
        >> c
        >> d
        >> p
        >> nl
        >> np;

    int el = (k * l) / nl;
    int sli = c * d;
    int sal = p / np;

    cout << min(el, min(sli, sal)) / n << endl;
}

int32_t main() {
    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}