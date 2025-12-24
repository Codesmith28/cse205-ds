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

const int N = 1e7 + 1;
vector<bool> isPrime(N, true);
vector<int> mnDiv(N, 0);

void sieve( ) {
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i < N; i++) {
                if (isPrime[i]) {
                        mnDiv[i] = i;
                        for (int j = i * i; j < N; j += i) {
                                isPrime[j] = false;
                                if (mnDiv[j] == 0) mnDiv[j] = i;
                        }
                }
        }
}

void solve( ) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &i : a) cin >> i;

        vector<pii> res(n);

        for (int i = 0; i < n; i++) {
                int x = a[i];
                vector<int> pfs;

                while (x > 1) {
                        int pf = mnDiv[x];
                        pfs.push_back(pf);
                        while (x % pf == 0) {
                                x /= pf;
                        }
                }

                if (pfs.size( ) < 2) {
                        res[i] = {-1, -1};
                } else {
                        int d1 = pfs[0];
                        int d2 = 1;
                        for (int j = 1; j < pfs.size( ); j++) {
                                d2 *= pfs[j];
                        }
                        res[i] = {d1, d2};
                }
        }

        for (pii a : res) cout << a.first << " ";
        cout << endl;
        for (pii a : res) cout << a.second << " ";
        cout << endl;
}

int32_t main( ) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        sieve( );
        int testCases = 1;
        // cin >> testCases;

        while (testCases--) {
                solve( );
        }

        return 0;
}
