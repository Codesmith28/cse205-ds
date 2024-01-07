#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>

int lcm(int a, int b) {
    return (a * b) / __gcd(a, b);
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 2, 1);
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }

    vector<int> b(n + 2, 1);

    // making b as per the given condition
    for (int i = 1; i <= n + 1; i++) {
        b[i] = lcm(a[i], a[i - 1]);
    }

    // cross check:
    for (int i = 1; i <= n; i++) {
        if (__gcd(b[i], b[i + 1]) != a[i]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int32_t main() {
    int testCases = 1;
    cin >> testCases;
    void solve();

    while (testCases--) {
        solve();
    }

    return 0;
}