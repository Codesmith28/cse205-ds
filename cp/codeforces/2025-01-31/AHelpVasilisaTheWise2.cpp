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
    int r1, r2, c1, c2, d1, d2;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;

    for (int a = 1; a <= 9; a++) {
        for (int b = 1; b <= 9; b++) {
            for (int c = 1; c <= 9; c++) {
                for (int d = 1; d <= 9; d++) {
                    set<int> st = {a, b, c, d};

                    bool b1 = (a + b == r1);
                    bool b2 = (c + d == r2);
                    bool b3 = (a + c == c1);
                    bool b4 = (b + d == c2);
                    bool b5 = (a + d == d1);
                    bool b6 = (b + c == d2);

                    if (st.size( ) == 4 && b1 && b2 && b3 && b4 && b5 && b6) {
                        cout << a << " " << b << endl;
                        cout << c << " " << d << endl;
                        return;
                    }
                }
            }
        }
    }

    cout << -1 << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    /*cin >> test_cases;*/

    while (test_cases--) {
        solve( );
    }

    return 0;
}
