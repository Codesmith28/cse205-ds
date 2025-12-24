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

void solve( ) {
        int a, b, c;
        cin >> a >> b >> c;

        // +- 1 to any elements till they are > 0
        // min ops such that: a % b == 0 && b % c == 0

        int af, bf, cf;
        af = bf = cf = -1;
        int diff = inf;

        for (int i = 1; i <= 2 * a; i++) {             // possible a
                for (int j = i; j <= 2 * b; j += i) {  // possible b
                        for (int k = 0; k <= 1; k++) { // possible c
                                int currC = j * (c / j) + k * j;
                                int currDiff = abs(a - i) + abs(b - j) + abs(c - currC);
                                if (currDiff < diff) {
                                        diff = currDiff;
                                        af = i;
                                        bf = j;
                                        cf = currC;
                                }
                        }
                }
        }

        cout << diff << endl;
        cout << af << " " << bf << " " << cf << endl;
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
