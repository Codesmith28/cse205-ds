#include <bits/stdc++.h>
#include <unordered_map>
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

void solve() {
    string s;
    cin >> s;

    int n = s.size(), dis = 0, l = 0;
    unordered_map<char, int> fq;
    int mn = INT_MAX;

    for (int r = 0; r < n; r++) {
        fq[s[r]]++;
        if (fq[s[r]] == 1) dis++;

        while (dis == 3) {
            mn = min(mn, r - l + 1);
            fq[s[l]]--;
            if (fq[s[l]] == 0) dis--;
            l++;
        }
    }

    cout << (mn == INT_MAX ? 0 : mn) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}