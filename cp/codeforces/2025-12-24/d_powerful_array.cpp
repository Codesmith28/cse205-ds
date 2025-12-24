#include <algorithm>
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

// return SUM(x * fq[x] ^ 2) for all elements x in range [l, r]
void solve( ) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int &i : a) cin >> i;

        /*
         * Say current count of x = c
         *      - When we add -> count = c + 1
         *      => contribution change = (c + 1) ^ 2 - c ^ 2 = 2c + 1
         *      - When we remove -> count = c - 1
         *      => contribution change = (c - 1) ^ 2 - c ^ 2 = -2c + 1
         * */

        /// Mo's Algorithm
        struct Query {
                int l, r, idx;
        };
        vector<Query> queries;
        for (int i = 0; i < q; i++) {
                int l, r;
                cin >> l >> r;
                l--, r--;
                queries.push_back({l, r, i});
        }
        int blockSize = max(1LL, (int)sqrt(n));
        sort(queries.begin( ), queries.end( ), [&](const Query &a, const Query &b) {
                int blockL = a.l / blockSize;
                int blockR = b.l / blockSize;
                if (blockL != blockR) return blockL < blockR;
                if (blockL % 2 == 0) return a.r < b.r;
                return a.r > b.r;
        });

        // map<int, int> fq;
        // compression
        vector<int> vals = a;
        sort(vals.begin( ), vals.end( ));
        vals.erase(unique(vals.begin( ), vals.end( )), vals.end( ));
        int m = vals.size( );
        vector<int> comp(n);
        for (int i = 0; i < n; i++) {
                comp[i] = lower_bound(vals.begin( ), vals.end( ), a[i]) - vals.begin( );
        }

        int curr = 0;
        vector<int> fq(m, 0);
        auto add = [&](int pos) -> void {
                int id = comp[pos];
                int val = vals[id];
                int cnt = fq[id];
                curr += (2 * cnt + 1) * val;
                fq[id] = cnt + 1;
        };
        auto remove = [&](int pos) -> void {
                int id = comp[pos];
                int val = vals[id];
                int cnt = fq[id];
                curr += (-2 * cnt + 1) * val;
                fq[id] = cnt - 1;
        };

        int currL = 0, currR = -1;
        vector<int> res(q);
        for (auto &it : queries) {
                int L = it.l, R = it.r;
                while (currL > L) add(--currL);
                while (currR < R) add(++currR);
                while (currL < L) remove(currL++);
                while (currR > R) remove(currR--);
                res[it.idx] = curr;
        }

        for (int &i : res) cout << i << endl;
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
