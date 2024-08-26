#include <bits/stdc++.h>
#include <functional>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    int sum = 0;     // sum of coins the other twin gets
    int currSum = 0; // sum of coins I get

    for (int &i : a) {
        cin >> i;
        sum += i;
    }

    sort(begin(a), end(a), greater<int>());

    int i = 0;
    while (currSum <= sum) {
        currSum += a[i];
        sum -= a[i];
        i++;
    }

    cout << i << endl;
}

int32_t main() {
    int testCases = 1;
    // cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}