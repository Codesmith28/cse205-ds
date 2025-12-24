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
        string s;
        int q;
        cin >> s >> q;

        int n = s.size( );
        const int mxsz = 1e5 + 1;
        vector<bitset<mxsz>> charBits(26);
        for (int i = 0; i < n; i++) charBits[s[i] - 'a'][i] = 1;

        auto updateChar = [&](int pos, char x) -> void {
                int old = s[pos] - 'a';
                int curr = x - 'a';
                charBits[old][pos] = 0;  // unset
                charBits[curr][pos] = 1; // set
                s[pos] = x;              // update str
        };

        auto countOccur = [&](int start, int end, const string &sub) -> int {
                int len = sub.size( );
                if (end - start + 1 < len) return 0;

                bitset<mxsz> mask;
                mask.set( );
                for (int i = 0; i < len; i++) mask &= (charBits[sub[i] - 'a'] >> i);
                // shift into the position of the starting char, this way we can get all valid starting points where
                // our substring starts in the string

                // bitset<mxsz> rangeMask;
                // for (int i = start; i <= end - len + 1; i++) rangeMask[i] = 1;
                // int count = (mask & rangeMask).count( ); // set bits = valid starting points of the sub

                int count = (mask >> start).count( ) - (mask >> (end - len + 2)).count( );
                return count;
        };

        while (q--) {
                int t;
                cin >> t;
                if (t == 1) {
                        int idx;
                        char c;
                        cin >> idx >> c;
                        updateChar(idx - 1, c);
                } else if (t == 2) {
                        int l, r;
                        string y;
                        cin >> l >> r >> y;
                        cout << countOccur(l - 1, r - 1, y) << endl;
                }
        }
}

int32_t main( ) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int test_cases = 1;
        // cin >> test_cases;

        while (test_cases--) {
                solve( );
        }

        return 0;
}
