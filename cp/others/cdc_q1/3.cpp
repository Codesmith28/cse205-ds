#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

vector<long> fairTime(vector<long> a, int m) {
#define int long
    long n = a.size( );
    sort(a.begin( ), a.end( ));

    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];

    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        if (i >= m)
            res[i] = res[i - m] + pref[i + 1];
        else
            res[i] = pref[i + 1];
    }

    return res;
}
#undef int

int main( ) {
    int n;
    cin >> n;
    vector<long> arr(n);
    for (long &x : arr) cin >> x;
    int m;
    cin >> m;

    vector<long> result = fairTime(arr, m);
    for (long x : result) cout << x << " ";
    cout << endl;
    return 0;
}
