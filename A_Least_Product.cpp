#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int& i : a) cin >> i;

    int neg = 0;

    for (int& it : a) {
        if (it == 0) {
            cout << 0 << endl;
            return;
        } else if (it < 0) {
            neg++;
        }
    }

    if (neg % 2 == 0) {
        cout << 1 << endl;
        cout << 1 << " " << 0 << endl;
    } else {
        cout << 0;
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