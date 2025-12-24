#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"
 
int findMx(vector<int> &a) {
    int n = a.size(), res = 0;
    // find the number of good subarrays good subarray: xor of all elements is odd and length of subarray is even

    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1) res++;
        pref[i + 1] = pref[i] ^ a[i];
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    cout << findMx(a) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}