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
#define tii  tuple<int, int, int>

const int inf = 1e18;

void solve( ) {
        int n;
        cin >> n;

        // min number of operations in any order to make 1 -> n
        // split => wt += pow(2, cnt) , cnt *= 2
        // nosplit => wt += cnt

        vector<int> pop;
        int currWt = 0;

        for (int i = 1; i + currWt <= n; i *= 2) {
                pop.push_back(i);
                currWt += i;
        }
        if (currWt < n) pop.push_back(n - currWt);

        sort(pop.begin( ), pop.end( ));

        cout << pop.size( ) - 1 << endl;
        for (int i = 1; i < pop.size( ); i++) cout << pop[i] - pop[i - 1] << " ";
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
