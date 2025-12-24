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

struct Query {
        int t, x, y;
};

void solve( ) {
        int q;
        cin >> q;

        vector<Query> query(q);
        for (int i = 0; i < q; ++i) {
                cin >> query[i].t;
                if (query[i].t == 1)
                        cin >> query[i].x;
                else
                        cin >> query[i].x >> query[i].y;
        }

        map<int, int> transform;
        vector<int> res;

        // Process backwards
        for (int i = q - 1; i >= 0; i--) {
                if (query[i].t == 1) {
                        int val = query[i].x;
                        if (transform.count(val)) { // transform if available
                                res.push_back(transform[val]);
                        } else {
                                res.push_back(val);
                        }
                } else {
                        // x -> y
                        int x = query[i].x;
                        int y = query[i].y;
                        if (transform.count(y)) {
                                transform[x] = transform[y];
                        } else {
                                transform[x] = y;
                        }
                }
        }

        reverse(res.begin( ), res.end( ));
        for (int &i : res) cout << i << " ";
        cout << endl;
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
