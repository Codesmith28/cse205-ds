#include <bits/stdc++.h>
#include <iostream>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    int o = 0, z = 0;
    for (int &i : a) {
        cin >> i;
        if (i == 0)
            z++;
        else
            o++;
    }

    
}

int32_t main() {
    int testCases = 1;
    cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}