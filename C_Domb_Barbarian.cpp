#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>

void solve() {
    string s;
    cin >> s;

    bool flag = false;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0') {
            s.erase(s.begin() + i);
            flag = true;
            break;
        }
    }

    if (!flag) {
        s.erase(s.begin());
    }

    cout << s << endl;
}

int32_t main() {
    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}