#include<bits/stdc++.h>
using namespace std;
#define int long long

/* (╯°□°)╯︵ ┻━┻ */

void solve() {
    string s;
    cin >> s;

    char h0 = s[0];
    char h1 = s[1];
    char m0 = s[3];
    char m1 = s[4];

    if (h0 == m1 and h1 == m0) {
        cout << 0 << endl;
        return;
    }
    else {
        int h = (h0 - '0') * 10 + (h1 - '0');
        int m = (m0 - '0') * 10 + (m1 - '0');

        int ans = 0;
        while (true) {
            m++;
            if (m == 60) {
                m = 0;
                h++;
                if (h == 24) {
                    h = 0;
                }
            }
            ans++;
            if (h / 10 == m % 10 and h % 10 == m / 10) {
                cout << ans << endl;
                return;
            }
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