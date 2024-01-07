#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>

void solve() {
    int    n, k;
    cin >> n >> k;

    // vector<int> a(n);
    // for (int& i : a) cin >> i;

    int x;


    string s;
    for (int i = 0; i < n; i++) {
        cin >> x;
        s += to_string(x);
    }

    // cout << s << endl;

    map<string, int> mp;

    for (int i = 0; i < n; i += k) {
        mp[s.substr(i, k)]++;
    }

    string base = (*mp.begin()).first;
    int fq = (*mp.begin()).second;
    //get the one with maximum fq:
    for (auto it : mp) {
        if (it.second > fq) {
            base = it.first;
        }
    }

    // cout << base << endl;


    // for (auto it : mp) {
    //     cout << it.first << " " << it.second << endl;
    // }

    // a.erase(a.begin(), a.begin() + k);


    int ans = 0;

    while (s.length() != 0) {
        for (int i = 0; i < k; i++) {
            if (base[i] != s[i]) {
                ans++;
            }
        }
        s.erase(s.begin(), s.begin() + k);
    }

    int m = 0, y = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] != '1') {
            m++;
        }
        else {
            y++;
        }
    }

    cout << min({ ans, m, y }) << endl;
}

int32_t main() {
    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}