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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &i : a) cin >> i;

        // OPERATION:
        // pick an idx
        // replace that number with the mex of the array
        // repeat till array sorted in inc order (0, 1, 2, ..., n)

        auto getMex = [&](vector<int> &a) -> int {
                int mex = 0;
                set<int> cp(a.begin( ), a.end( ));
                for (int i : cp) {
                        if (mex != i) break;
                        mex++;
                }
                return mex;
        };
        auto getUnfixed = [&](vector<int> &a) -> int {
                for (int i = 0; i < n; i++) {
                        if (a[i] != i) {
                                return i;
                        }
                }
                return -1;
        };

        vector<int> ops;

        int unfixed = getUnfixed(a);
        while (unfixed != -1) {
                int currMex = getMex(a);
                int opIdx = -1;

                if (currMex < n) {
                        opIdx = currMex;
                } else { // currMex == n
                        opIdx = unfixed;
                }

                a[opIdx] = currMex;
                ops.push_back(opIdx + 1);
                unfixed = getUnfixed(a);
        }

        dbg(a);

        cout << ops.size( ) << endl;
        for (int &i : ops) cout << i << " ";
        cout << endl;
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