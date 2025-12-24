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

// Global variable for Mo's block size, accessed by compareQueries
int blockSize;
struct Query {
        int l, r, idx;
};
bool compareQueries(Query &a, Query &b) {
        int blockA = a.l / blockSize;
        int blockB = b.l / blockSize;
        if (blockA != blockB) return blockA < blockB;
        if (blockA % 2 == 1) return a.r > b.r;
        return a.r < b.r;
}

void solve( ) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n);
        for (int &i : a) cin >> i;

        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) pref[i + 1] = pref[i] ^ a[i];
        unordered_map<int, int> freq;

        int currRes = 0;
        auto add = [&](int idx) -> void {
                // Implementation of add function
                // P[idx] acts as P[j]. We check for P[i-1] = P[j] ^ K
                currRes += freq[pref[idx] ^ k];
                freq[pref[idx]]++;
        };
        auto remove = [&](int idx) -> void {
                // Implementation of remove function
                freq[pref[idx]]--;
                currRes -= freq[pref[idx] ^ k];
        };

        blockSize = (int)sqrt(n);
        vector<int> res(m);

        vector<Query> lr(m);
        for (int i = 0; i < m; i++) {
                cin >> lr[i].l >> lr[i].r;
                lr[i].l--;
                lr[i].idx = i;
        }
        sort(lr.begin( ), lr.end( ), compareQueries);

        int currL = 0, currR = -1;
        for (auto &q : lr) {
                int L = q.l, R = q.r;
                while (currR < R) add(++currR);
                while (currR > R) remove(currR--);
                while (currL < L) remove(currL++);
                while (currL > L) add(--currL);
                res[q.idx] = currRes;
        }

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
