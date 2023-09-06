#include<bits/stdc++.h>
using namespace std;
#define int long long

/* (╯°□°)╯︵ ┻━┻ */

bool recur(string s, int a, int b, int it, int sum) {

    // base case condition:
    if ((it == s.length())) {
        if (sum == 0) {
            return true;
        } else {
            return false;
        }
    }

    char c = s[it];
    bool c1, c2;

    if (c == '+') {
        c1 = recur(s, a, b, it + 1, sum + a);
        c2 = recur(s, a, b, it + 1, sum + b);
    } else if (c == '-') {
        c1 = recur(s, a, b, it + 1, sum - a);
        c2 = recur(s, a, b, it + 1, sum - b);
    }

    return (c1 or c2);
}

void solve() {
    int n, q;
    cin >> n;

    string s;
    cin >> s;
    cin >> q;

    while (q--) {
        int a, b;
        cin >> a >> b;

        bool flag = recur(s, a, b, 0, 0);

        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int32_t main() {
    int testCases = 1;
    // cin >> testCases;
    void solve();

    while (testCases--) {
        solve();
    }

    return 0;
}