#include <bits/stdc++.h>
#include <unistd.h>
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

// permutation of size = n
// say cycles in the perm: {c1, c2, ..., ck}
// then sum(ci) = n
// swap required to fix cycle of size k = k - 1
// fixing => sorting the perm using swaps only
// then swaps for all the cycles:
// (c1 - 1) + (c2 - 1) + ... + (ck - 1)
// (c1 + c2 + ... + ck) - (1 + 1 + ... + 1)
// n - k
// MAX(n - k) = n - 1 => 1 cycle

// if same element -> multiple occur => each element in some diff cycle

void solve( ) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &i : nums) cin >> i;

    int mxfq = 0;
    map<int, int> fq;
    for (int &i : nums) {
        fq[i]++;
        mxfq = max(mxfq, fq[i]);
    }

    vector<int> sarr = nums;
    sort(sarr.begin( ), sarr.end( ));
    vector<int> sarrRot = sarr; // sarr rotated by mxfq
    rotate(sarrRot.begin( ), sarrRot.begin( ) + mxfq, sarrRot.end( ));

    map<int, vector<int>> inPlace;
    for (int i = 0; i < n; i++) {
        inPlace[sarr[i]].push_back(sarrRot[i]);
    }

    // dbg(inPlace);

    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        int val = nums[i];
        res[i] = inPlace[val].back( );
        inPlace[val].pop_back( );
    }

    for (int &i : res) cout << i << " ";
    cout << endl;
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