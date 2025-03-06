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
const int ninf = -1 * inf;
int mod = 1e9 + 7;

void solve( ) {
    string s;
    cin >> s;
    s = 'R' + s;
    s = s + 'R';

    vector<int> gaps;
    int n = s.size( );
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            int j = i + 1;
            while (j < s.size( ) && s[j] != 'R') j++;
            gaps.push_back(j - i);
            i = j - 1;
        }
    }

    cout << *max_element(gaps.begin( ), gaps.end( )) << endl;
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
