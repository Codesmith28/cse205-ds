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
int mod = 1e9 + 7;

void solve( ) {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int &i : a) cin >> i;

    if (m == 1) {
        cout << 2 << endl;
        return;
    }

    sort(a.begin( ), a.end( ));
    vector<int> num_houses;
    for (int i = 0; i < m - 1; i++) num_houses.push_back(a[i + 1] - a[i] - 1);
    int fst_lst = (n - a.back( ) - 1) + a[0];
    num_houses.push_back(fst_lst);

    sort(num_houses.begin( ), num_houses.end( ), greater<int>( ));
    int saved = 0, cnt = 0;

    for (int i : num_houses) {
        int protect = i - 2 * cnt;
        if (protect > 0) {
            if (protect <= 2) {
                saved++;
                cnt++;
            } else {
                cnt += 2;
                saved += (protect - 1);
            }
        }
    }

    cout << n - saved << endl;
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
